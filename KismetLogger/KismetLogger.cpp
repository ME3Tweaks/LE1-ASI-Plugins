#include <stdio.h>
#include <io.h>
#include <string>
#include <fstream>
#include <iostream>
#include <ostream>
#include <streambuf>
#include <sstream>
#include "../Interface.h"
#include "../Common.h"
#include "../SDK/LE1SDK/SdkHeaders.h"
#include "../ME3TweaksHeader.h"

#define MYHOOK "KismetLogger_"

SPI_PLUGINSIDE_SUPPORT(L"KismetLogger", L"2.0.0", L"HenBagle", SPI_GAME_LE1, SPI_VERSION_ANY);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

ME3TweaksASILogger logger("Kismet Logger v2", "KismetLog.txt");



// ProcessEvent hook
// ======================================================================

typedef void (*tProcessEvent)(UObject* Context, UFunction* Function, void* Parms, void* Result);
tProcessEvent ProcessEvent = nullptr;

tProcessEvent ProcessEvent_orig = nullptr;
void ProcessEvent_hook(UObject* Context, UFunction* Function, void* Parms, void* Result)
{
    if(!strcmp(Function->GetFullName(), "Function Engine.SequenceOp.Activated"))
    {
        const auto op = reinterpret_cast<USequenceOp*>(Context);
        char* fullInstancedPath = op->GetFullPath();
        char* className = op->Class->Name.GetName();
		logger.writeToLog(string_format("%s %s\n", className, fullInstancedPath), true);
    }
    ProcessEvent_orig(Context, Function, Parms, Result);
}


SPI_IMPLEMENT_ATTACH
{
    Common::OpenConsole();

    auto _ = SDKInitializer::Instance();
    writeln(L"Attach - names at 0x%p, objects at 0x%p",
        SDKInitializer::Instance()->GetBioNamePools(),
        SDKInitializer::Instance()->GetObjects());

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
