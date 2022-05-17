#include <stdio.h>
#include <io.h>
#include <string>
#include <fstream>
#include <thread>

#include "HookPrototypes.h"

SPI_PLUGINSIDE_SUPPORT(L"DebugLogger", L"3.0.0", L"ME3Tweaks", SPI_GAME_LE1, SPI_VERSION_ANY);
SPI_PLUGINSIDE_PRELOAD;
SPI_PLUGINSIDE_SEQATTACH;

ME3TweaksASILogger logger("DebugLogger v3", "LE1DebugLogger.log");

// Logs a message from a source
void logMessage(const wchar_t* logSource, wchar_t* formatStr, void* param1, void* param2)
{
	// We have to prepare the formatting string since it's an inbound parameter
	auto preString = wstring_format(L"%s: %s", logSource, formatStr);
	logger.writeToLog(wstring_format(preString.data(), param1, param2), true, true);
}

// Not in the header because this is not part of the game we are hooking.
typedef void (WINAPI* tOutputDebugStringW)(LPCWSTR lpcszString);
tOutputDebugStringW OutputDebugStringW_orig = nullptr;
void WINAPI OutputDebugStringW_hook(LPCWSTR lpcszString)
{
	OutputDebugStringW_orig(lpcszString);
	logger.writeToLog(std::wstring_view{ lpcszString }.data(), true);
	logger.flush();
}


// LOG FAILED IMPORTS
UObject* CreateImport_hook(ULinkerLoad* Context, int i)
{
	UObject* object = CreateImport_orig(Context, i);
	if (object == nullptr)
	{
		FObjectImport importEntry = Context->ImportMap(i);
		logger.writeToLog(wstring_format(L"Could not resolve #%d: %hs (%hs) in file: %s\n", -i - 1, importEntry.ObjectName.GetName(), importEntry.ClassName.GetName(), Context->Filename.Data), true);
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

	// Kinda jank way to re-use this code by making it create a string a certain way
	logMessage(L"LogInternal() from %hs", L"%s", callingObject->GetFullName(), stringArg.Data);

	//restore the code pointer so LogInternal executes normally.
	stackFrame->Code = originalCodePointer;
	LogInternal_orig(callingObject, stackFrame);
}

#pragma endregion LogInternal

#pragma region PackageLoading
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


	logger.writeToLog(wstring_format(L"Loading package synchronously: %s\n", packageName), true);
	return LoadPackage_orig(outer, packageName, loadFlags);
}


uint32 LoadPackageAsyncTick_hook(UnLinker* linker, int a2, float a3)
{
	// Logger writes after the call cause linker might be null to start with, it's populated when tick begins
	auto result = LoadPackageAsyncTick_orig(linker, a2, a3);
	logger.writeToLog(wstring_format(L"Loading package asynchronously: %s, %f%%\n", linker->PackageName, linker->EstimatedLoadPercentage), true);
	// writeln("Loading package asynchronously: %s, %f%%", linker->PackageName, linker->EstimatedLoadPercentage);
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
//void RootObject_hook(UObject* object)
//{
//	//writeln("Rooting object %hs", object->GetFullName());
//	RootObject_orig(object);
//}
//
//void BioDownloadableContentRootPackage_hook(void* extraContent, UPackage* package)
//{
//	writeln("DLC Rooting Package %hs", package->GetFullName());
//	BioDownloadableContentRootPackage_orig(extraContent, package);
//}

// DEBUG: APP LOAD FILE TO STRING
//bool appLoadFileToString_hook(FString* result, wchar_t* filename, void* fileManager, unsigned int flags1)
//{
//	// Param3: GFileManager?
//	writeln(L"appLoadFileToString: %s", filename);
//	auto loadResult = appLoadFileToString_orig(result, filename, fileManager, flags1);
//	return loadResult;
//}
//
//void logMemorySmth_hook(void* parm1, wchar_t* parm2)
//{
//	logMemorySmth_orig(parm1, parm2);
//}

//void* generateNameFromDisk_hook(void* param1, void* param2, wchar_t* param3)
//{
//	writeln("Generate name %s", param3);
//	auto val = generateNameFromDisk_orig(param1, param2, param3);
//	return val;
//}
//
//void sfxNameConstructor_hook(unsigned int* outIndex, wchar_t* nameValue, int nameNumber, BOOL parm4, BOOL parm5)
//{
//	if (nameNumber != 0)
//	{
//		wchar_t* t = L"poop";
//		unsigned int outIdx[2];
//		sfxNameConstructor_orig(&outIdx[0], t, 0, 1, 1);
//		writeln("TEST name lookup: %i_%i %s %i %i %i", outIdx[0], outIdx[1], t, 0, 1, 1);
//
//		auto chunk = SDKInitializer::Instance()->GetBioNamePools()[0];
//		auto entry = (FNameEntry*)((BYTE*)chunk + outIdx[0]);
//		auto value = entry->AnsiName;
//
//	}
//	sfxNameConstructor_orig(outIndex, nameValue, nameNumber, parm4, parm5);
//	writeln("Name lookup: %i %s %i %i %i", *outIndex, nameValue, nameNumber, parm4, parm5);
//}

//void* GetBioEventNotifier()
//{
//	if (GWorld != nullptr)
//	{
//		auto something1 = *(int64*)((int64*)(GWorld)+0x88);
//		auto something2 = **(int64**)(something1 + 0x60);
//		auto bioEventNotifier = *(int64*)(something2 + 0xb8c);
//		return (void*)bioEventNotifier;
//	}
//}
//
//void LoadSlider2DA_hook(void* parm1)
//{
//	LoadSlider2DA_orig(parm1);
//}

//void* GetBioWorldInfo()
//{
//	// Doesn't work!
//	/*if (GWorld)
//	{
//		return GWorld->CurrentLevel1->Actors.Data[0];
//	}*/
//	return nullptr;
//}

void EventNotifierAddNotice_hook(void* bioEventNotifier, int nType, int nContext, int nTimeToLive, int nIconIndex,
	INT stringRefTitle, wchar_t* strTitle, int nQuantity, int nQuantMin, int nQuantMax)
{
	EventNotifierAddNotice_orig(bioEventNotifier, nType, nContext, nTimeToLive, nIconIndex, /*stringRefTitle*/157152, strTitle, nQuantity, nQuantMin, nQuantMax);
}

void* GStringManager = nullptr;

typedef FString* (*tTLKLookup)(void* param1, FString* outString, int stringID, BOOL bParse);
tTLKLookup TLKLookup = nullptr;
tTLKLookup TLKLookup_orig = nullptr;
int countBetween = 5;
FString* TLKLookup_hook(void* param1, FString* outString, int stringID, BOOL bParse)
{
	//if (countBetween) {
	//	std::this_thread::sleep_for(chrono::seconds(countBetween));
	//	countBetween = 0; // Debugger should attach by now
	//}

	auto retVal = TLKLookup_orig(param1, outString, stringID, bParse);
	if (outString && outString->Count > 0) {
		writeln(L"GetString(%p, %s, %i, %i)", param1, outString->Data, stringID, bParse);
	}
	else
	{
		//writeln(L"GetString(%p, (null), %i, %i)", param1, stringID, bParse);
	}
	return retVal;
}

void logAllocationFailure(UClass* instancingClass, UObject* outer, FName objClassName, long long loadFlags, UObject* archetype) {
	char* instancingClassName = instancingClass ? instancingClass->GetFullName() : nullptr;
	char* outerName = outer ? outer->GetFullName() : nullptr;
	char* objectName = objClassName.Instanced();
	char* archetypeName = archetype ? archetype->GetFullName() : nullptr;
	logger.writeToLog(L"ERROR ALLOCATING OBJECT! Some information that may help track down the problem:\n", true);
	logger.writeToLog(wstring_format(L"\tInstancing class name: %hs\n", instancingClassName), true);
	logger.writeToLog(wstring_format(L"\tOuter ('Link' in modding tools): %hs\n", outerName), true);
	logger.writeToLog(wstring_format(L"\tName of object being created: %hs\n", objectName), true);
	logger.writeToLog(wstring_format(L"\tArchetype: %hs\n", archetypeName), true);

	logger.writeToLog(L"DebugLogger: Terminating application due to crash in StaticAllocateObject(). See the DebugLogger log file.\n", true);
	logger.flush();
}

UObject* StaticAllocateObject_hook(
	UClass* instancingClass,
	UObject* outer,
	FName objClassName,
	long long loadFlags,
	UObject* archetype,
	void* errorDev, // FOutputDevice
	const wchar_t* a7, // Ghidra shows this is pretty commonly 0
	void* instancePtr, // Ghidra shows this is pretty commonly 0
	void* a9) // Ghidra shows this is pretty commonly 0
{
	__try {
		return StaticAllocateObject_orig(instancingClass, outer, objClassName, loadFlags, archetype, errorDev, a7, instancePtr, a9);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		// We failed to allocate an object
		// Game's gonna die. Let's log it

		// This has to be in a different function since it needs unwound and
		// that can't be done in __try __except
		logAllocationFailure(instancingClass, outer, objClassName, loadFlags, archetype);
		std::this_thread::sleep_for(chrono::seconds(8));
		exit(1);
	}
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

	//INIT_FIND_PATTERN_POSTHOOK(logMemorySmth, /*"40 57 48 83 ec*/ "40 48 c7 44 24 20 fe ff ff ff 48 89 5c 24 50 48 89 6c 24 58 48 89 74 24 60 49 8b f8 48 8b ea");
	//INIT_HOOK_PATTERN(logMemorySmth);
}

typedef void* (*tSelfPointerFunc)(void* ptr);
tSelfPointerFunc InputPoll = (tSelfPointerFunc)0x7ff7129ca4f0;
tSelfPointerFunc InputPoll_orig = nullptr;


void* InputPoll_hook(void* ptr)
{
	writeln(L"InputPoll: %p", ptr);
	auto t = InputPoll_orig(ptr);
	return t;
}

SPI_IMPLEMENT_ATTACH
{
	Common::OpenConsole();

	writeln(L"Initializing DebugLogger...");
	INIT_CHECK_SDK();

	LoadCommonClassPointers(InterfacePtr);
	// This is the argument used when looking up TLK strings it seems
	GStringManager = findAddressLeaMov(InterfacePtr, "GStringManager","48 8b 0d 4f 74 5a 01 4c 8b c7 e8 d7 3f fa ff 48 8b 5c 24 30 48 83 c4 20");

	// Log debug output messages
	//INIT_HOOK_PATTERN(OutputDebugStringW);

	// REVERSE ENGINEERING STUFF ----------------------------
	// Log loading file to string
	//INIT_FIND_PATTERN_POSTHOOK(appLoadFileToString, /*48 8b c4 55 41*/ " 54 41 55 41 56 41 57 48 8d 68 a1 48 81 ec 00 01 00 00 48 c7 45 17 fe ff ff ff");
	//INIT_HOOK_PATTERN(appLoadFileToString);

	// Works, but not really helpful in this project:
	// TLK Lookup (seems to be basic version) (strref to string RE)
	//INIT_FIND_PATTERN_POSTHOOK(TLKLookup, /*"48 89 54 24 10*/ "56 57 41 56 48 83 ec 30 48 c7 44 24 28 fe ff ff ff 48 89 5c 24 50 48 89 6c 24 60 45 8b f1 41 8b e8 48 8b da 48 8b f1 33 c0 89 44 24 20 48 89 02 48 89 42 08 c7 44 24 20 01 00 00 00");
	//INIT_HOOK_PATTERN(TLKLookup);

	// RE: ToggleDebugCamera
	// Notes: Method 0xff7129ca4f0 is some sort of input polling
	// It is called every frame. When you turn on DebugCamera, this method hits a nullpointer
	// and the game dies
	// So it's not this method, but that's where the access is done
	//INIT_FIND_PATTERN_POSTHOOK(LoadPackage, /*"48 8b c4 44 89*/"40 18 48 89 48 08 53 56 57 41 56 41 57 48 83 ec 50 48 c7 40 b8 fe ff ff ff");
	INIT_HOOK_PATTERN(InputPoll);


	// -------------------------------------------------------


		// Log creating an import for when it fails
		//INIT_FIND_PATTERN_POSTHOOK(CreateImport, /*48 8b c4 55 41*/ "54 41 55 41 56 41 57 48 8b ec 48 83 ec 70 48 c7 45 d0 fe ff ff ff 48 89 58 10 48 89 70 18 48 89 78 20 4c 63 e2");
		//INIT_HOOK_PATTERN(CreateImport);

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

		// When object instances are allocated, if there's an error
		// the game dies. This logs which object was being created
		// that the game died on
		//INIT_FIND_PATTERN_POSTHOOK(StaticAllocateObject, /*"4c 89 44 24 18*/ "55 56 57 41 54 41 55 41 56 41 57 48 8d ac 24 80 fb ff ff 48 81 ec 80 05 00 00");
		//INIT_HOOK_PATTERN(StaticAllocateObject);

		// When the Slider's 2DA is loaded for the character creator
		// For trying to figure out why merges aren't working to the CC 2DAs
		//INIT_FIND_PATTERN_POSTHOOK(LoadSlider2DA, /*"48 8b c4 55 41*/ "54 41 55 41 56 41 57 48 8d a8 b8 fc ff ff 48 81 ec 20 04 00 00 48 c7 85 f8 01 00 00 fe ff ff ff")
		//INIT_HOOK_PATTERN(LoadSlider2DA);
		
		//hookLoggingFunctions(InterfacePtr);

		//INIT_FIND_PATTERN_POSTHOOK(EventNotifierAddNotice, /*"48 8b c4 55 41*/ "54 41 55 41 56 41 57 48 8b ec 48 83 ec 60 48 c7 45 c0 fe ff ff ff 48 89 58 10 48 89 70 18 48 89 78 20 4c 8b f1 33 db 48 89 5d c8 48 89 5d d0 48 89 5d d8 48 89 5d e0 48 89 5d e8 48 89 5d f0");
		//INIT_HOOK_PATTERN(EventNotifierAddNotice);
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