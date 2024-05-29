#define GAMELE1
//#define GAMELE2
//#define GAMELE3


#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#include <shlwapi.h>
#include <psapi.h>
#include <string>
#include <fstream>
#include <ostream>
#include <streambuf>
#include <sstream>
#include <stack>

#include "BreakPointContainer.h"
#include "ScriptDebugLogger.h"
#include "../../Shared-ASI/Interface.h"
#include "../../Shared-ASI/Common.h"
#include "../../Shared-ASI/ME3Tweaks/ME3TweaksHeader.h"
#include "UnrealScriptDefinitions.h"
#include "../../Shared-ASI/ConsoleCommandParsing.h"
#pragma comment(lib, "shlwapi.lib")

#define SLHHOOK "UnrealscriptDebugger_"


SPI_PLUGINSIDE_SUPPORT(L"UnrealscriptDebugger", L"SirCxyrtyx", L"3.0.0", SPI_GAME_LE1, SPI_VERSION_LATEST);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

#if defined GAMELE1

#elif defined GAMELE2

#elif defined GAMELE3

#endif

struct DebuggerFrame
{
	UStruct* Node;
	UObject* Object;
	BYTE* CodeBaseAddr;
	BYTE* Locals;
	OutParmInfo* OutParms;
	DebuggerFrame* PreviousFrame;
	UFunction* NativeFunc;
	const char* NodePath;
	const wchar_t* FileName;
	USHORT FileNameLength;
	USHORT NodePathLength;
	USHORT CurrentPosition;
};


TCHAR logPath[MAX_PATH];
ScriptDebugLogger logger;

static ISharedProxyInterface* ProxyInterface;

BreakPointContainer BreakpointMap;
std::stack<DebuggerFrame*> DebuggerStack;
std::map<std::string, std::wstring> NodePathToFileNameMap;
#define currentStackDepth static_cast<int>(DebuggerStack.size())
bool pendingAttach = false;
bool pendingDetach = false;
bool isStepping = false;
int steppingMinStackDepth = 0;
bool resume = false;

char debugFuncFullPath[1024];
bool debugFunc = false;


struct LexMsg
{
	DebuggerFrame* currentFrame;
	FNameEntry** NamePool;
	ULONG64 msgLength;
	wchar_t msg[1024];
};

void SendMsgToLEX(const wstring& wstr, DebuggerFrame* stackFrame = nullptr) {
	if (const auto handle = FindWindow(nullptr, L"Legendary Explorer"))
	{
		constexpr unsigned long SENT_FROM_LE1_DEBUGGER = 0x02AC00D7;
		LexMsg msg;
		msg.msgLength = wstr.length();
		wcsncpy_s(msg.msg, wstr.c_str(), msg.msgLength + 1);
		msg.currentFrame = stackFrame;
		msg.NamePool = SDKInitializer::Instance()->GetBioNamePools();
		COPYDATASTRUCT cds;
		ZeroMemory(&cds, sizeof(COPYDATASTRUCT));
		cds.dwData = SENT_FROM_LE1_DEBUGGER;
		cds.cbData = sizeof(msg);
		cds.lpData = &msg;
		SendMessageTimeout(handle, WM_COPYDATA, NULL, reinterpret_cast<LPARAM>(&cds), 0, 10, nullptr);
	}
}

// ======================================================================
// ExecHandler hook
// ======================================================================

typedef unsigned (*tExecHandler)(UEngine* Context, wchar_t* cmd, void* unk);
tExecHandler ExecHandler = nullptr;
tExecHandler ExecHandler_orig = nullptr;
unsigned ExecHandler_hook(UEngine* Context, wchar_t* cmd, void* unk)
{
	if (ExecHandler_orig(Context, cmd, unk))
	{
		return TRUE;
	}
	if (IsCmd(&cmd, L"DEBUGSCRIPT"))
	{
		const auto seps = L" \t";
		wchar_t* context = nullptr;
		wchar_t* const token = wcstok_s(cmd, seps, &context);

		if (token == nullptr)
		{
			return FALSE;
		}
		strcpy_s(debugFuncFullPath, wchar2string(token).c_str());
		debugFunc = true;
		PathRemoveFileSpec(logPath);
		StrCat(logPath, L"\\");
		StrCat(logPath, token);
		StrCat(logPath, L".log");

		logger.Open(logPath);

		//todo: additional params to restrict it to when executing on a specific object? log multiple calls?
	}

	return FALSE;
}

// ======================================================================
// ProcessEvent hook
// ======================================================================

typedef void (*tProcessEvent)(UObject* Context, UFunction* Function, void* Parms, void* Result);
tProcessEvent ProcessEvent = nullptr;
tProcessEvent ProcessEvent_orig = nullptr;
void ProcessEvent_hook(UObject* Context, UFunction* Function, void* Parms, void* Result)
{
	ProcessEvent_orig(Context, Function, Parms, Result);
}

// ======================================================================
// CallFunction hook
// ======================================================================
typedef void (*tCallFunction) (UObject* Context, FFrame* Stack, void* Result, UFunction* Function);
tCallFunction CallFunction = nullptr;
tCallFunction CallFunction_orig = nullptr;
void CallFunction_hook(UObject* Context, FFrame* Stack, void* Result, UFunction* Function)
{
	constexpr int FUNC_NATIVE = 1024;
	bool needPop = false;
	if (Function->iNative || Function->FunctionFlags & FUNC_NATIVE)
	{
		//Native functions will not be executed by ProcessInternal, but should still be in the call stack
		const auto nodePathString = std::string(Function->GetFullPath());
		DebuggerFrame debugFrame;
		debugFrame.Node = Stack->Node;
		debugFrame.Object = Stack->Object;
		debugFrame.Locals = Stack->Locals;
		debugFrame.OutParms = Stack->OutParms;
		debugFrame.CodeBaseAddr = Stack->Code;
		debugFrame.CurrentPosition = 0;
		debugFrame.PreviousFrame = DebuggerStack.empty() ? nullptr : DebuggerStack.top();
		debugFrame.NativeFunc = Function;
		debugFrame.NodePath = nodePathString.c_str();
		debugFrame.NodePathLength = static_cast<USHORT>(nodePathString.length());
		if (const auto pair = NodePathToFileNameMap.find(nodePathString); pair != NodePathToFileNameMap.end())
		{
			debugFrame.FileName = pair->second.c_str();
			debugFrame.FileNameLength = static_cast<USHORT>(pair->second.length());
		}
		else
		{
			debugFrame.FileName = nullptr;
		}
		DebuggerStack.push(&debugFrame);
		needPop = true;
	}

	CallFunction_orig(Context, Stack, Result, Function);

	if (needPop)
	{
		DebuggerStack.pop();
	}
}

#define SCRIPTOBJECTFULLPATH(objPtr) (objPtr ? objPtr->GetFullPath() : "None")
#define PRINTALLELEMENTS(type, printStmnt) auto value = *reinterpret_cast<type*>(propAddr); \
											if (prop->ArrayDim > 1) \
											{ \
												logger.out() << "[" << prop->ArrayDim << "] : [" << printStmnt; \
												for (int i = prop->ArrayDim - 1; i > 0; --i) \
												{ \
													propAddr += prop->ElementSize; \
													value = *reinterpret_cast<type*>(propAddr); \
													logger.out() << ", " << printStmnt; \
												} \
												logger.out() << "]\n"; \
											} \
											else \
											{ \
												logger.out() << ": " << printStmnt << "\n"; \
											} \

void PrintPropertyValues(BYTE* propsOffset, UStruct* const node, OutParmInfo* outParmInfo = nullptr)
{
	BYTE* propAddr = nullptr;
	logger.IncreaseIndent();
	for (auto curChild = node->Children; curChild; curChild = curChild->Next)
	{
		if (!IsA<UProperty>(curChild))
		{
			continue;
		}

		auto prop = static_cast<UProperty*>(curChild);
		if (prop->PropertyFlags & 0x400) //ReturnValue flag
		{
			continue;
		}
		if (prop->PropertyFlags & 0x100) //OutParm flag
		{
			for (auto curOutParm = outParmInfo; curOutParm; curOutParm = curOutParm->Next)
			{
				if (curOutParm->Prop == prop)
				{
					propAddr = curOutParm->PropAddr;
					break;
				}
			}
		}
		else
		{
			propAddr = propsOffset + prop->Offset;
		}

		if (propAddr == nullptr)
		{
			continue;
		}

		auto propClass = prop->Class;

		auto propName = prop->GetName();
		logger.indent() << propName;
		if (propClass == UIntProperty::StaticClass())
		{
			PRINTALLELEMENTS(int, value)
		}
		else if (propClass == UFloatProperty::StaticClass())
		{
			PRINTALLELEMENTS(float, value)
		}
		else if (propClass == UByteProperty::StaticClass())
		{
			PRINTALLELEMENTS(BYTE, static_cast<int>(value))
		}
		else if (propClass == UBoolProperty::StaticClass())
		{
			auto boolProp = static_cast<UBoolProperty*>(prop);
			PRINTALLELEMENTS(unsigned, ((value & boolProp->BitMask) ? "True" : "False"))
		}
		else if (propClass == UNameProperty::StaticClass())
		{
			PRINTALLELEMENTS(FName, value.Instanced())
		}
		else if (propClass == UStrProperty::StaticClass())
		{
			PRINTALLELEMENTS(FString, "\"" << (value.Data ? value.Data : L"") << "\"")
		}
		else if (propClass == UStringRefProperty::StaticClass())
		{
			PRINTALLELEMENTS(int, "$" << value)
		}
		else if (propClass == UArrayProperty::StaticClass())
		{
			auto array = *reinterpret_cast<TArray<BYTE>*>(propAddr);
			auto array_property = static_cast<UArrayProperty*>(prop);
			prop = array_property->Inner;
			propClass = prop->Class;
			logger.indent() << ": " << array.Count << " Elements ";
			logger.out() << "[";
			propAddr = array.Data;
			if (propClass == UStructProperty::StaticClass())
			{
				auto uStruct = static_cast<UStructProperty*>(prop)->Struct;
				logger.out() << " : ( StructType: " << uStruct->GetName() << ") [\n";
				for (int i = 0; i < array.Num(); ++i)
				{
					if (i > 0)
					{
						logger.indent() << ",\n";
					}
					PrintPropertyValues(propAddr, uStruct);
					propAddr += prop->ElementSize;
				}
				logger.indent() << "]\n";
			}
			else
			{
				for (int i = 0; i < array.Num(); ++i)
				{
					if (i > 0)
					{
						logger.out() << ", ";
					}
					if (propClass == UIntProperty::StaticClass())
					{
						auto value = *reinterpret_cast<int*>(propAddr);
						logger.out() << value;
					}
					else if (propClass == UFloatProperty::StaticClass())
					{
						auto value = *reinterpret_cast<float*>(propAddr);
						logger.out() << value;
					}
					else if (propClass == UByteProperty::StaticClass())
					{
						auto value = *reinterpret_cast<BYTE*>(propAddr);
						logger.out() << static_cast<int>(value);
					}
					else if (propClass == UBoolProperty::StaticClass())
					{
						auto value = *reinterpret_cast<unsigned*>(propAddr);
						logger.out() << (value ? "True" : "False");
					}
					else if (propClass == UNameProperty::StaticClass())
					{
						auto value = *reinterpret_cast<FName*>(propAddr);
						logger.out() << value.Instanced();
					}
					else if (propClass == UStrProperty::StaticClass())
					{
						auto value = *reinterpret_cast<FString*>(propAddr);
						logger.out() << "\"" << (value.Data ? value.Data : L"") << "\"";
					}
					else if (propClass == UStringRefProperty::StaticClass())
					{
						auto value = *reinterpret_cast<int*>(propAddr);
						logger.out() << "$" << value;
					}
					else if (propClass == UDelegateProperty::StaticClass())
					{
						auto value = *reinterpret_cast<FScriptDelegate*>(propAddr);
						logger.out() << "(Function Name:" << value.FunctionName.Instanced() << ", Object: " << SCRIPTOBJECTFULLPATH(value.Object) << ")";
					}
					else if (propClass == UInterfaceProperty::StaticClass())
					{
						auto value = *reinterpret_cast<FScriptInterface*>(propAddr);
						logger.out() << SCRIPTOBJECTFULLPATH(value.Object);
					}
					else if (IsA<UObjectProperty>(prop))
					{
						auto value = *reinterpret_cast<UObject**>(propAddr);
						logger.out() << SCRIPTOBJECTFULLPATH(value);
					}
					propAddr += prop->ElementSize;
				}
				logger.out() << "]\n";
			}
		}
		else if (propClass == UDelegateProperty::StaticClass())
		{
			PRINTALLELEMENTS(FScriptDelegate, "(Function Name : " << value.FunctionName.Instanced() << ", Object : " << SCRIPTOBJECTFULLPATH(value.Object) << ")")
		}
		else if (propClass == UInterfaceProperty::StaticClass())
		{
			PRINTALLELEMENTS(FScriptInterface, SCRIPTOBJECTFULLPATH(value.Object))
		}
		else if (propClass == UStructProperty::StaticClass())
		{
			auto uStruct = static_cast<UStructProperty*>(prop)->Struct;
			auto value = reinterpret_cast<UStructProperty*>(propAddr);
			if (prop->ArrayDim > 1)
			{
				logger.out() << "[" << prop->ArrayDim << "] : ( StructType: " << uStruct->GetName() << ") [\n";
				PrintPropertyValues(propAddr, uStruct);
				for (int i = prop->ArrayDim - 1; i > 0; --i)
				{
					logger.indent() << ",\n";
					propAddr += prop->ElementSize;
					PrintPropertyValues(propAddr, uStruct);
				}
				logger.indent() << "]\n";
			}
			else
			{
				logger.out() << "( StructType: " << uStruct->GetName() << ")\n";
				PrintPropertyValues(propAddr, uStruct);
			}
		}
		else if (IsA<UObjectProperty>(prop))
		{
			PRINTALLELEMENTS(UObject*, SCRIPTOBJECTFULLPATH(value))
		}

	}
	logger.DecreaseIndent();
}

void breakState()
{
	isStepping = false;

	SendMsgToLEX(L"Break", DebuggerStack.top());
	MSG msg;
	while (true)
	{
		if (resume)
		{
			resume = false;
			break;
		}
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT || msg.message == WM_CLOSE)
			{
				msg.message = WM_QUIT;
				pendingDetach = true;
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	if (msg.message == WM_QUIT)
	{
		PostQuitMessage(static_cast<int>(msg.wParam));
	}
}

__forceinline bool ShouldBreak(const std::string& nodePathString, const unsigned short location)
{
	return isStepping && currentStackDepth <= steppingMinStackDepth || BreakpointMap.HasBreakPoint(nodePathString, location);
}

// ======================================================================
// ExecutionLoop detour
// ======================================================================
typedef void (*tNativeFunction) (UObject* Context, FFrame* Stack, void* Result);
void* ExecutionLoop = nullptr;
void ExecutionLoop_hook(UObject* Context, FFrame* Stack, void* Result, const tNativeFunction* GNatives)
{
	const auto node = Stack->Node;
	//const auto props_offset = Stack->Locals;
	//const auto out_parm_info = Stack->OutParms;
	//const bool isFunction = IsA<UFunction>(node);
	const auto nodePathString = std::string(node->GetFullPath());

	/*if (!pendingDetach)
	{
		logger.indent() << "Executing" << (isFunction ? "Function" : "State Code") << ": " << nodePathString.c_str() << "\n";
		logger.indent() << "On Object: " << Stack->Object->GetFullPath() << "\n";
		logger.IncreaseIndent();
	}*/
	BYTE* beginOffset = node->Script.Data;

	DebuggerFrame debugFrame;
	debugFrame.Node = node;
	debugFrame.Object = Stack->Object;
	debugFrame.Locals = Stack->Locals;
	debugFrame.OutParms = Stack->OutParms;
	debugFrame.CodeBaseAddr = beginOffset;
	debugFrame.CurrentPosition = 0;
	debugFrame.PreviousFrame = DebuggerStack.empty() ? nullptr : DebuggerStack.top();
	debugFrame.NativeFunc = nullptr;
	debugFrame.NodePath = nodePathString.c_str();
	debugFrame.NodePathLength = static_cast<USHORT>(nodePathString.length());
	if (const auto pair = NodePathToFileNameMap.find(nodePathString); pair != NodePathToFileNameMap.end())
	{
		debugFrame.FileName = pair->second.c_str();
		debugFrame.FileNameLength = static_cast<USHORT>(pair->second.length());
	}
	else
	{
		debugFrame.FileName = nullptr;
	}

	DebuggerStack.push(&debugFrame);

	BYTE buff[64];
	while (*Stack->Code != (BYTE)OpCodes::Return)
	{
		if (!pendingDetach)
		{
			//if (isFunction) PrintPropertyValues(props_offset, node, out_parm_info);
			//logger.indent() << "Statement at: 0x" << std::hex << Stack->Code - beginOffset << std::dec << "\n";
			const auto location = static_cast<USHORT>(Stack->Code - beginOffset);
			debugFrame.CurrentPosition = location;
			if (ShouldBreak(nodePathString, location))
			{
				breakState();
			}
		}
		const int idx = *Stack->Code++;
		GNatives[idx](Context, Stack, buff);
	}
	if (!pendingDetach)
	{
		//if (isFunction) PrintPropertyValues(props_offset, node, out_parm_info);
		//logger.indent() << "Statement at: 0x" << std::hex << Stack->Code - beginOffset << std::dec << "\n";
		const auto location = static_cast<USHORT>(Stack->Code - beginOffset);
		debugFrame.CurrentPosition = location;
		if (ShouldBreak(nodePathString, location))
		{
			breakState();
		}
	}
	Stack->Code++; //skip Return opcode
	const int idx = *Stack->Code++;
	GNatives[idx](Context, Stack, Result); //execute statement that places return value in Result
	/*if (!pendingDetach)
	{
		if (isFunction) PrintPropertyValues(props_offset, node, out_parm_info);
		logger.DecreaseIndent();
	}*/

	DebuggerStack.pop();
	if (steppingMinStackDepth < 1)
	{
		steppingMinStackDepth = 1;
	}
}

bool PatchMemory(const void* patch, const SIZE_T patchSize)
{
	//make the memory we're going to patch writeable
	DWORD  oldProtect;
	if (!VirtualProtect(ExecutionLoop, patchSize, PAGE_EXECUTE_READWRITE, &oldProtect))
		return false;

	//overwrite with our patch
	memcpy(ExecutionLoop, patch, patchSize);

	//restore the memory's old protection level
	VirtualProtect(ExecutionLoop, patchSize, oldProtect, &oldProtect);
	FlushInstructionCache(GetCurrentProcess(), ExecutionLoop, patchSize);
	return true;
}

bool AttachDebugger()
{
	//This won't work properly until LEBinkProxy has been updated
	//if (const auto rc = ProxyInterface->InstallHook(SLHHOOK "CallFunction", CallFunction, CallFunction_hook, (void**)&CallFunction_orig);
	//	rc != SPIReturn::Success)
	//{
	//	writeln(L"Attach - failed to hook CallFunction: %d / %s", rc, SPIReturnToString(rc));
	//	//return false;
	//}

	BYTE patch[] = { 0x4c, 0x8d, 0x0d, 0x5c, 0xf2, 0x5a, 0x01, //LEA R9, [GNatives] //load the address of the native function array into the 4th argument register
						   0x4C, 0x8B, 0xC5, //MOV R8, RBP //Move the Result pointer into the 3rd argument register
						   0x48, 0x8B, 0xD3, //MOV RDX, RBX //Move the FFrame pointer into the 2nd argument register
						   0x48, 0x89, 0xF9, //MOV RCX, RDI //Move the this pointer into the 1st argument register
						   0x49, 0xBE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //MOV R14, 0xFFFFFFFFFFFFFFFF //put address of ExecutionLoop_hook into R14 (actual address filled in at runtime) 
						   0x41, 0xFF, 0xD6,  //CALL R14 //Call ExecutionLoop_hook

						   //remaining bytes are NOPs of various sizes: https://stackoverflow.com/questions/43991155/what-does-nop-dword-ptr-raxrax-x64-assembly-instruction-do/50594130#50594130
						   0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00,
						   0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00,
						   0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00,
						   0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00,
						   0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00,
						   0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00,
						   0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00,
						   0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00,
						   0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00,
						   0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00,
						   0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00,
						   0x0F, 0x1F, 0x44, 0x00, 0x00 };

	//place the absolute address of ExecutionLoop_hook into the patch
	void* funcPtr = ExecutionLoop_hook;
	memcpy(patch + 18, &funcPtr, sizeof(funcPtr));

	return PatchMemory(patch, sizeof(patch));
}

bool DetachDebugger()
{
	//This won't work properly until LEBinkProxy has been updated
	//if (const auto rc = ProxyInterface->UninstallHook(SLHHOOK "CallFunction");
	//	rc != SPIReturn::Success)
	//{
	//	writeln(L"Detach - failed to unhook CallFunction: %d / %s", rc, SPIReturnToString(rc));
	//	//return false;
	//}

	const BYTE originalExecutionLoopBytes[] = { 0x4c, 0x8d, 0x35, 0x5c, 0xf2, 0x5a, 0x01, 0x80, 0x38, 0x04, 0x74, 0x30, 0x0f, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x43, 0x24, 0x4c, 0x8d, 0x44, 0x24, 0x30, 0x48, 0x8b, 0xd3, 0x0f, 0xb6, 0x08, 0x48, 0xff, 0xc0, 0x48, 0x89, 0x43, 0x24, 0x8b, 0xc1, 0x48, 0x8b, 0x4b, 0x1c, 0x41, 0xff, 0x14, 0xc6, 0x48, 0x8b, 0x43, 0x24, 0x80, 0x38, 0x04, 0x75, 0xd7, 0x48, 0xff, 0xc0, 0x4c, 0x8b, 0xc5, 0x48, 0x89, 0x43, 0x24, 0x48, 0x8b, 0xd3, 0x0f, 0xb6, 0x08, 0x48, 0xff, 0xc0, 0x48, 0x89, 0x43, 0x24, 0x8b, 0xc1, 0x48, 0x8b, 0x4b, 0x1c, 0x41, 0xff, 0x14, 0xc6, 0x48, 0x8b, 0x43, 0x24, 0x4c, 0x8b, 0xb4, 0x24, 0x80, 0x00, 0x00, 0x00, 0x80, 0x38, 0x41, 0x75, 0x17, 0x48, 0x8b, 0x4b, 0x1c, 0x48, 0xff, 0xc0, 0x4c, 0x8b, 0xc5, 0x48, 0x89, 0x43, 0x24, 0x48, 0x8b, 0xd3, 0xff, 0x15, 0xe6, 0xf3, 0x5a, 0x01 };

	return PatchMemory(originalExecutionLoopBytes, sizeof(originalExecutionLoopBytes));
}


// ======================================================================
// ProcessInternal hook
// ======================================================================

typedef void (*tProcessInternal)(UObject* Context, FFrame* Stack, void* Result);
tProcessInternal ProcessInternal = nullptr;
tProcessInternal ProcessInternal_orig = nullptr;
void ProcessInternal_hook(UObject* Context, FFrame* Stack, void* Result)
{
	if (!debugFunc)
	{
		ProcessInternal_orig(Context, Stack, Result);
		return;
	}
	const auto node = Stack->Node;
	bool removePatch = false;
	//logger << "Executing: " << node->GetFullPath() << "\nOn Object: " << Stack->Object->GetFullPath() << "\n";

	if (!_strcmpi(node->GetFullPath(), debugFuncFullPath))
	{
		debugFunc = false;
		AttachDebugger();
		removePatch = true;
	}

	ProcessInternal_orig(Context, Stack, Result);

	if (removePatch)
	{
		DetachDebugger();
		logger.Close();
	}
}


// ======================================================================
// GameEngineTick hook
// ======================================================================

typedef void (*tGameEngineTick)(UGameEngine* Context, FLOAT deltaSeconds);
tGameEngineTick GameEngineTick = nullptr;
tGameEngineTick GameEngineTick_orig = nullptr;
void GameEngineTick_hook(UGameEngine* Context, FLOAT deltaSeconds)
{
	if (pendingAttach)
	{
		pendingAttach = false;
		AttachDebugger();
		SendMsgToLEX(std::wstring(L"Attached"));
	}
	else if (pendingDetach)
	{
		pendingDetach = false;
		resume = false;
		BreakpointMap.ClearBreakPoints();
		DetachDebugger();
		SendMsgToLEX(std::wstring(L"Detached"));
	}
	GameEngineTick_orig(Context, deltaSeconds);
}


// ======================================================================
// SetLinker hook
// ======================================================================

typedef void (*tSetLinker)(UObject* Context, ULinkerLoad* Linker, int LinkerIndex);
tSetLinker SetLinker = nullptr;
tSetLinker SetLinker_orig = nullptr;
void SetLinker_hook(UObject* Context, ULinkerLoad* Linker, int LinkerIndex)
{
	if (Context->Linker && IsA<UFunction>(Context))
	{
		NodePathToFileNameMap.insert_or_assign(std::string(Context->GetFullPath()), std::wstring(Context->Linker->Filename.Data));
	}
	SetLinker_orig(Context, Linker, LinkerIndex);
}


template<typename T>
T Read(BYTE* ptr, const int offset)
{
	return *reinterpret_cast<T*>(ptr + offset);
}

enum PipeCommands
{
	CMD_AttachDebugger = 1,
	CMD_DetachDebugger = 2,
	CMD_BreakImmediate = 3,
	CMD_Breakpoint = 4,
		CMD_Add = 5,
		CMD_Remove = 6,
	CMD_StepInto = 7,
	CMD_StepOver = 8,
	CMD_StepOut = 9,
	CMD_Resume = 10
};

void ProcessCommand(BYTE* str, DWORD len)
{
	switch (str[0])
	{
	case CMD_AttachDebugger:
		pendingAttach = true;
		break;
	case CMD_DetachDebugger:
		pendingDetach = true;
		resume = true;
		break;
	case CMD_Breakpoint:
	{
		const auto op = Read<BYTE>(str, 1);
		const auto breakOffset = Read<USHORT>(str, 2);
		const auto functionPath = reinterpret_cast<char*>(str + 4);
		if (op == CMD_Add)
		{
			BreakpointMap.AddBreakPoint(functionPath, breakOffset);
		}
		else if (op == CMD_Remove)
		{
			BreakpointMap.RemoveBreakPoint(functionPath, breakOffset);
		}
		break;
	}
	case CMD_BreakImmediate:
		steppingMinStackDepth = INT_MAX;
		isStepping = true;
		break;

	/*
	 * BreakState commands (must only be issued if debugger is in the break state)
	 */

	case CMD_StepInto:
		steppingMinStackDepth = INT_MAX;
		isStepping = true;
		resume = true;
		break;
	case CMD_StepOver:
		steppingMinStackDepth = currentStackDepth;
		isStepping = true;
		resume = true;
		break;
	case CMD_StepOut:
		steppingMinStackDepth = currentStackDepth - 1;
		isStepping = true;
		resume = true;
		break;
	case CMD_Resume:
		resume = true;
		break;
	}
}


SPI_IMPLEMENT_ATTACH
{
	//Common::OpenConsole();

	logger.Open(logPath);

	INIT_CHECK_SDK()

	ProxyInterface = InterfacePtr;

	if (const auto rc = InterfacePtr->FindPattern(&ExecutionLoop, "4c 8d 35 5c f2 5a 01 80 38 04 74 30 0f 1f 80 00 00 00 00");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find ExecutionLoop pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}

	/*if (const auto rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&ProcessInternal), "40 53 55 56 57 48 81 EC 88 00 00 00 48 8B 05 B5 25 58 01");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find ProcessInternal pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}
	if (const auto rc = InterfacePtr->InstallHook(SLHHOOK "ProcessInternal", ProcessInternal, ProcessInternal_hook, reinterpret_cast<void**>(&ProcessInternal_orig));
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook ProcessInternal: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}*/

	if (const auto rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&GameEngineTick), "48 8b c4 55 53 56 57 41 54 41 56 41 57 48 8d a8 e8 fd ff ff");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find GameEngineTick pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}
	if (const auto rc = InterfacePtr->InstallHook(SLHHOOK "GameEngineTick", GameEngineTick, GameEngineTick_hook, reinterpret_cast<void**>(&GameEngineTick_orig));
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook GameEngineTick: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}

	/*if (const auto rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&ExecHandler), "48 8b c4 48 89 50 10 55 56 57 41 54 41 55 41 56 41 57 48 8d a8 d8 fe ff ff");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find ExecHandler pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}
	if (const auto rc = InterfacePtr->InstallHook(SLHHOOK "ExecHandler", ExecHandler, ExecHandler_hook, reinterpret_cast<void**>(&ExecHandler_orig));
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook ExecHandler: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}*/
	if (auto rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&CallFunction), "40 55 53 56 57 41 54 41 55 41 56 41 57 48 81 EC A8 04 00 00 48 8D 6C 24 20 48 C7 45 68 FE FF FF FF");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find CallFunction pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}

	/*if (auto rc = InterfacePtr->FindPattern((void**)&ProcessEvent, "40 55 41 56 41 57 48 81 EC 90 00 00 00 48 8D 6C 24 20");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find ProcessEvent pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}
	if (auto rc = InterfacePtr->InstallHook(SLHHOOK "ProcessEvent", ProcessEvent, ProcessEvent_hook, (void**)&ProcessEvent_orig);
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook ProcessEvent: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}*/



	if (const auto rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&SetLinker), "4c 8b 51 2c 4c 8b c9 4d 85 d2 74 39 48 85 d2 74 1c 48 8b c1");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find SetLinker pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}
	if (const auto rc = InterfacePtr->InstallHook(SLHHOOK "SetLinker", SetLinker, SetLinker_hook, reinterpret_cast<void**>(&SetLinker_orig));
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook SetLinker: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}

	//Good test function
	/*
	wchar_t* const token = L"SFXGame.BioSFHandler_Inventory.HandleEvent";
	strcpy_s(debugFuncFullPath, wchar2string(token).c_str());
	debugFunc = true;
	PathRemoveFileSpec(logPath);
	StrCat(logPath, L"\\");
	StrCat(logPath, token);
	StrCat(logPath, L".log");
	logger.Open(logPath);
	*/

	
	BYTE buffer[1024];
	DWORD numBytesRead;
	HANDLE hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\LEX_LE1_SCRIPTDEBUG_PIPE"),
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,   // FILE_FLAG_FIRST_PIPE_INSTANCE is not needed but forces CreateNamedPipe(..) to fail if the pipe already exists...
		1,
		1024 * 16,
		1024 * 16,
		NMPWAIT_USE_DEFAULT_WAIT,
	nullptr);

	while (hPipe != INVALID_HANDLE_VALUE)
	{
		if (ConnectNamedPipe(hPipe, nullptr) != FALSE)   // wait for someone to connect to the pipe
		{
			while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &numBytesRead, nullptr) != FALSE)
			{
				/* add terminating zero */
				buffer[numBytesRead] = '\0';
				ProcessCommand(buffer, numBytesRead);
			}
		}
		
		DisconnectNamedPipe(hPipe);
	}

	return true;
}

SPI_IMPLEMENT_DETACH
{
	//Common::CloseConsole();
	logger.Close();
	return true;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID) {
	if (reason == DLL_PROCESS_ATTACH)
	{
		GetModuleFileName(hModule, logPath, MAX_PATH);
	}

	return TRUE;
}