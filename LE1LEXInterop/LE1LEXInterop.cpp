#include <stdio.h>
#include <io.h>
#include <string>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <map>
#include <optional>
#include <ostream>
#include <streambuf>
#include <shlwapi.h>
#include <sstream>
#include "Strsafe.h"

// Game: LE1
#define GAMELE1

// To build this, you need to use the LEASIMods repo so these shared files are available
#include "..\\..\\Shared-ASI\\LEXInterop\\LEXInterop.h"

// Featureset
#include <thread>



#pragma comment(lib, "shlwapi.lib")

SPI_PLUGINSIDE_SUPPORT(L"LE1 LEX Interop", L"2.0.0", L"ME3Tweaks", SPI_GAME_LE1, SPI_VERSION_ANY);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

TCHAR SplashPath[MAX_PATH];
HANDLE hPipe;
LPOVERLAPPED pipeOverlap;

#pragma region TLKLookup
// TLK lookups to keys in this map will return the data by their key instead of their original data.
// This does NOT support interpolation
map<int, FString> tlkOverride;

// LE1 Specific: Message notifications in-game
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
	if (stringID == TLK_STRID_GPS)
	{
		writeln(L"HIT");
	}
	map<int, FString>::iterator it = tlkOverride.find(stringID);
	if (it != tlkOverride.end())
	{
		//element found;
		return &it->second;
	}

	return TLKLookup_orig(param1, outString, stringID, bParse);

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

#pragma endregion TLKLookup

// ProcessEvent hook
// ======================================================================

typedef void (*tProcessEvent)(UObject* Context, UFunction* Function, void* Parms, void* Result);
tProcessEvent ProcessEvent = nullptr;

tProcessEvent ProcessEvent_orig = nullptr;
void ProcessEvent_hook(UObject* Context, UFunction* Function, void* Parms, void* Result)
{
	// ProcessEvent calls return true or false if the following functions should also handle
	// the call (to increase perf)
	// Implementations should take care to allow follow up invocations if it might be appropriate
	// This is a debug tool; performance loss is to be expected

	SharedData::ProcessEvent(Context, Function, Parms, Result); // Update the shared data automatically

	bool continueChecking = LEXCommunications::ProcessEvent(Context, Function, Parms, Result);
	if (continueChecking) continueChecking = LEPathfindingGPS::ProcessEvent(Context, Function, Parms, Result);
	if (continueChecking) continueChecking = LELiveLevelEditor::ProcessEvent(Context, Function, Parms, Result);
	if (continueChecking) continueChecking = LEAnimViewer::ProcessEvent(Context, Function, Parms, Result);

	ProcessEvent_orig(Context, Function, Parms, Result);
}


// Note: Doesn't work. Game doesn't show notification
void sendInGameNotification(wchar_t* shortMessage, int tlkIDToUse)
{
	auto bioWorldInfo = reinterpret_cast<ABioWorldInfo*>(FindObjectOfType(ABioWorldInfo::StaticClass()));
	if (bioWorldInfo && bioWorldInfo->EventNotifier)
	{
		tlkOverride.insert_or_assign(tlkIDToUse, FString(shortMessage));
		bioWorldInfo->EventNotifier->AddNotice(1, 3, 10000, 2, tlkIDToUse, L"Level Up!", 0, 0, 0);
	}
}





SPI_IMPLEMENT_ATTACH
{
	Common::OpenConsole();

	auto _ = SDKInitializer::Instance();

	// Cache the pointer so we can install a hook later (if needed)
	SharedData::SPIInterfacePtr = InterfacePtr;

	INIT_FIND_PATTERN_POSTHOOK(ProcessEvent, /* 40 55 41 56 41 */ "57 48 81 EC 90 00 00 00 48 8D 6C 24 20");
	INIT_HOOK_PATTERN(ProcessEvent);

	// LE1: Override TLK for user notification
	INIT_FIND_PATTERN_POSTHOOK(TLKLookup, /*"48 89 54 24 10*/ "56 57 41 56 48 83 ec 30 48 c7 44 24 28 fe ff ff ff 48 89 5c 24 50 48 89 6c 24 60 45 8b f1 41 8b e8 48 8b da 48 8b f1 33 c0 89 44 24 20 48 89 02 48 89 42 08 c7 44 24 20 01 00 00 00");
	INIT_HOOK_PATTERN(TLKLookup);

	// Used to dynamically register a package
	// This is hooked so we can capture the first parameter address
	INIT_FIND_PATTERN_POSTHOOK(CacheContentWrapper, /*48 8b c4 55 41*/ "54 41 55 41 56 41 57 48 8d 68 a1 48 81 ec 00 01 00 00 48 c7 45 27 fe ff ff ff 48 89 58 08 48 89 70 10 48 89 78 18 45 8b e9");
	INIT_FIND_PATTERN_POSTHOOK(CacheContent, /*"48 8b c4 44 89"*/ "48 20 44 89 40 18 55 56 57 41 54 41 55 41 56 41 57 48 8d 68 a1 48 81 ec a0 00 00 00");
	INIT_HOOK_PATTERN(CacheContentWrapper); // For ISB registration

	// I'm not sure how this handles the scope
	writeln("Making pipe thread");
	std::thread pipeThread(HandlePipe);
	writeln("Detaching pipe thread");
	pipeThread.detach();
	writeln("Initialized LE1LEXInterop");
	return true;
}

SPI_IMPLEMENT_DETACH
{
	Common::CloseConsole();
	return true;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID) {
	if (reason == DLL_PROCESS_ATTACH)
	{
		//GetModuleFileName(hModule, SplashPath, MAX_PATH);
		//PathRemoveFileSpec(SplashPath);
		//PathRemoveFileSpec(SplashPath);
		//StringCchCat(SplashPath, MAX_PATH, L"\\ME3ExpActorDump.txt");
	}

	return TRUE;
}
