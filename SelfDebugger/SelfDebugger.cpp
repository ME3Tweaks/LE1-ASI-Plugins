#include <stdio.h>
#include <io.h>
#include <string>
#include <fstream>
#include "../Interface.h"
#include "../Common.h"
#include "../ME3TweaksHeader.h"

SPI_PLUGINSIDE_SUPPORT(L"SelfDebugger", L"1.0.0", L"ME3Tweaks", SPI_GAME_LE1 | SPI_GAME_LE2 | SPI_GAME_LE3, SPI_VERSION_ANY);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

//ME3TweaksASILogger logger("Self Debugger v1", "SelfDebuggerLog.txt");

// Original Func
VOID(WINAPI* _OutputDebugStringW)(__in_z_opt LPCWSTR lpcszString) = OutputDebugStringW;
typedef void (*tOutputDebugStringW)(__in_z_opt LPCWSTR lpcszString);
tOutputDebugStringW OutputDebugStringW_Orig = OutputDebugStringW;

// Our replacement
VOID WINAPI OutputDebugStringHook(__in_z_opt LPCWSTR lpcszString)
{
	// do something with the string, like write to file
    //cout << lpcszString;
    //cout << "\n";
	//writeln(lpcszString);
}

SPI_IMPLEMENT_ATTACH
{
    Common::OpenConsole();
	writeln(L"Initializing selfdebugger...");

    if (auto rc = InterfacePtr->InstallHook("OutputDebugStringW", OutputDebugStringW_Orig, OutputDebugStringHook, (void**)OutputDebugStringW); rc != SPIReturn::Success)
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
