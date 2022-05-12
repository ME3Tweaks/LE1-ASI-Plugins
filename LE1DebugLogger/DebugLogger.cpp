#include <stdio.h>
#include <io.h>
#include <string>
#include <fstream>
#include "HookPrototypes.h"

SPI_PLUGINSIDE_SUPPORT(L"DebugLogger", L"2.0.0", L"ME3Tweaks", SPI_GAME_LE1, SPI_VERSION_ANY);
SPI_PLUGINSIDE_PRELOAD;
SPI_PLUGINSIDE_SEQATTACH;

ME3TweaksASILogger logger("DebugLogger v2", "LE1DebugLogger.log");

// Not in the header because this is not part of the game we are hooking.
typedef void (WINAPI* tOutputDebugStringW)(LPCWSTR lpcszString);
tOutputDebugStringW OutputDebugStringW_orig = nullptr;
void WINAPI OutputDebugStringW_hook(LPCWSTR lpcszString)
{
	OutputDebugStringW_orig(lpcszString);
	writeMsg(L"%s", lpcszString); // string already has a newline on the end
	logger.writeWideToLog(std::wstring_view{ lpcszString });
	logger.flush();
}


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

#pragma region FOutputDevice::Logf
void FOutputDeviceLogf_hook(void* fOutputDevice, int* code, wchar_t* formatStr, void* param1)
{
	logMessage(L"appLogf", formatStr, param1, param1);
}

#pragma endregion FOutputDevice::Logf

#pragma region FErrorOutputDevice::Logf
void FErrorOutputDeviceLogf_hook(void* outputDevice, wchar_t* formatStr, void* param1, void* param2)
{
	logMessage(L"appErrorLogf", formatStr, param1, param2);
}

#pragma endrgion FErrorOutputDevice::Logf



#pragma region LogInternal

void LogInternal_hook(UObject* callingObject, LE1FFrame* stackFrame)
{
	// 0x20 = Object?
	// 0x28 = Code?
	// 0x2C = ??
	// 0x38 = PreviousFrame?

	BYTE* originalCodePointer = stackFrame->Code;
	BYTE nativeIndex = *stackFrame->Code++;
	FString stringArg;
	UObject* sfObject = stackFrame->Object;
	GNatives[nativeIndex](sfObject, (LE1FFrame*)stackFrame, &stringArg);
	writeln(L"LogInternal() from %hs: %s", callingObject->GetFullName(), stringArg.Data);

	//restore the code pointer so LogInternal executes normally.
	stackFrame->Code = originalCodePointer;
	LogInternal_orig(callingObject, stackFrame);
}

#pragma endregion LogInternal

#pragma region PackageLoading

void LoadPackagePersistent_hook(int64 param1, const wchar_t* packageName, uint32 param3, int64* param4, uint32* param5)
{
	writeln("Loading persistent package: %s", packageName);
	LoadPackagePersistent_orig(param1, packageName, param3, param4, param5);
}

// Returns a UPackage, but we don't have that defined
UPackage* LoadPackage_hook(UPackage* outer, wchar_t* packageName, ELoadFlags loadFlags)
{
	// FindPackageFile doesn't seem to work. Might need to figure out what parameters it really needs.
	// The below commented out code crashes the game

	/*std::this_thread::sleep_for(std::chrono::seconds(8));
	FString outName;
	wchar_t* language = L"";
	auto pFound = GPackageFileCache->FindPackageFile(param2, nullptr, outName, language, false);
	if (pFound)
	{
		writeln("Loading package synchronously: %s", outName.Data);
	}
	else
	{
		writeln("Loading package synchronously: %s", param2);
	}*/

	writeln("Loading package synchronously: %s, %hs, hasOuter: %s", packageName, GetLoadFlagsString(loadFlags).c_str(), outer != nullptr ? L"true" : L"false");
	auto package = LoadPackage_orig(outer, packageName, loadFlags);
	/*if (package)
	{
		writeln(", took %fms", package->LoadTime);
	} else
	{
		writeln(", package disposed!");
	}*/
	return package;
}


uint32 LoadPackageAsyncTick_hook(UnLinker* linker, int a2, float a3)
{
	auto result = LoadPackageAsyncTick_orig(linker, a2, a3);
	writeln("Loading package asynchronously: %s, %f%%", linker->PackageName, linker->EstimatedLoadPercentage);
	return result;
}


void LinkerLoadPreload_hook(UnLinker* linker, UObject* objectToLoad)
{

	// This prints out pretty much everything that loads
	// Not sure how to properly hook on preload here

	// This is used when loading the ref shader cache file, the game seems to actually be doing a
	// seek free load on the CacheObject, which loads the file via preload
	//auto fullPath = objectToLoad->GetFullPath();
	////if (isPartOf(fullPath, "CacheObject"))
	////{
	//	//std::this_thread::sleep_for(std::chrono::seconds(8));

	//	// I took this right out of Ghidra, cause I don't want to deal with a FQWORD (Isn't this just a int64?)
	//int64* objectFlags = (int64*)((int64)objectToLoad + 0xC);
	//if ((*objectFlags & 0x20000000000) != 0) {

	//	// Object needs loaded, so the file is going to be loaded.
	//	writeln("SeekFreeLoading object: %hs", objectToLoad->GetFullPath());
	//}
	////}
	LinkerLoadPreload_orig(linker, objectToLoad);
}


#pragma endregion PackageLoading


void RootObject_hook(UObject* object)
{
	//writeln("Rooting object %hs", object->GetFullName());
	RootObject_orig(object);
}

void BioDownloadableContentRootPackage_hook(void* extraContent, UPackage* package)
{
	writeln("DLC Rooting Package %hs", package->GetFullName());
	BioDownloadableContentRootPackage_orig(extraContent, package);
}

// DEBUG: APP LOAD FILE TO STRING
bool appLoadFileToString_hook(FString* result, wchar_t* filename, void* fileManager, unsigned int flags1)
{
	// Param3: GFileManager?
	writeln(L"appLoadFileToString: %s", filename);
	auto loadResult = appLoadFileToString_orig(result, filename, fileManager, flags1);
	return loadResult;
}

void logMemorySmth_hook(void* parm1, wchar_t* parm2)
{
	logMemorySmth_orig(parm1, parm2);
}

void* generateNameFromDisk_hook(void* param1, void* param2, wchar_t* param3)
{
	writeln("Generate name %s", param3);
	auto val = generateNameFromDisk_orig(param1, param2, param3);
	return val;
}

void sfxNameConstructor_hook(unsigned int* outIndex, wchar_t* nameValue, int nameNumber, BOOL parm4, BOOL parm5)
{
	if (nameNumber != 0)
	{
		wchar_t* t = L"poop";
		unsigned int outIdx[2];
		sfxNameConstructor_orig(&outIdx[0], t, 0, 1, 1);
		writeln("TEST name lookup: %i_%i %s %i %i %i", outIdx[0], outIdx[1], t, 0, 1, 1);

		auto chunk = SDKInitializer::Instance()->GetBioNamePools()[0];
		auto entry = (FNameEntry*)((BYTE*)chunk + outIdx[0]);
		auto value = entry->AnsiName;

	}
	sfxNameConstructor_orig(outIndex, nameValue, nameNumber, parm4, parm5);
	writeln("Name lookup: %i %s %i %i %i", *outIndex, nameValue, nameNumber, parm4, parm5);
}

// Hooks logging functions
bool hookLoggingFunctions(ISharedProxyInterface* InterfacePtr)
{
	// Allows logging LogInternal() calls (even user ones)
	INIT_FIND_PATTERN_POSTHOOK(LogInternal, /*"40 57 48 83 ec */"40 48 c7 44 24 20 fe ff ff ff 48 89 5c 24 50 48 89 74 24 60 48 8b da 33 f6 48 89 74 24 28 48 89 74 24 30");
	INIT_HOOK_PATTERN(LogInternal);

	// WarnInternal prints to LogF which is captured below, it just won't have the prefix
	// appAssertFailed writes to debug output

	INIT_FIND_PATTERN_POSTHOOK(FOutputDeviceLogf, /*48 8b c4 48 89*/ "50 10 4c 89 40 18 4c 89 48 20 56 48 83 ec 50 83 79 08 00 48 8b f1 0f 85 bf 00 00 00");
	INIT_HOOK_PATTERN(FOutputDeviceLogf);

	INIT_FIND_PATTERN_POSTHOOK(FErrorOutputDeviceLogf, /*"48 8b c4 48 89*/ "50 10 4c 89 40 18 4c 89 48 20 56 48 83 ec 50 83 79 08 00 48 8b f1");
	INIT_HOOK_PATTERN(FErrorOutputDeviceLogf);

	INIT_FIND_PATTERN_POSTHOOK(logMemorySmth, /*"40 57 48 83 ec*/ "40 48 c7 44 24 20 fe ff ff ff 48 89 5c 24 50 48 89 6c 24 58 48 89 74 24 60 49 8b f8 48 8b ea");
	INIT_HOOK_PATTERN(logMemorySmth);

}

SPI_IMPLEMENT_ATTACH
{
	Common::OpenConsole();

	writeln(L"Initializing DebugLogger...");
	INIT_CHECK_SDK();

	LoadCommonClassPointers(InterfacePtr);

	// Log debug output messages
	//INIT_HOOK_PATTERN(OutputDebugStringW);

	// Log loading file to string
	//INIT_FIND_PATTERN_POSTHOOK(appLoadFileToString, /*48 8b c4 55 41*/ " 54 41 55 41 56 41 57 48 8d 68 a1 48 81 ec 00 01 00 00 48 c7 45 17 fe ff ff ff");
	//INIT_HOOK_PATTERN(appLoadFileToString);

	// RE: SFXName
	// When package loads this method is called
	//INIT_FIND_PATTERN_POSTHOOK(generateNameFromDisk, /*"40 53 48 83 ec*/ "30 49 8b d0 c7 44 24 20 00 00 00 00 45 33 c0 41 b9 01 00 00 00 48 8b d9 e8 5e c6 00 00 48 8b c3");
	//	INIT_HOOK_PATTERN(generateNameFromDisk);

	//INIT_FIND_PATTERN_POSTHOOK(sfxNameConstructor, /*"40 55 56 57 41*/ "54 41 55 41 56 41 57 48 81 ec 00 07 00 00 48 c7 44 24 50 fe ff ff ff 48 89 9c 24 50 07 00 00 48 8b 05 fd 2d 5d 01 48 33 c4 48 89 84 24 f0 06 00 00");
		//INIT_HOOK_PATTERN(sfxNameConstructor);



		// PACKAGE ROOTING
		// NOTE: THIS POINTS TO A FUNCTION FOLLOWING BY 0X10 AS THE FUNC IS SMALL
		//INIT_FIND_PATTERN_POSTHOOK(RootObject, /*"40 55 48 8b ec*/"48 83 ec 50 48 c7 45 e0 fe ff ff ff 48 89 5c 24 60");
		//writeln("RootObject currently at 0x%p", RootObject);
		//RootObject = (tUObjectRoot)((char*)RootObject - 0x10);
		//writeln("Actual RootObject is at 0x%p", RootObject);
		//INIT_HOOK_PATTERN(RootObject);

		//INIT_FIND_PATTERN_POSTHOOK(BioDownloadableContentRootPackage, /*48 89 5c 24 08*/ "48 89 74 24 10 57 48 83 ec 20 48 8d 99 a0 00 00 00 48 8b f2 48 63 7b 08 44 8b 43 0c");
		//INIT_HOOK_PATTERN(BioDownloadableContentRootPackage);

		// Log creating an import for when it fails
		INIT_FIND_PATTERN_POSTHOOK(CreateImport, /*48 8b c4 55 41*/ "54 41 55 41 56 41 57 48 8b ec 48 83 ec 70 48 c7 45 d0 fe ff ff ff 48 89 58 10 48 89 70 18 48 89 78 20 4c 63 e2");
		INIT_HOOK_PATTERN(CreateImport);

		// FIX ADDR
		// OBJECT PRELOAD (called on every object in a package file, can be used for seekfree)
		//INIT_FIND_PATTERN_POSTHOOK(LinkerLoadPreload, /*"40 55 56 57 41*/ "54 41 55 41 56 41 57 48 8d 6c 24 d9 48 81 ec 90 00 00 00 48 c7 45 e7 fe ff ff ff");
		//INIT_HOOK_PATTERN(LinkerLoadPreload);

		// SYNC LOAD PACKAGE
		//INIT_FIND_PATTERN_POSTHOOK(LoadPackage, /*"48 8b c4 44 89*/"40 18 48 89 48 08 53 56 57 41 56 41 57 48 83 ec 50 48 c7 40 b8 fe ff ff ff");
		//INIT_HOOK_PATTERN(LoadPackage);

		// ASYNC LOAD PACKAGE
		//INIT_FIND_PATTERN_POSTHOOK(LoadPackageAsyncTick, /*"48 8b c4 55 56*/ "57 41 54 41 55 41 56 41 57 48 81 ec 80 00 00 00 48 c7 40 90 fe ff ff ff");
		//INIT_HOOK_PATTERN(LoadPackageAsyncTick);

		INIT_FIND_PATTERN_POSTHOOK(LoadPackage, /*"48 8b c4 44 89*/ "40 18 48 89 48 08 53 56 57 41 56 41 57 48 83 ec 50 48 c7 40 b8 fe ff ff ff");
		INIT_HOOK_PATTERN(LoadPackage);

		//hookLoggingFunctions(InterfacePtr);

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