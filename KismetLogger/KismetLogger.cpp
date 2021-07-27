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

SPI_PLUGINSIDE_SUPPORT(L"KismetLogger", L"1.0.0", L"HenBagle", SPI_GAME_LE1, SPI_VERSION_ANY);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

ME3TweaksASILogger logger("Kismet Logger v1", "KismetLog.txt");

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
        char* name = op->Name.GetName();
        std::string fpstring = op->GetFullPath();
		char* packagename = op->GetPackageName().GetName();
        int index = op->Name.Number;

        // This is a cheap hack because GetFullPath returns the proper instanced name (where 1 is name_0) and kismet logger doesn't want that
        // This was easier to change. This will break if you have a _1000
        std::size_t found = fpstring.find_last_of('_');
        if(found >= fpstring.size() - 4) fpstring.erase(found);

		logger.writeToLog(string_format("(%s) %s %s_%i\n", packagename, name, fpstring.data(), index), true);
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

    if (auto rc = InterfacePtr->FindPattern((void**)&ProcessEvent, "40 55 41 56 41 57 48 81 EC 90 00 00 00 48 8D 6C 24 20"); 
        rc != SPIReturn::Success)
    {
        writeln(L"Attach - failed to find ProcessEvent pattern: %d / %s", rc, SPIReturnToString(rc));
        return false;
    }


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
