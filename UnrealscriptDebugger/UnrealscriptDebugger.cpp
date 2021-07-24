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
#pragma comment(lib, "shlwapi.lib");

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
// ProcessInternal hook
// ======================================================================


typedef void (*tProcessInternal)(UObject* Context, LE1FFrame* Stack, void* Result);
tProcessInternal ProcessInternal = nullptr;
tProcessInternal ProcessInternal_orig = nullptr;
void ProcessInternal_hook(UObject* Context, LE1FFrame* Stack, void* Result)
{
	auto node = Stack->Node;
	logFile << "Executing: " << node->GetFullPath() << "On Object: " << Stack->Object->GetFullPath() << "\n";
	ProcessInternal_orig(Context, Stack, Result);
}

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