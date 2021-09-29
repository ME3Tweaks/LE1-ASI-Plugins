#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#include <shlwapi.h>
#include <psapi.h>
#include <string>
#include <fstream>
#include <ostream>
#include <streambuf>
#include <sstream>

#include "ScriptDebugLogger.h"
#include "../Interface.h"
#include "../Common.h"
#include "../ME3TweaksHeader.h"
#include "UnrealScriptDefinitions.h"
#include "../ConsoleCommandParsing.h"
#pragma comment(lib, "shlwapi.lib")

#define SLHHOOK "UnrealscriptDebugger_"


SPI_PLUGINSIDE_SUPPORT(L"UnrealscriptDebugger", L"SirCxyrtyx", L"0.1.0", SPI_GAME_LE1, SPI_VERSION_LATEST);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

struct OutParmInfo
{
	UProperty* Prop;
	BYTE* PropAddr;
	OutParmInfo* Next;
};

struct LE1FFrame
{
	void* vtable;
	int unks[3];
	UStruct* Node;
	UObject* Object;
	BYTE* Code;
	BYTE* Locals;
	LE1FFrame* PreviousFrame;
	OutParmInfo* OutParms;
};

TCHAR logPath[MAX_PATH];
ScriptDebugLogger logger;

char debugFuncFullPath[128];
bool debugFunc = false;

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
		auto token = wcstok_s(cmd, seps, &context);

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
typedef void (*tCallFunction) (UObject* Context, LE1FFrame* Stack, void* Result, UFunction* Function);
tCallFunction CallFunction = nullptr;
tCallFunction CallFunction_orig = nullptr;
void CallFunction_hook(UObject* Context, LE1FFrame* Stack, void* Result, UFunction* Function)
{
	CallFunction_orig(Context, Stack, Result, Function);
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
	BYTE* propAddr;
	logger.IncreaseIndent();
	for (auto curChild = node->Children; curChild; curChild = curChild->Next)
	{
		if (!IsA<UProperty>(curChild))
		{
			continue;
		}
		auto prop = static_cast<UProperty*>(curChild);
		if (prop->PropertyFlags & 0x100) //OutParm flag
		{
			if (outParmInfo == nullptr)
			{
				continue;
			}
			propAddr = outParmInfo->PropAddr;
			outParmInfo = outParmInfo->Next;
		}
		else
		{
			propAddr = propsOffset + prop->Offset;
		}

		auto propClass = prop->Class;

		logger.indent() << prop->GetName();
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
			PRINTALLELEMENTS(unsigned, (value ? "True" : "False"))
		}
		else if (propClass == UNameProperty::StaticClass())
		{
			PRINTALLELEMENTS(FName, value.Instanced())
		}
		else if (propClass == UStrProperty::StaticClass())
		{
			PRINTALLELEMENTS(FString, value.Data)
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
			if (propClass == UStructProperty::StaticClass())
			{
				auto uStruct = static_cast<UStructProperty*>(prop)->Struct;
				logger.out() << " : ( StructType: " << uStruct->GetName() << ") [\n";
				PrintPropertyValues(propAddr, uStruct);
				for (int i = 0; i < array.Num(); ++i)
				{
					logger.indent() << ",\n";
					propAddr += prop->ElementSize;
					PrintPropertyValues(propAddr, uStruct);
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
						logger.out() << value.Data;
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
			auto value = *reinterpret_cast<UStructProperty*>(propAddr);
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

// ======================================================================
// ExecutionLoop detour
// ======================================================================
typedef void (*tNativeFunction) (UObject* Context, LE1FFrame* Stack, void* Result);
void* ExecutionLoop = nullptr;
void ExecutionLoop_hook(UObject* Context, LE1FFrame* Stack, void* Result, tNativeFunction* GNatives)
{
	auto node = Stack->Node;
	const bool isFunction = IsA<UFunction>(node);
	logger.indent() << "Executing" << (isFunction ? "Function" : "State Code") << ": " << node->GetFullPath() << "\n";
	logger.indent() << "On Object: " << Stack->Object->GetFullPath() << "\n";
	logger.IncreaseIndent();
	const auto beginOffset = Stack->Code;

	BYTE buff[64];
	while (*Stack->Code != (BYTE)OpCodes::Return)
	{
		if (isFunction) PrintPropertyValues(Stack->Locals, Stack->Node, Stack->OutParms);
		logger.indent() << "Statement at: 0x" << std::hex << Stack->Code - beginOffset << std::dec << "\n";
		const int idx = *Stack->Code++;
		GNatives[idx](Context, Stack, buff);
	}
	if (isFunction) PrintPropertyValues(Stack->Locals, Stack->Node, Stack->OutParms);
	logger.indent() << "Statement at: 0x" << std::hex << Stack->Code - beginOffset << std::dec << "\n";
	Stack->Code++; //skip Return opcode
	const int idx = *Stack->Code++;
	GNatives[idx](Context, Stack, Result); //execute statement that places return value in Result
	if (isFunction) PrintPropertyValues(Stack->Locals, Stack->Node, Stack->OutParms);
	logger.DecreaseIndent();
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

bool PatchExecutionLoop()
{

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

bool RestoreExecutionLoop()
{
	const BYTE originalExecutionLoopBytes[] = { 0x4c, 0x8d, 0x35, 0x5c, 0xf2, 0x5a, 0x01, 0x80, 0x38, 0x04, 0x74, 0x30, 0x0f, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x43, 0x24, 0x4c, 0x8d, 0x44, 0x24, 0x30, 0x48, 0x8b, 0xd3, 0x0f, 0xb6, 0x08, 0x48, 0xff, 0xc0, 0x48, 0x89, 0x43, 0x24, 0x8b, 0xc1, 0x48, 0x8b, 0x4b, 0x1c, 0x41, 0xff, 0x14, 0xc6, 0x48, 0x8b, 0x43, 0x24, 0x80, 0x38, 0x04, 0x75, 0xd7, 0x48, 0xff, 0xc0, 0x4c, 0x8b, 0xc5, 0x48, 0x89, 0x43, 0x24, 0x48, 0x8b, 0xd3, 0x0f, 0xb6, 0x08, 0x48, 0xff, 0xc0, 0x48, 0x89, 0x43, 0x24, 0x8b, 0xc1, 0x48, 0x8b, 0x4b, 0x1c, 0x41, 0xff, 0x14, 0xc6, 0x48, 0x8b, 0x43, 0x24, 0x4c, 0x8b, 0xb4, 0x24, 0x80, 0x00, 0x00, 0x00, 0x80, 0x38, 0x41, 0x75, 0x17, 0x48, 0x8b, 0x4b, 0x1c, 0x48, 0xff, 0xc0, 0x4c, 0x8b, 0xc5, 0x48, 0x89, 0x43, 0x24, 0x48, 0x8b, 0xd3, 0xff, 0x15, 0xe6, 0xf3, 0x5a, 0x01 };

	return PatchMemory(originalExecutionLoopBytes, sizeof(originalExecutionLoopBytes));
}


// ======================================================================
// ProcessInternal hook
// ======================================================================


typedef void (*tProcessInternal)(UObject* Context, LE1FFrame* Stack, void* Result);
tProcessInternal ProcessInternal = nullptr;
tProcessInternal ProcessInternal_orig = nullptr;
void ProcessInternal_hook(UObject* Context, LE1FFrame* Stack, void* Result)
{
	if (!debugFunc)
	{
		ProcessInternal_orig(Context, Stack, Result);
		return;
	}
	auto node = Stack->Node;
	bool removePatch = false;
	//logger << "Executing: " << node->GetFullPath() << "\nOn Object: " << Stack->Object->GetFullPath() << "\n";

	if (!_strcmpi(node->GetFullPath(), debugFuncFullPath))
	{
		debugFunc = false;
		PatchExecutionLoop();
		removePatch = true;
	}

	ProcessInternal_orig(Context, Stack, Result);

	if (removePatch)
	{
		RestoreExecutionLoop();
		logger.Close();
	}
}


SPI_IMPLEMENT_ATTACH
{
	//Common::OpenConsole();

	logger.Open(logPath);

	auto _ = SDKInitializer::Instance();
	/*writeln(L"Attach - names at 0x%p, objects at 0x%p",
		SDKInitializer::Instance()->GetBioNamePools(),
		SDKInitializer::Instance()->GetObjects());*/

	if (const auto rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&ProcessInternal), "40 53 55 56 57 48 81 EC 88 00 00 00 48 8B 05 B5 25 58 01");
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
	}

	if (const auto rc = InterfacePtr->FindPattern(&ExecutionLoop, "4c 8d 35 5c f2 5a 01 80 38 04 74 30 0f 1f 80 00 00 00 00");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find ExecutionLoop pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}

	if (const auto rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&ExecHandler), "48 8b c4 48 89 50 10 55 56 57 41 54 41 55 41 56 41 57 48 8d a8 d8 fe ff ff");
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
	}


	if (auto rc = InterfacePtr->FindPattern((void**)&CallFunction, "40 55 53 56 57 41 54 41 55 41 56 41 57 48 81 EC A8 04 00 00 48 8D 6C 24 20 48 C7 45 68 FE FF FF FF");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find CallFunction pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}
	if (auto rc = InterfacePtr->InstallHook(SLHHOOK "CallFunction", CallFunction, CallFunction_hook, (void**)&CallFunction_orig);
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook ProcessEvent: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}*/

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