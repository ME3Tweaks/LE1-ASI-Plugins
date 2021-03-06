// This project was forked from d00telemental's LE1AutoloadEnabler repository on 02/03/2022: https://github.com/d00telemental/LENativeExperiments
// due to difficulty building project from that repo and extensions made in this one

#include <filesystem>
#include <Shlwapi.h>
#include <thread>
#include <vector>
#include <Windows.h>
#include "../LE1-SDK/Interface.h"
#include "../LE1-SDK/Common.h"
#include "../LE1-SDK/SdkHeaders.h"
#include "ExtraContent.h"
#include "Logging.h"

#define MYHOOK "LE1AutoloadEnabler"
#ifndef NDEBUG
constexpr bool GIsRelease = false;
#else
constexpr bool GIsRelease = true;
#endif

SPI_PLUGINSIDE_SUPPORT(L"LE1AutoloadEnabler", L"---", L"0.5.0", SPI_GAME_LE1, SPI_VERSION_LATEST);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_SEQATTACH;

bool ContentScanComplete = false;

// Fixes bad launcher logic when not using Autoboot (sets the wrong working directory)
void SetWorkingDirectory() {
	WCHAR path[MAX_PATH];
	GetModuleFileNameW(NULL, path, MAX_PATH);
	std::filesystem::path exePath = path;
	SetCurrentDirectoryW(exePath.parent_path().c_str());
}


// Functions used to make a list of available DLCs.
// ======================================================================

std::wstring GetDLCsRoot()
{
	wchar_t modulePath[512];

	GetModuleFileNameW(nullptr, modulePath, 512);
	PathRemoveFileSpecW(modulePath);
	PathRemoveFileSpecW(modulePath);
	PathRemoveFileSpecW(modulePath);

	std::wstring root;
	root.append(modulePath);
	root.append(L"\\BioGame\\DLC\\");

	return root;
}

std::vector<std::wstring> GetAllDLCAutoloads(std::wstring&& searchRoot)
{
	std::vector<std::wstring> autoloadPaths{};
	searchRoot.append(L"*");

	WIN32_FIND_DATA fd;
	HANDLE handle = FindFirstFileW(searchRoot.c_str(), &fd);
	do
	{
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && wcslen(fd.cFileName) > 4
			&& fd.cFileName[0] == L'D' && fd.cFileName[1] == L'L' && fd.cFileName[2] == L'C' && fd.cFileName[3] == L'_')
		{
			wchar_t autoloadPath[512];
			swprintf_s(autoloadPath, 512, L"..\\..\\BioGame\\DLC\\%s\\AutoLoad.ini", fd.cFileName);
			autoloadPaths.emplace_back(autoloadPath);
		}
	} while (FindNextFile(handle, &fd) != 0);

	return autoloadPaths;
}

// HasAtLeastOneBasegameTFC: So we know when we can call RegisterTFC
typedef bool (*tNoParamBool)();
tNoParamBool HasAtLeastOneBasegameTFC = nullptr;

// ======================================================================
// RegisterTFC prototype so we can call it to register our TFCs
// =====================================================================
typedef void (*tRegisterTFC)(FString* name);
tRegisterTFC RegisterTFC = nullptr;

// The list of pending TFCs to register once our first package file tries to load
std::vector<FString*> DLCTFCsToRegister;

// Logs a message and registers a TFC
void RegisterTFCWrapper(FString* tfcPath)
{
	writeln(L"Registering DLC mod TFC file: %s", tfcPath->Data);
	RegisterTFC(tfcPath);
	// This just crashes it idk why
	//free(tfcPath->Data); // Data consturcted here was made with _wcsdup
}

// ======================================================================
// ProcessIni hook
// Logs every invocation, call itself for each found Autoload.ini.
// ======================================================================

bool GOriginalCalled = false;
ExtraContent* GExtraContent = nullptr;
std::vector<std::wstring> GExtraAutoloadPaths{};

// NI: The first param is actually a 'this' pointer.
typedef void (*tProcessIni)(ExtraContent* ExtraContent, FString* IniPath, FString* BasePath);
tProcessIni ProcessIni = nullptr;
tProcessIni ProcessIni_orig = nullptr;
void ProcessIni_hook(ExtraContent* ExtraContent, FString* IniPath, FString* BasePath)
{
	ProcessIni_orig(ExtraContent, IniPath, BasePath);

	if (!GOriginalCalled)
	{
		GOriginalCalled = true;
		for (const auto& autoloadPath : GExtraAutoloadPaths)
		{
			writeln(L"Registering DLC mod Autoload.ini %s", IniPath->Data);
			ProcessIni(ExtraContent, &FString{ const_cast<wchar_t*>(autoloadPath.c_str()) }, nullptr);
		}
		GExtraContent = ExtraContent;
	}
}

// Sets the RF_Root flag, as part of making object startup
typedef void (*tUObjectRoot)(UObject* callingObject);
tUObjectRoot RootObject = nullptr; // We aren't hooking this, we just need to call it.

// Marks all objects as RF_Root that have a outermost outer that is the same as the listed
// UPackage (which means they are from this package)
void RegisterStartupFile(UPackage* package)
{
	writeln(L"Registering startup file: %hs", package->Name.GetName());

	auto GObjects = SDKInitializer::Instance()->GetObjects();
	for (int i = 0; i < GObjects->Count; i++)
	{
		auto obj = GObjects->Data[i];
		if (obj && obj->Outer)
		{
			// Must not be null and must have an outer (otherwise it's already an object at the root of the hierarchy, which should already be rooted... in theory...)
			UObject* outerMost = obj;
			while (outerMost->Outer != nullptr)
			{
				outerMost = outerMost->Outer; // Go to it's nullptr
			}

			if (outerMost == package)
			{
				// It's a child of this package!
				writeln(L"Rooting startup package object %hs in package %hs", obj->GetFullName(), package->Name.GetName())
				RootObject(obj);
			}
		}
	}
}
// The lazy way
static std::wstring charToWString(const char* text)
{
	const size_t size = std::strlen(text);
	std::wstring wstr;
	if (size > 0) {
		wstr.resize(size);
		std::mbstowcs(&wstr[0], text, size);
	}
	return wstr;
}

// =====================
// InstallDownloadableContent()
// This method calls ProcessIni() to read the Inis and populate the 'ExtraContent' class object.
// This method then loads packages based on what it read in (2DAs, etc)
// This hook marks objects that load from items in the GlobalPackages array as rooted so they don't GC
// This makes them behave like startup files in LE2/LE3 do
// =====================
typedef void (*tInstallDownloadableContent)(void* unk);
tInstallDownloadableContent InstallDownloadableContent = nullptr;
tInstallDownloadableContent InstallDownloadableContent_orig = nullptr;
void InstallDownloadableContent_hook(void* unk)
{
	InstallDownloadableContent_orig(unk);
	for (int i = 0; i < GExtraContent->GlobalPackages.Count; i++)
	{
		auto globalPackageName = GExtraContent->GlobalPackages.Data[i];
		// Find it in the GExtraContent loaded packages
		for (int j = 0; j < GExtraContent->LoadedPackages.Count; j++)
		{
			auto package = GExtraContent->LoadedPackages.Data[j];
			auto isSameName = _wcsicmp(charToWString(package->Name.GetName()).c_str(), globalPackageName.Data) == 0;
			if (package && isSameName)
			{
				// It's a match
				RegisterStartupFile(package);
				break; // Go to the next one
			}
		}
	}
}

// ======================================================================
// ProcessEvent hook
// Renders autoload profiler, allows toggling it.
// ======================================================================

#ifndef NDEBUG
typedef void (*tProcessEvent)(UObject* Context, UFunction* Function, void* Parms, void* Result);
tProcessEvent ProcessEvent = nullptr;

tProcessEvent ProcessEvent_orig = nullptr;
void ProcessEvent_hook(UObject* Context, UFunction* Function, void* Parms, void* Result)
{
	static ExtraContentHUD* hud = nullptr;

	// Render autoload profiler HUD.
	if (!strcmp(Function->GetFullName(), "Function SFXGame.BioHUD.PostRender"))
	{
		if (!hud)
		{
			hud = new ExtraContentHUD{ !GIsRelease };
		}
		hud->Update(((ABioHUD*)Context)->Canvas, GExtraContent);
		hud->Draw();
	}


	// Allow toggling the autoload profiler HUD on `profile autoload` command.
	if (!strcmp(Function->GetFullName(), "Function Console.Typing.InputChar") && Parms && hud)
	{
		auto sfxConsole = reinterpret_cast<UConsole*>(Context);
		auto inputParms = reinterpret_cast<UConsole_execInputChar_Parms*>(Parms);
		if (inputParms->Unicode.Count >= 1 && inputParms->Unicode.Data[0] == L'\r'
			&& sfxConsole->TypedStr.Data
			&& !wcsncmp(sfxConsole->TypedStr.Data, L"profile ", 8))
		{
			hud->SetVisible(!wcscmp(sfxConsole->TypedStr.Data, L"profile autoload"));
		}
	}

	ProcessEvent_orig(Context, Function, Parms, Result);
}

#endif

#pragma region CacheContent
// ======================================================================
// ISB Registration
// ======================================================================

// List of found ISBs that will register on first ISB registration
std::vector<wchar_t*> ISBsToRegister;

typedef void (*tCachePackage)(long long parm1, wchar_t* filePath, bool replaceIfExisting, bool warnIfExists);
tCachePackage CacheContentWrapper = nullptr;
tCachePackage CacheContentWrapper_orig = nullptr;

bool registeredISBs = false;
void CacheContentWrapper_hook(long long parm1, wchar_t* filePath, bool replaceIfExisting, bool warnIfExists)
{
	if (!registeredISBs)
	{
		registeredISBs = true;
		for each (auto isb in ISBsToRegister)
		{
			writeln(L"Registering DLC mod ISB %s", isb);
			CacheContentWrapper_orig(parm1, isb, true, false);
			delete isb; // IDK if this is accurate...
		}
	}
	CacheContentWrapper_orig(parm1, filePath, replaceIfExisting, warnIfExists);
}

#pragma endregion CacheContent

#pragma region FirstLoad
// ======================================================================
// This method is called when files are opened for reading (it seems).
// Core.pcc is the first invocation, which means TFCs should have been registered by now
// so textures don't try to load before TFCs are available
// ======================================================================

typedef void* (*tSomethingFirstLoad)(long long* parm1, void* parm2, wchar_t** parm3, void* parm4);
tSomethingFirstLoad SomethingFirstLoad = nullptr;
tSomethingFirstLoad SomethingFirstLoad_orig = nullptr;
int numFilesRead = 0;
bool firstLoad = true;

void* SomethingFirstLoad_hook(long long* parm1, void* parm2, wchar_t** filePath, void* parm4)
{
	if (firstLoad)
	{
		firstLoad = false;

		// Wait up to 5 seconds.
		int i = 5;
		while (i > 0 && !ContentScanComplete)
		{
			writeln(L"Waiting for content scan to complete...");
			std::this_thread::sleep_for(std::chrono::seconds(1));
			i--;
		}

		if (i == 0 && !ContentScanComplete)
		{
			writeln(L"Content scan took too long, giving up waiting");
		}

		writeln(L"Performing TFC registration");
		for each (auto tfcPath in DLCTFCsToRegister)
		{
			RegisterTFCWrapper(tfcPath);
		}
	}

	// This call seems to be for when files are opened for reading (CreateFileW is called). This happens a lot with things like TFC reading but first hit is Core.pcc
	return SomethingFirstLoad_orig(parm1, parm2, filePath, parm4);
}

#pragma endregion FirstLoad

// ======================================================================

SPI_IMPLEMENT_ATTACH
{
	initLog();

	// Find RegisterTFC so we can register TFCs
	INIT_FIND_PATTERN_POSTHOOK(RegisterTFC, /*48 8b c4 57 41*/ "56 41 57 48 83 ec 60 48 c7 40 a8 fe ff ff ff 48 89 58 10 48 89 68 18 48 89 70 20 4c 8b f9 48 8b 0d 6e 3e 45 01 48 8b 01 48 8d 2d b0 9d d4 00 41 83 7f 08 00 74 05 49 8b 17 eb 03");

	// Leftover for documentation sake.
	// We need to find 'Has at least one TFC' which I think means TFC manager has loaded...
	//INIT_FIND_PATTERN_POSTHOOK(HasAtLeastOneBasegameTFC, /* 8b 0d aa a6 50 */ "01 33 c0 2b 0d ce a6 50 01 85 c9 0f 9f c0 c3"); // dunno if this is long enough

	INIT_FIND_PATTERN_POSTHOOK(CacheContentWrapper, /*48 8b c4 55 41*/ "54 41 55 41 56 41 57 48 8d 68 a1 48 81 ec 00 01 00 00 48 c7 45 27 fe ff ff ff 48 89 58 08 48 89 70 10 48 89 78 18 45 8b e9");
	INIT_HOOK_PATTERN(CacheContentWrapper); // For ISB registration

	// This method is called initially when Core.pcc loads
	INIT_FIND_PATTERN_POSTHOOK(SomethingFirstLoad, /*48 8b c4 56 57*/ "41 54 41 56 41 57 48 83 ec 50 48 c7 40 a8 fe ff ff ff 48 89 58 10 48 89 68 18 4d 8b f0 48 8b f2");
	INIT_HOOK_PATTERN(SomethingFirstLoad);

	// Initialize the SDK because we need object names.
	INIT_CHECK_SDK();

	// This is done first cause it's kind of important that it's done early so changes to things like
	// BIOC_Materials work

	// Get a list of DLC Autoloads.
	writeln(L"Finding DLC content...");
	for (const auto& autoload : GetAllDLCAutoloads(GetDLCsRoot()))
	{
		writeln(L"Found DLC Autoload.ini: %s", autoload.c_str());
		GExtraAutoloadPaths.push_back(autoload.c_str());

		// It's a DLC mod, LE only has a single autoload.ini (Bring Down The Sky)
		std::filesystem::path path = autoload.c_str();
		auto dlcFolder = path.parent_path();

		for (const auto& entry : std::filesystem::recursive_directory_iterator(dlcFolder))
		{
			if (entry.is_directory())
			{
				writeln(L"\tScanning %s", entry.path().c_str());
				continue;
			}

			// _wcsdup might leak memory but not much. Freeing it upon consumption crashes the app so...
			auto extension = entry.path().extension();
			if (extension == L".tfc") {
				auto path = entry.path().c_str();
				writeln(L"\t\tFound TFC: %s", path);
				DLCTFCsToRegister.push_back(new FString(_wcsdup(path))); // We have to wait until first registration attempt or we'll hit a null pointer
			}
			else if (extension == ".isb")
			{
				// Register ISB
				auto path = entry.path().c_str();
				writeln(L"\t\tFound ISB: %s", path);
				ISBsToRegister.push_back(_wcsdup(path)); // We have to wait until first registration attempt or we'll hit a null pointer
			}
		}
	}
	ContentScanComplete = true;
	writeln(L"Completed DLC content detection");

	// Hook stuff that won't be needed until like 10-15 seconds into the game

#if !NDEBUG
	// Hook ProcessEvent for debugging.
	INIT_FIND_PATTERN_POSTHOOK(ProcessEvent, LE_PATTERN_POSTHOOK_PROCESSEVENT);
	INIT_HOOK_PATTERN(ProcessEvent);
#endif

	// Find and hook the ProcessIni for Autoload.ini support
	INIT_FIND_PATTERN_POSTHOOK(ProcessIni, /*"40 55 56 57 41*/ "54 41 55 41 56 41 57 48 8D AC 24 A0 EC FF FF B8 60 14 00 00");
	INIT_HOOK_PATTERN(ProcessIni);

	INIT_FIND_PATTERN_POSTHOOK(InstallDownloadableContent, /*"48 8b c4 55 41*/ "54 41 55 41 56 41 57 48 8d a8 98 fe ff ff 48 81 ec 40 02 00 00 48 c7 45 18 fe ff ff ff");
	INIT_HOOK_PATTERN(InstallDownloadableContent);

	// OBJECT ROOTING FOR STARTUP FILE OBJECTS
	// NOTE: THIS POINTS TO A FUNCTION FOLLOWING BY 0X10 AS THE FUNC IS TOO SMALL TO FIND BY SIGNATURE
	INIT_FIND_PATTERN_POSTHOOK(RootObject, /*"40 55 48 8b ec*/"48 83 ec 50 48 c7 45 e0 fe ff ff ff 48 89 5c 24 60");
	//writeln("RootObject currently at 0x%p", RootObject);
	RootObject = (tUObjectRoot)((char*)RootObject - 0x10);
	//writeln("Actual RootObject is at 0x%p", RootObject);


	return true;
}

SPI_IMPLEMENT_DETACH
{
	closeLog();
	return true;
}