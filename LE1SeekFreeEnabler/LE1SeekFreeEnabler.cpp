#include <shlwapi.h>
#include <psapi.h>
#include <string>
#include <fstream>
#include <iostream>
#include <ostream>
#include <streambuf>
#include <sstream>
#include "Header.h"

#define SEEKFREEHOOK "LE1SeekFreeEnabler_"

SPI_PLUGINSIDE_SUPPORT(L"LE1SeekFreeEnabler", L"Mgamerz", L"1.0.0", SPI_GAME_LE1, SPI_VERSION_LATEST);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;


// ======================================================================


// ProcessEvent hook
// Renders the HUD for Streaming Levels
// ======================================================================


// THIS IS WIP DEMO PROJECT
// Will probably get merged into AutoLoad enabler

typedef void (*tProcessEvent)(UObject* Context, UFunction* Function, void* Parms, void* Result);
tProcessEvent ProcessEvent = nullptr;
tProcessEvent ProcessEvent_orig = nullptr;

bool listenHook = true;
int callsRemaining = 500;


void printArray(TArray<FString> data)
{
	for (int i = 0; i < data.Count; i++)
	{
		fwprintf_s(stdout, data.Data[i].Data);
		fwprintf_s(stdout, L"\n");
	}
}

void saveInitHook(UObject* Context, UFunction* Function, void* Parms, void* Result)
{
	if (listenHook && !strcmp(Function->GetFullName(), "Function SFXGame.SFXEngine.ScanSaveDataComplete"))
	{
		auto system = (USystem*) FindObjectOfType(USystem::StaticClass());

		if (system != nullptr) {
			std::cout << "SeekFreePCPaths:\n";
			std::cout << "Count: " << system->SeekFreePCPaths.Count << "\n";
			printArray(system->SeekFreePCPaths);

			std::cout << "Paths:\n";
			std::cout << "Count: " << system->Paths.Count << "\n";
			printArray(system->Paths);
		}
		listenHook = false;
	}

	ProcessEvent_orig(Context, Function, Parms, Result);
}

// ======================================================================


SPI_IMPLEMENT_ATTACH
{
	Common::OpenConsole();

	auto _ = SDKInitializer::Instance();
	/*writeln(L"Attach - names at 0x%p, objects at 0x%p",
		SDKInitializer::Instance()->GetBioNamePools(),
		SDKInitializer::Instance()->GetObjects());*/

	if (auto rc = InterfacePtr->FindPattern((void**)&ProcessEvent, "40 55 41 56 41 57 48 81 EC 90 00 00 00 48 8D 6C 24 20");
		rc != SPIReturn::Success)
	{
		//writeln(L"Attach - failed to find ProcessEvent pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}

	if (auto rc = InterfacePtr->InstallHook(SEEKFREEHOOK "ProcessEvent", ProcessEvent, saveInitHook, (void**)&ProcessEvent_orig);
		rc != SPIReturn::Success)
	{
		//writeln(L"Attach - failed to hook ProcessEvent: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}

	return true;
}

SPI_IMPLEMENT_DETACH
{
	Common::CloseConsole();
	return true;
}
