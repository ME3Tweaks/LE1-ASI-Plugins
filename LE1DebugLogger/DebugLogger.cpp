#include <stdio.h>
#include <io.h>
#include <string>
#include <fstream>
#include "LE1DebugLogger.h"
#include "HookPrototypes.h"

SPI_PLUGINSIDE_SUPPORT(L"DebugLogger", L"2.0.0", L"ME3Tweaks", SPI_GAME_LE1, SPI_VERSION_ANY);
SPI_PLUGINSIDE_PRELOAD;
SPI_PLUGINSIDE_SEQATTACH;

ME3TweaksASILogger logger("DebugLogger v2", "DebugLogger.txt");

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


void* GFileManager;


// LOG FAILED IMPORTS
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

// DEBUG: APP LOAD FILE TO STRING
bool appLoadFileToString_hook(FString* result, wchar_t* filename, void* fileManager, unsigned int flags1)
{
	// Param3: GFileManager?
	GFileManager = fileManager;
	writeln(L"appLoadFileToString: %s", filename);
	auto loadResult = appLoadFileToString_orig(result, filename, fileManager, flags1);
	return loadResult;
}


// LOAD PACKAGE PERSISTENT
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
void LogF_hook(void* fOutputDevice, wchar_t* formatStr, void* param1, void* param2)
{
	logMessage(L"appLogf", formatStr, param1, param2);
}

void ErrorLogF_hook(void* fOutputDevice, int* code, wchar_t* formatStr, void* param1)
{
	logMessage(L"appErrorLogf", formatStr, param1, param1);
}

//typedef void (*tFOutputDeviceLogF)(void* param1, wchar_t* param2, wchar_t* param3);
void MsgF_hook(void* fOutputDevice, wchar_t* formatStr, wchar_t* param1)
{
	// Seems dangerous.
	logMessage(L"appMsgf", formatStr, param1, 0);
}

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

// DEBUGGING RE ONLY
bool autoConfigTestDone = false;
void FConfigCombineFromBuffer_hook(void* Context, wchar_t* filePath, FString* contents, int extra)
{
	if (!autoConfigTestDone) {
		autoConfigTestDone = true;
		FString loadedIni;
		wchar_t* path = L"X:\\Google Drive\\Mass Effect Legendary Modding\\LE1\\FConfigCombiner\\BIOGame.ini";
		wchar_t* fakePath = L"..\\..\\BIOGame\\Config\\BIOGame.ini";
		if (appLoadFileToString_orig(&loadedIni, path, GFileManager, 0))
		{
			FConfigCombineFromBuffer_orig(Context, fakePath, &loadedIni, 0);
			writeln(L"Did combiney thing");
		}
	}
	writeln("FConfig::CombineFromBuffer: %p %s", Context, filePath);
	FConfigCombineFromBuffer_orig(Context, filePath, contents, extra);
}

#pragma region TFCRegistering
bool testRegistered = false;
void RegisterTFC_hook(FString* tfc)
{
	/*if (!testRegistered)
	{
		testRegistered = true;
		FString str = L"C:\\Users\\mgame\\Desktop\\Textures_DLC_MOD_AdvancedWeaponModels.tfc";
		RegisterTFC_hook(&str);
	}*/
	logMessage(L"Registering TFC:", L"%s", tfc->Data, nullptr);
	RegisterTFC_orig(tfc);
}
#pragma endregion TFCRegistering

#pragma region FindFiles
bool redirected = false;
FString myData[3];

void FindFiles_hook(void* classPtr, TArray<wchar_t>* outFiles, wchar_t* searchPattern, bool files, bool directories, int flagSet)
{
	writeln(L"FindFiles: Flag %i, Files: %i, Folders: %i, %s", flagSet, files, directories, searchPattern);
	FindFiles_orig(classPtr, outFiles, searchPattern, files, directories, flagSet);
	writeln(L"  >> Found %d files", outFiles->Count);
}

#pragma endregion FindFiles

// Following is used to register ISB. Left here for documentation purposes.

/*
#pragma region CachePackage
typedef void (*tCachePackage)(long long parm1, wchar_t* filePath, bool overrideIfDupe, bool warnIfExists);
tCachePackage CachePackage = nullptr;
tCachePackage CachePackage_orig = nullptr;
void CachePackage_hook(long long parm1, wchar_t* filePath, bool overrideIfDupe, bool warnIfExists)
{
	//CachePackage = (tCachePackage)0x7ff7121b8fb0;
	writeln(L"CachePackage: OVERRIDE: %d WARN: %d %s", overrideIfDupe, warnIfExists, filePath);

	CachePackage_orig(parm1, filePath, overrideIfDupe, warnIfExists);
}

tCachePackage CacheContentWrapper = nullptr;
tCachePackage CachePackageWrapper_orig = nullptr;
void CachePackageWrapper_hook(long long parm1, wchar_t* filePath, bool overrideIfDupe, bool warnIfExists)
{
	//CachePackage = (tCachePackage)0x7ff7121b8fb0;
	writeln(L"CachePackageWrapper: OVERRIDE: %d WARN: %d %s", overrideIfDupe, warnIfExists, filePath);

	CachePackageWrapper_orig(parm1, filePath, overrideIfDupe, warnIfExists);
}

#pragma endregion CachePackage
*/

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
	if (auto rc = InterfacePtr->InstallHook("OutputDebugStringW", (void*)OutputDebugStringW, (void*)OutputDebugStringW_Hook, (void**)&OutputDebugStringW_Orig);	rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook OutputDebugStringW: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}

	auto _ = SDKInitializer::Instance();

	// Left here for documentation purposes
	/*
	if (auto rc = InterfacePtr->InstallHook("CachePackage", (void*)0x7ff7121b8fb0, (void*)CachePackage_hook, (void**)&CachePackage_orig);	rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook CachePackage: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}

	if (auto rc = InterfacePtr->InstallHook("CachePackageWrapper", (void*)0x7ff7120e3760, (void*)CachePackageWrapper_hook, (void**)&CachePackageWrapper_orig);	rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook CachePackageWrapper: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}*/


	// Works, just disabled right now
	//INIT_FIND_PATTERN_POSTHOOK(FindFiles, /*40 55 53 56 57*/ "41 54 41 55 41 56 41 57 48 8d ac 24 d8 fa ff ff 48 81 ec 28 06 00 00 48 c7 45 d0 fe ff ff ff");
	//INIT_HOOK_PATTERN(FindFiles);

	INIT_FIND_PATTERN_POSTHOOK(appLoadFileToString, /*48 8b c4 55 41*/ " 54 41 55 41 56 41 57 48 8d 68 a1 48 81 ec 00 01 00 00 48 c7 45 17 fe ff ff ff");
	INIT_HOOK_PATTERN(appLoadFileToString);

	INIT_FIND_PATTERN_POSTHOOK(CreateImport, /*48 8b c4 55 41*/ "54 41 55 41 56 41 57 48 8b ec 48 83 ec 70 48 c7 45 d0 fe ff ff ff 48 89 58 10 48 89 70 18 48 89 78 20 4c 63 e2");
	INIT_HOOK_PATTERN(CreateImport);
	/*writeln(L"Initializing CreateImport hook...");
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
	}*/

	// LOAD PACKAGE PERSISTENT ----------------------------------------------------------------
	//INIT_FIND_PATTERN_POSTHOOK(LoadPackagePersistent, /*40 53 56 57 41*/ "54 41 55 41 56 41 57 48 81 ec e0 02 00 00 48 c7 84 24 b8 00 00 00");
	//INIT_HOOK_PATTERN(LoadPackagePersistent);

	// LOGF HOOK?--------------------
	hookLoggingFunc(InterfacePtr);

	// This is mainly just for debugging TFC registration
	//INIT_FIND_PATTERN_POSTHOOK(RegisterTFC, /*48 8b c4 57 41*/ "56 41 57 48 83 ec 60 48 c7 40 a8 fe ff ff ff 48 89 58 10 48 89 68 18 48 89 70 20 4c 8b f9 48 8b 0d 6e 3e 45 01 48 8b 01 48 8d 2d b0 9d d4 00 41 83 7f 08 00 74 05 49 8b 17 eb 03");
	//INIT_HOOK_PATTERN(RegisterTFC);

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