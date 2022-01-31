#include <stdio.h>
#include <io.h>
#include <string>
#include <fstream>
#include "../LE1-SDK/Interface.h"
#include "../LE1-SDK/Common.h"
#include "../LE1-SDK/ME3TweaksHeader.h"
#define MYHOOK "DebugLogger_"

SPI_PLUGINSIDE_SUPPORT(L"DebugLogger", L"1.0.0", L"ME3Tweaks", SPI_GAME_LE1 | SPI_GAME_LE2 | SPI_GAME_LE3,
	SPI_VERSION_ANY);
SPI_PLUGINSIDE_PRELOAD;
SPI_PLUGINSIDE_SEQATTACH;

ME3TweaksASILogger logger("DebugLogger v1", "DebugLogger.txt");

// Original Func
typedef void (WINAPI* tOutputDebugStringW)(LPCWSTR lpcszString);
tOutputDebugStringW OutputDebugStringW_Orig = nullptr;

// Our replacement
void WINAPI OutputDebugStringW_Hook(LPCWSTR lpcszString)
{
	OutputDebugStringW_Orig(lpcszString);
	writeMsg(L"%s", lpcszString); // string already has a newline on the end
	logger.writeWideToLog(std::wstring_view{ lpcszString });
	logger.flush();
}

typedef UObject* (*tCreateImport)(ULinkerLoad* Context, int UIndex);
tCreateImport CreateImport = nullptr;
tCreateImport CreateImport_orig = nullptr;
UObject* CreateImport_hook(ULinkerLoad* Context, int i)
{
	UObject* object = CreateImport_orig(Context, i);
	if (object == nullptr)
	{
		FObjectImport importEntry = Context->ImportMap(i);
		writeln("Could not resolve #%d: %hs (%hs) in file: %s", -i - 1, importEntry.ObjectName.GetName(), importEntry.ClassName.GetName(), Context->Filename.Data);
		logger.writeWideLineToLog(wstring_format(L"Could not resolve #%d: %hs (%hs) in file: %s", -i - 1, importEntry.ObjectName.GetName(), importEntry.ClassName.GetName(), Context->Filename.Data));
		logger.flush();
	}
	return object;
}

// LOAD PACKAGE PERSISTENT
typedef UObject* (*tLoadPackagePersistent)(int64 param1, const wchar_t* param2, uint32 param3, int64* param4, uint32* param5);
tLoadPackagePersistent LoadPackagePersistent = nullptr;
tLoadPackagePersistent LoadPackagePersistent_orig = nullptr;
void LoadPackagePersistent_hook(int64 param1, const wchar_t* packageName, uint32 param3, int64* param4, uint32* param5)
{
	writeln("PERSISTENTPACKAGELOAD: %s", (void*)packageName, packageName);
	LoadPackagePersistent_orig(param1, packageName, param3, param4, param5);
	//std::this_thread::sleep_for(std::chrono::seconds(1000));

	/*UObject* object = CreateImport_orig(Context, i);
	if (object == nullptr)
	{
		FObjectImport importEntry = Context->ImportMap(i);
		writeln("Could not resolve #%d: %hs (%hs) in file: %s", -i - 1, importEntry.ObjectName.GetName(), importEntry.ClassName.GetName(), Context->Filename.Data);
		logger.writeWideLineToLog(wstring_format(L"Could not resolve #%d: %hs (%hs) in file: %s", -i - 1, importEntry.ObjectName.GetName(), importEntry.ClassName.GetName(), Context->Filename.Data));
		logger.flush();
	}*/
}

void logMessage(const wchar_t* logSource, wchar_t* formatStr, void* param1, void* param2)
{
	// Todo: Log to disk.
	fwprintf_s(stdout, L"%s: ", logSource);
	fwprintf_s(stdout, formatStr, param1, param2);
	fwprintf_s(stdout, L"\n");
}

// LOGF
typedef void (*tFOutputDeviceLogF)(void* outputDevice, wchar_t* formatStr, void* param1, void* param2);


tFOutputDeviceLogF LogF = nullptr;
tFOutputDeviceLogF LogF_orig = nullptr;
void LogF_hook(void* fOutputDevice, wchar_t* formatStr, void* param1, void* param2)
{
	logMessage(L"appLogf", formatStr, param1, param2);
}

typedef void (*tFOutputDeviceErrorLogF)(void* outputDevice, int* code, wchar_t* formatStr, void* param1);
tFOutputDeviceErrorLogF ErrorLogF = nullptr;
tFOutputDeviceErrorLogF ErrorLogF_orig = nullptr;
void ErrorLogF_hook(void* fOutputDevice, int* code, wchar_t* formatStr, void* param1)
{
	logMessage(L"appErrorLogf", formatStr, param1, param1);
}

//typedef void (*tFOutputDeviceLogF)(void* param1, wchar_t* param2, wchar_t* param3);
tFOutputDeviceLogF MsgF = nullptr;
tFOutputDeviceLogF MsgF_orig = nullptr;
void MsgF_hook(void* fOutputDevice, wchar_t* formatStr, wchar_t* param1)
{
	// Seems dangerous.
	logMessage(L"appMsgf", formatStr, param1, 0);
}

typedef void (*tMessageBoxF)(int messageBoxType, wchar_t* formatString, wchar_t* param3);
tMessageBoxF MsgFDialog = nullptr;
tMessageBoxF MsgFDialog_orig = nullptr;
void MsgFDialog_hook(int messageBoxType, wchar_t* formatStr, wchar_t* param1)
{
	MessageBoxW(NULL, formatStr, L"Game message", 0x0);
}


// HOOK LogInternal / WarnInternal
// ======================================================================
// ProcessInternal hook (for native .Activated())
// ======================================================================

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

typedef void (*tProcessInternal)(UObject* Context, LE1FFrame* Stack, void* Result);
tProcessInternal ProcessInternal = nullptr;
tProcessInternal ProcessInternal_orig = nullptr;
void ProcessInternal_hook(UObject* Context, LE1FFrame* Stack, void* Result)
{
	/*
	auto func = Stack->Node;
	if (func)
		writeln("%hs", func->GetName());
	auto obj = Stack->Object;
	if (func && !strcmp(func->GetName(), "LogInternal"))
	{
		const auto op = reinterpret_cast<UObject*>(Context);
		char* fullInstancedPath = op->GetFullPath();
		char* className = op->Class->Name.GetName();
		logger.writeToLog(string_format("%s %s\n", className, fullInstancedPath), true);
	}*/
	ProcessInternal_orig(Context, Stack, Result);
}

typedef void (*tCombineFromBuffer)(UObject* Context, wchar_t* filePath, FString* contents, int extra);
tCombineFromBuffer FConfigCombineFromBuffer = nullptr;
tCombineFromBuffer FConfigCombineFromBuffer_orig = nullptr;
void FConfigCombineFromBuffer_hook(UObject* Context, wchar_t* filePath, FString* contents, int extra)
{
	writeln("FConfig::CombineFromBuffer: %s", filePath);
	FConfigCombineFromBuffer_orig(Context, filePath, contents, extra);
}


// Configures the hooks for built-in logging functions that don't output anything.
void hookLoggingFunc(ISharedProxyInterface* InterfacePtr)
{
	// ============================================================
	// appLogF
	//=============================================================
	writeln(L"Initializing appLogf hook...");
	if (auto const rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&LogF), "48 8b c4 48 89 50 10 4c 89 40 18 4c 89 48 20 56 48 83 ec 50 83 79 08 00 48 8b f1 0f 85 bf 00 00 00");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find appLogf pattern: %d / %s", rc, SPIReturnToString(rc));
		//return false;
	}
	else if (auto const rc = InterfacePtr->InstallHook(MYHOOK "appLogf", LogF, LogF_hook, reinterpret_cast<void**>(&LogF_orig));
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook appLogf: %d / %s", rc, SPIReturnToString(rc));
		//return false;
	}
	else
	{
		writeln(L"Hooked appLogf");
	}

	// ============================================================
	// appLogF (FOutputDeviceError)
	// ============================================================
	writeln(L"Initializing errorAppLogf hook...");
	if (auto const rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&ErrorLogF), "4c 89 44 24 18 4c 89 4c 24 20 55 56 48 83 ec 58 83 79 08 00 48 8b ea 48 8b f1 0f 85 c3 00 00 00 83 3d 91 9d 57 01 00 0f 85 b6 00 00 00");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find errorAppLogf pattern: %d / %s", rc, SPIReturnToString(rc));
		//return false;
	}
	else if (auto const rc = InterfacePtr->InstallHook(MYHOOK "errorAppLogf", ErrorLogF, ErrorLogF_hook, reinterpret_cast<void**>(&ErrorLogF_orig));
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook errorAppLogf: %d / %s", rc, SPIReturnToString(rc));
		//return false;
	}
	else
	{
		writeln(L"Hooked errorAppLogf");
	}

	// ============================================================
	// appMsgf
	//=============================================================
	//writeln(L"Initializing appMsgf hook...");
	//if (auto const rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&MsgF), "48 89 54 24 10 4c 89 44 24 18 4c 89 4c 24 20 53 55 56 57 b8 58 80 00 00 e8 b3 f6 d7 00");
	//	rc != SPIReturn::Success)
	//{
	//	writeln(L"Attach - failed to find appMsgf pattern: %d / %s", rc, SPIReturnToString(rc));
	//	//return false;
	//}
	//else if (auto const rc = InterfacePtr->InstallHook(MYHOOK "appMsgf", MsgF, MsgF_hook, reinterpret_cast<void**>(&MsgF_orig));
	//	rc != SPIReturn::Success)
	//{
	//	writeln(L"Attach - failed to hook appMsgf: %d / %s", rc, SPIReturnToString(rc));
	//	//return false;
	//}
	//else
	//{
	//	writeln(L"Hooked appMsgf");
	//}

	// ==============================================================
	// appMsgf Dialog
	// ==============================================================

	writeln(L"Initializing appMsgfDialog hook...");
	if (auto const rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&MsgFDialog), "48 89 54 24 10 4c 89 44 24 18 4c 89 4c 24 20 55 53 56 57 41 54 41 55 41 56 41 57 48 8d ac 24 58 80 ff ff");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find appMsgfDialog pattern: %d / %s", rc, SPIReturnToString(rc));
		//return false;
	}
	else if (auto const rc = InterfacePtr->InstallHook(MYHOOK "appMsgfDialog", MsgFDialog, MsgFDialog_hook, reinterpret_cast<void**>(&MsgFDialog_orig));
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook appMsgfDialog: %d / %s", rc, SPIReturnToString(rc));
		//return false;
	}
	else
	{
		writeln(L"Hooked appMsgfDialog");
	}

	// ==============================================================
	// FConfig::CombineFromBuffer
	// ==============================================================
	writeln(L"Locating FConfig::CombineFromBuffer...");
	if (auto const rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&FConfigCombineFromBuffer), "40 55 56 57 41 54 41 55 41 56 41 57 48 8d ac 24 e0 fe ff ff 48 81 ec 20 02 00 00 48 c7 85 b8 00 00 00 fe ff ff ff");
		rc != SPIReturn::Success)
	{
		writeln(L"Failed to find FConfig::CombineFromBuffer pattern: %d / %s", rc, SPIReturnToString(rc));
		//return false;
	}
	else if (auto const rc = InterfacePtr->InstallHook(MYHOOK "FConfigCombineFromBuffer", FConfigCombineFromBuffer, FConfigCombineFromBuffer_hook, reinterpret_cast<void**>(&FConfigCombineFromBuffer_orig));
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook FConfigCombineFromBuffer: %d / %s", rc, SPIReturnToString(rc));
		//return false;
	}
	else
	{
		writeln(L"Hooked FConfigCombineFromBuffer");
	}

	// ==============================================================
	// FConfig::LoadIni
	// ==============================================================
	//writeln(L"Locating FConfig::LoadIni...");
	//if (auto const rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&FConfigCombineFromBuffer), "40 55 56 57 41 54 41 55 41 56 41 57 48 8d ac 24 e0 fe ff ff 48 81 ec 20 02 00 00 48 c7 85 b8 00 00 00 fe ff ff ff");
	//	rc != SPIReturn::Success)
	//{
	//	writeln(L"Failed to find FConfig::LoadIni pattern: %d / %s", rc, SPIReturnToString(rc));
	//	//return false;
	//}
	//else if (auto const rc = InterfacePtr->InstallHook(MYHOOK "FConfigLoadIni", FConfigCombineFromBuffer, FConfigCombineFromBuffer_hook, reinterpret_cast<void**>(&FConfigCombineFromBuffer_orig));
	//	rc != SPIReturn::Success)
	//{
	//	writeln(L"Attach - failed to hook LoadIni: %d / %s", rc, SPIReturnToString(rc));
	//	//return false;
	//}
	//else
	//{
	//	writeln(L"Hooked FConfig::LoadIni");
	//}

}


SPI_IMPLEMENT_ATTACH
{
	Common::OpenConsole();
	writeln(L"Initializing DebugLogger...");

	if (auto rc = InterfacePtr->InstallHook("OutputDebugStringW", (void*)OutputDebugStringW, (void*)OutputDebugStringW_Hook, (void**)&OutputDebugStringW_Orig);
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook OutputDebugStringW: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}
	writeln(L"Initialized DebugLogger");


	auto _ = SDKInitializer::Instance();
	writeln(L"Initializing CreateImport hook...");
	if (auto const rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&CreateImport), "48 8b c4 55 41 54 41 55 41 56 41 57 48 8b ec 48 83 ec 70 48 c7 45 d0 fe ff ff ff 48 89 58 10 48 89 70 18 48 89 78 20 4c 63 e2");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find CreateImport pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}
	if (auto const rc = InterfacePtr->InstallHook(MYHOOK "CreateImport", CreateImport, CreateImport_hook, reinterpret_cast<void**>(&CreateImport_orig));
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook CreateImport: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}
	writeln(L"Hooked CreateImport");


	if (const auto rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&ProcessInternal), "40 53 55 56 57 48 81 EC 88 00 00 00 48 8B 05 B5 25 58 01");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find ProcessInternal pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}
	if (const auto rc = InterfacePtr->InstallHook(MYHOOK "ProcessInternal", ProcessInternal, ProcessInternal_hook, reinterpret_cast<void**>(&ProcessInternal_orig));
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook ProcessInternal: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}

	// LOAD PACKAGE PERSISTENT ----------------------------------------------------------------
	/*writeln(L"Initializing LoadPackagePersistent hook...");
	if (auto const rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&LoadPackagePersistent), "40 53 56 57 41 54 41 55 41 56 41 57 48 81 ec e0 02 00 00 48 c7 84 24 b8 00 00 00");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find LoadPackagePersistent pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}

	if (auto const rc = InterfacePtr->InstallHook(MYHOOK "LoadPackagePersistent", LoadPackagePersistent, LoadPackagePersistent_hook, reinterpret_cast<void**>(&LoadPackagePersistent_orig));
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook LoadPackagePersistent: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}
	writeln(L"Hooked LoadPackagePersistent");*/

	// LOGF HOOK?--------------------
	hookLoggingFunc(InterfacePtr);

	return true;
}


SPI_IMPLEMENT_DETACH
{
	//DebugActiveProcessStop(GetCurrentProcessId());
	Common::CloseConsole();
	logger.close();
	return true;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID) {
	if (reason == DLL_PROCESS_DETACH)
	{
		logger.close();
	}

	return TRUE;
}