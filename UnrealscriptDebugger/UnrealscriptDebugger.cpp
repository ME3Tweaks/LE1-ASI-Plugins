#include <shlwapi.h>
#include <psapi.h>
#include <string>
#include <fstream>
#include <ostream>
#include <streambuf>
#include <sstream>
#include "../Interface.h"
#include "../Common.h"
#include "../SDK/LE1SDK/SdkHeaders.h"
#include "UnrealScriptDefinitions.h"
#pragma comment(lib, "shlwapi.lib")

#define SLHHOOK "UnrealscriptDebugger_"

//WIP. Generates VERY large logfiles if LE1 is left running for very long.

SPI_PLUGINSIDE_SUPPORT(L"UnrealscriptDebugger", L"SirCxyrtyx", L"0.1.0", SPI_GAME_LE1, SPI_VERSION_LATEST);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

struct OutParmInfo
{
	UProperty* Prop;
	byte* PropAddr;
	OutParmInfo* Next;
};

struct LE1FFrame 
{
	void* vtable;
	int unks[3];
	UStruct* Node;
	UObject* Object;
	byte* Code;
	byte* Locals;
	LE1FFrame* PreviousFrame;
	OutParmInfo* OutParms;
};

TCHAR logPath[MAX_PATH];
std::ofstream logFile;


// ======================================================================
// ProcessEvent hook
// ======================================================================

typedef void (*tProcessEvent)(UObject* Context, UFunction* Function, void* Parms, void* Result);
tProcessEvent ProcessEvent = nullptr;
tProcessEvent ProcessEvent_orig = nullptr;
void ProcessEvent_hook(UObject* Context, UFunction* Function, void* Parms, void* Result)
{
	logFile << "PE:    " << Function->GetFullName();
	if (Function->FunctionFlags & 0x00000400) //FUNC_Native
	{
		logFile << " [Native]";
	}
	logFile << "\n";
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
	logFile << "CF:    " << Function->GetFullName();
	if (Function->FunctionFlags & 0x00000400) //FUNC_Native
	{
		logFile << " [Native]";
	}
	logFile << "\n";
	CallFunction_orig(Context, Stack, Result, Function);
}


// ======================================================================
// ExecutionLoop detour
// ======================================================================
typedef void (*tNativeFunction) (UObject* Context, LE1FFrame* Stack, void* Result);
void* ExecutionLoop = nullptr;
void ExecutionLoop_hook(UObject* Context, LE1FFrame* Stack, void* Result, tNativeFunction* GNatives)
{
	auto node = Stack->Node;
	logFile << "Executing: " << node->GetFullPath() << "\nOn Object: " << Stack->Object->GetFullPath() << "\n";
	const auto beginOffset = Stack->Code;

	byte buff[64];
	while (*Stack->Code != (byte)OpCodes::Return) 
	{
		logFile << "    Statement at: " << std::hex << Stack->Code - beginOffset << "\n";
		int idx = *Stack->Code++;
		GNatives[idx](Context, Stack, buff);
	}
	logFile << "    Statement at: " << std::hex << Stack->Code - beginOffset << "\n";
	Stack->Code++; //skip Return opcode
	const int idx = *Stack->Code++;
	GNatives[idx](Context, Stack, Result); //execute statement that places return value in Result
}

bool PatchMemory(const void* patch, SIZE_T patchSize)
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

	byte patch[] = { 0x4c, 0x8d, 0x0d, 0x5c, 0xf2, 0x5a, 0x01, //LEA R9, [GNatives] //load the address of the native function array into the 4th argument register
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
	const byte originalExecutionLoopBytes[] = { 0x4c, 0x8d, 0x35, 0x5c, 0xf2, 0x5a, 0x01, 0x80, 0x38, 0x04, 0x74, 0x30, 0x0f, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x43, 0x24, 0x4c, 0x8d, 0x44, 0x24, 0x30, 0x48, 0x8b, 0xd3, 0x0f, 0xb6, 0x08, 0x48, 0xff, 0xc0, 0x48, 0x89, 0x43, 0x24, 0x8b, 0xc1, 0x48, 0x8b, 0x4b, 0x1c, 0x41, 0xff, 0x14, 0xc6, 0x48, 0x8b, 0x43, 0x24, 0x80, 0x38, 0x04, 0x75, 0xd7, 0x48, 0xff, 0xc0, 0x4c, 0x8b, 0xc5, 0x48, 0x89, 0x43, 0x24, 0x48, 0x8b, 0xd3, 0x0f, 0xb6, 0x08, 0x48, 0xff, 0xc0, 0x48, 0x89, 0x43, 0x24, 0x8b, 0xc1, 0x48, 0x8b, 0x4b, 0x1c, 0x41, 0xff, 0x14, 0xc6, 0x48, 0x8b, 0x43, 0x24, 0x4c, 0x8b, 0xb4, 0x24, 0x80, 0x00, 0x00, 0x00, 0x80, 0x38, 0x41, 0x75, 0x17, 0x48, 0x8b, 0x4b, 0x1c, 0x48, 0xff, 0xc0, 0x4c, 0x8b, 0xc5, 0x48, 0x89, 0x43, 0x24, 0x48, 0x8b, 0xd3, 0xff, 0x15, 0xe6, 0xf3, 0x5a, 0x01 };

	return PatchMemory(originalExecutionLoopBytes, sizeof(originalExecutionLoopBytes));
}

bool debbuggingFunction = false;

// ======================================================================
// ProcessInternal hook
// ======================================================================


typedef void (*tProcessInternal)(UObject* Context, LE1FFrame* Stack, void* Result);
tProcessInternal ProcessInternal = nullptr;
tProcessInternal ProcessInternal_orig = nullptr;
void ProcessInternal_hook(UObject* Context, LE1FFrame* Stack, void* Result)
{
	auto node = Stack->Node;
	bool removePatch = false;
	//logFile << "Executing: " << node->GetFullPath() << "\nOn Object: " << Stack->Object->GetFullPath() << "\n";

	if (!debbuggingFunction && !strcmp(node->Name.GetName(), "ClearSmoothing") && !strcmp(node->GetFullPath(), "Engine.PlayerInput.ClearSmoothing")) //hardcoding for development purposes. Will want to have a way for LEX to communicate the method to debug
	{
		debbuggingFunction = true;
		PatchExecutionLoop();
		removePatch = true;
	}

	ProcessInternal_orig(Context, Stack, Result);

	if (removePatch)
	{
		RestoreExecutionLoop();
	}
}


SPI_IMPLEMENT_ATTACH
{
	//Common::OpenConsole();

	logFile.open(logPath);
	
	auto _ = SDKInitializer::Instance();
	/*writeln(L"Attach - names at 0x%p, objects at 0x%p",
		SDKInitializer::Instance()->GetBioNamePools(),
		SDKInitializer::Instance()->GetObjects());*/

	if (auto rc = InterfacePtr->FindPattern((void**)&ProcessInternal, "40 53 55 56 57 48 81 EC 88 00 00 00 48 8B 05 B5 25 58 01");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find ProcessInternal pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}
	if (auto rc = InterfacePtr->InstallHook(SLHHOOK "ProcessInternal", ProcessInternal, ProcessInternal_hook, (void**)&ProcessInternal_orig);
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook ProcessInternal: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}

	if (auto rc = InterfacePtr->FindPattern((void**)&ExecutionLoop, "4c 8d 35 5c f2 5a 01 80 38 04 74 30 0f 1f 80 00 00 00 00");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find ExecutionLoop pattern: %d / %s", rc, SPIReturnToString(rc));
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
	logFile.close();
	return true;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID) {
	if (reason == DLL_PROCESS_ATTACH) 
	{
		GetModuleFileName(hModule, logPath, MAX_PATH);
		PathRemoveFileSpec(logPath);
		StrCat(logPath, L"\\UnrealscriptDebugger.log");
	}

	return TRUE;
}