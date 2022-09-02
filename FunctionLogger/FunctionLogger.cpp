#include <fstream>
#include <iostream>
#include <cstdio>

#define GAMELE1

#include "../../Shared-ASI/Common.h"
#include "../../Shared-ASI/Interface.h"
#include "../../Shared-ASI/ME3Tweaks/ME3TweaksHeader.h"

#define MYHOOK "KismetLogger_"

SPI_PLUGINSIDE_SUPPORT(L"FunctionLogger", L"2.0.0", L"Mgamerz", SPI_GAME_LE1, SPI_VERSION_ANY);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

ME3TweaksASILogger logger("Function Logger v2", "LE1FunctionLog.log");



// ProcessEvent hook
// ======================================================================

typedef void (*tProcessEvent)(UObject* Context, UFunction* Function, void* Parms, void* Result);
tProcessEvent ProcessEvent = nullptr;

tProcessEvent ProcessEvent_orig = nullptr;
void ProcessEvent_hook(UObject* Context, UFunction* Function, void* Parms, void* Result)
{
	const auto szName = Function->GetFullName();
    logger.writeToLog(string_format("%s\n", szName), true);
    logger.flush();
    ProcessEvent_orig(Context, Function, Parms, Result);
}


SPI_IMPLEMENT_ATTACH
{
    Common::OpenConsole();

	INIT_CHECK_SDK()
    writeln(L"Crash game as soon as possible in order to keep log size down");

    INIT_FIND_PATTERN_POSTHOOK(ProcessEvent, /* 40 55 41 56 41 */ "57 48 81 EC 90 00 00 00 48 8D 6C 24 20");
    if (auto rc = InterfacePtr->InstallHook(MYHOOK "ProcessEvent", ProcessEvent, ProcessEvent_hook, (void**)&ProcessEvent_orig); 
        rc != SPIReturn::Success)
    {
        writeln(L"Attach - failed to hook ProcessEvent: %d / %s", rc, SPIReturnToString(rc));
        return false;
    }

    return true;
}

SPI_IMPLEMENT_DETACH
{
    Common::CloseConsole();
    return true;
}
