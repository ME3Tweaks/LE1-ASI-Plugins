// This project was forked from d00telemental's LE1AutoloadEnabler repository on 02/03/2022: https://github.com/d00telemental/LENativeExperiments
// due to difficulty building project from that repo and extensions made in this one

#include <filesystem>
#include <Shlwapi.h>
#include <vector>
#include <Windows.h>
#include "../LE1-SDK/Interface.h"
#include "../LE1-SDK/Common.h"
#include "../LE1-SDK/SdkHeaders.h"
#include "ExtraContent.h"
#include "Logging.h"

#define MYHOOK "LE1AutoloadIniLogger_"
#ifndef NDEBUG
constexpr bool GIsRelease = false;
#else
constexpr bool GIsRelease = true;
#endif

SPI_PLUGINSIDE_SUPPORT(L"LE1AutoloadIniLogger", L"---", L"0.3.0", SPI_GAME_LE1, SPI_VERSION_LATEST);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;


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

// RegisterTFC prototype so we can call it when necessary
// =====================================================================
typedef void (*tRegisterTFC)(FString* name);
tRegisterTFC RegisterTFC = nullptr;
tRegisterTFC RegisterTFC_orig = nullptr;

std::vector<FString*> DLCTFCsToRegister;
bool registeredFirstTFC = false;

// Logs a message and registers a TFC
void RegisterTFCWrapper(FString* tfcPath)
{
	writeln(L"Registering DLC mod TFC file: %s", tfcPath->Data);
	RegisterTFC_orig(tfcPath);
	free(tfcPath->Data); // Data consturcted here was made with _wcsdup
}

void RegisterTFC_hook(FString* tfc)
{
	if (!registeredFirstTFC)
	{
		registeredFirstTFC = true;
		for each (FString* tfcPath in DLCTFCsToRegister)
		{
			RegisterTFCWrapper(tfcPath);
		}
	}
	RegisterTFC_orig(tfc);
}

// ProcessIni hook
// Logs every invocation, call itself for each found Autoload.ini.
// ======================================================================

bool GOriginalCalled = false;
ExtraContent* GExtraContent = nullptr;
std::vector<std::wstring> GExtraAutoloadPaths{};

// NI: The first param is actually a class pointer.
typedef void (*tProcessIni)(ExtraContent* ExtraContent, FString* IniPath, FString* BasePath);
tProcessIni ProcessIni = nullptr;
tProcessIni ProcessIni_orig = nullptr;
void ProcessIni_hook(ExtraContent* ExtraContent, FString* IniPath, FString* BasePath)
{
	writeln(L"ProcessIni - ExtraContent = %p, IniPath is %s", ExtraContent, IniPath->Data);
	ProcessIni_orig(ExtraContent, IniPath, BasePath);

	if (!GOriginalCalled)
	{
		GOriginalCalled = true;
		for (const auto& autoloadPath : GExtraAutoloadPaths)
		{
			ProcessIni(ExtraContent, &FString{ const_cast<wchar_t*>(autoloadPath.c_str()) }, nullptr);
		}
		GExtraContent = ExtraContent;
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

// ======================================================================

SPI_IMPLEMENT_ATTACH
{
		initLog();
		//writeln(L"Attach - hello there!");

		// Find RegisterTFC so we can register TFCs
		// As TFCs are one of the first things loaded this must be done ASAP
		INIT_FIND_PATTERN_POSTHOOK(RegisterTFC, /*48 8b c4 57 41*/ "56 41 57 48 83 ec 60 48 c7 40 a8 fe ff ff ff 48 89 58 10 48 89 68 18 48 89 70 20 4c 8b f9 48 8b 0d 6e 3e 45 01 48 8b 01 48 8d 2d b0 9d d4 00 41 83 7f 08 00 74 05 49 8b 17 eb 03");
		INIT_HOOK_PATTERN(RegisterTFC); // We will load our TFCs first

#ifndef NDEBUG
		// Initialize the SDK because we need object names.
		INIT_CHECK_SDK();

		// Hook ProcessEvent for debugging.
		INIT_FIND_PATTERN(ProcessEvent, "40 55 41 56 41 57 48 81 EC 90 00 00 00 48 8D 6C 24 20");
		INIT_HOOK_PATTERN(ProcessEvent);
#endif

		// Find and hook the ProcessIni.
		INIT_FIND_PATTERN(ProcessIni, "40 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 A0 EC FF FF B8 60 14 00 00");
		INIT_HOOK_PATTERN(ProcessIni);

		// Get a list of DLC Autoloads.

		for (const auto& autoload : GetAllDLCAutoloads(GetDLCsRoot()))
		{
			writeln(L"Attach - found a DLC autoload: %s", autoload.c_str());
			GExtraAutoloadPaths.push_back(autoload.c_str());

			// It's a DLC mod, LE only has a single autoload.ini (Bring Down The Sky)
			std::filesystem::path path = autoload.c_str();
			auto dlcFolder = path.parent_path();
			for (const auto& entry : std::filesystem::recursive_directory_iterator(dlcFolder))
			{
				if (entry.is_directory())
					continue;

				if (entry.path().extension() == L".tfc") {
					// Due to startup timing issues we have to do this
					if (registeredFirstTFC)
					{
						// This one won't be in list so we have to register it now.
						RegisterTFCWrapper(new FString(_wcsdup(entry.path().c_str())));
					}
					else
					{
						DLCTFCsToRegister.push_back(new FString(_wcsdup(entry.path().c_str()))); // We have to wait until first registration attempt or we'll hit a null pointer
					}
				}
			}
		}
	return true;
}

SPI_IMPLEMENT_DETACH
{
	closeLog();
	return true;
}