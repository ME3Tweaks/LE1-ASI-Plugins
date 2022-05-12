// This file is not used but is kept for documentation purposes


// FCONFIG STUFF (INI LOADING)
/*
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
 */

 // =======================
 // CachePackage ==========
 // =======================
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

	 // ====================
	 // TFC Registration
	 // ====================
	 /*#pragma region TFCRegistering
	 bool testRegistered = false;
	 void RegisterTFC_hook(FString* tfc)
	 {
		 logMessage(L"Registering TFC:", L"%s", tfc->Data, nullptr);
		 RegisterTFC_orig(tfc);
	 }
	 #pragma endregion TFCRegistering */

	 // This is mainly just for debugging TFC registration
	 //INIT_FIND_PATTERN_POSTHOOK(RegisterTFC, /*48 8b c4 57 41*/ "56 41 57 48 83 ec 60 48 c7 40 a8 fe ff ff ff 48 89 58 10 48 89 68 18 48 89 70 20 4c 8b f9 48 8b 0d 6e 3e 45 01 48 8b 01 48 8d 2d b0 9d d4 00 41 83 7f 08 00 74 05 49 8b 17 eb 03");
	 //INIT_HOOK_PATTERN(RegisterTFC);

	 // ======================
	 // appFindFiles
	 // ======================
	 /*#pragma region FindFiles
	 bool redirected = false;
	 FString myData[3];

	 void FindFiles_hook(void* classPtr, TArray<wchar_t>* outFiles, wchar_t* searchPattern, bool files, bool directories, int flagSet)
	 {
		 writeln(L"FindFiles: Flag %i, Files: %i, Folders: %i, %s", flagSet, files, directories, searchPattern);
		 FindFiles_orig(classPtr, outFiles, searchPattern, files, directories, flagSet);
		 writeln(L"  >> Found %d files", outFiles->Count);
	 }

	 #pragma endregion FindFiles*/

	 // Works, just disabled right now
	 //INIT_FIND_PATTERN_POSTHOOK(FindFiles, /*40 55 53 56 57*/ "41 54 41 55 41 56 41 57 48 8d ac 24 d8 fa ff ff 48 81 ec 28 06 00 00 48 c7 45 d0 fe ff ff ff");
	 //INIT_HOOK_PATTERN(FindFiles);



// MISC STUFF
/*
 


void MsgFDialog_hook(int messageBoxType, wchar_t* formatStr, wchar_t* param1)
{
	MessageBoxW(NULL, formatStr, L"Game message", 0x0);
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

 */

// ==============================
// UFunction::Bind
// ==============================

// This is only for printing out the natives addresses
// These will be pinned in ME3Tweaks Discord since they don't change
 //writeln(L"Initializing UFunction::Bind hook...");
 //if (auto const rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&UFunctionBind), "48 8B C4 55 41 56 41 57 48 8D A8 78 F8 FF FF 48 81 EC 70 08 00 00 48 C7 44 24 50 FE FF FF FF 48 89 58 10 48 89 70 18 48 89 78 20 48 8B ?? ?? ?? ?? ?? 48 33 C4 48 89 85 60 07 00 00 48 8B F1 E8 ?? ?? ?? ?? 48 8B F8 F7 86");
 //	rc != SPIReturn::Success)
 //{
 //	writeln(L"Attach - failed to find UFunction::Bind pattern: %d / %s", rc, SPIReturnToString(rc));
 //	return false;
 //}
 //if (auto const rc = InterfacePtr->InstallHook(MYHOOK "UFunction::Bind", UFunctionBind, HookedUFunctionBind, reinterpret_cast<void**>(&UFunctionBind_orig));
 //	rc != SPIReturn::Success)
 //{
 //	writeln(L"Attach - failed to hook UFunction::Bind: %d / %s", rc, SPIReturnToString(rc));
 //	return false;
 //}
 //writeln(L"Hooked UFunction::Bind");
 //return true;