#include <stdio.h>
#include <io.h>
#include <string>
#include <fstream>
#include "../Interface.h"
#include "../Common.h"
#include "../ME3TweaksHeader.h"

SPI_PLUGINSIDE_SUPPORT(L"SelfDebugger", L"1.0.0", L"ME3Tweaks", SPI_GAME_LE1 | SPI_GAME_LE2 | SPI_GAME_LE3, SPI_VERSION_ANY);
SPI_PLUGINSIDE_PRELOAD;
SPI_PLUGINSIDE_SEQATTACH;

ME3TweaksASILogger logger("Self Debugger v1", "SelfDebuggerLog.txt");

// Original Func
typedef void (WINAPI * tOutputDebugStringW)(LPCWSTR lpcszString);
tOutputDebugStringW OutputDebugStringW_Orig = nullptr;

// Our replacement
void WINAPI OutputDebugStringW_Hook(LPCWSTR lpcszString)
{
    OutputDebugStringW_Orig(lpcszString);
    writeln(L"%s", lpcszString);
    logger.writeWideLineToLog(std::wstring_view{ lpcszString });
}

SPI_IMPLEMENT_ATTACH
{
    Common::OpenConsole();
	writeln(L"Initializing selfdebugger...");

    if (auto rc = InterfacePtr->InstallHook("OutputDebugStringW", (void*)OutputDebugStringW, (void*)OutputDebugStringW_Hook, (void**)&OutputDebugStringW_Orig);
        rc != SPIReturn::Success)
    {
        writeln(L"Attach - failed to hook ProcessEvent: %d / %s", rc, SPIReturnToString(rc));
        return false;
    }
    writeln(L"Initialized selfdebugger");
    return true;
}


SPI_IMPLEMENT_DETACH
{
	//DebugActiveProcessStop(GetCurrentProcessId());
	Common::CloseConsole();
	return true;
}
