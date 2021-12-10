#include "../LE1-SDK/Interface.h"
#include "../LE1-SDK/Common.h"
#include "../LE1-SDK/SdkHeaders.h"


#define MYHOOK "LE1MedigelTest_"

SPI_PLUGINSIDE_SUPPORT(L"LE1MedigelTest", L"0.1.0", L"HenBagle", SPI_GAME_LE1, 2);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;


struct FFrame {
    void*            VfPtr;            // =0x00
    DWORD            Unknown08;        // +0x08
    DWORD            Unknown0C;        // +0x0C
    DWORD            Unknown10;        // +0x10
    class UStruct*        Node;            // +0x14
    class UObject*        Object;            // +0x1C
    BYTE*            Code;            // +0x24
    BYTE*            Locals;            // +0x2C
    struct FFrame*        PreviousFrame;    // +0x34
};


// ProcessEvent hook
// ======================================================================

typedef void (*tProcessEvent)(UObject* Context, UFunction* Function, void* Parms, void* Result);
tProcessEvent ProcessEvent = nullptr;

tProcessEvent ProcessEvent_orig = nullptr;
void ProcessEvent_hook(UObject* Context, UFunction* Function, void* Parms, void* Result)
{
    if(!strcmp(Function->GetFullName(), "Function SFXGame.BioSFHandler_PCHUD.HandleEvent"))
    {
        auto inputParms = reinterpret_cast<UBioSFHandler_PCHUD_execHandleEvent_Parms*>(Parms);
        if(inputParms->nCommand == 20)
        {
            writeln("Medigel button triggered!");
        }
    }
    ProcessEvent_orig(Context, Function, Parms, Result);
}

// ======================================================================

// CallFunction hook
// ======================================================================
typedef void (*tCallFunction) (UObject* Context, FFrame* Stack, void* Result, UFunction* Function);
tCallFunction CallFunction = nullptr;

tCallFunction CallFunction_orig = nullptr;
void CallFunction_hook(UObject* Context, FFrame* Stack, void* Result, UFunction* Function)
{
    if(!strcmp(Function->GetFullName(), "Function SFXGame.BioSFHandler_PCHUD.HandleEvent"))
    {
        writeln("Function Called!");
    }
    CallFunction_orig(Context, Stack, Result, Function);
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


    if (auto rc = InterfacePtr->FindPattern((void**)&CallFunction, "40 55 53 56 57 41 54 41 55 41 56 41 57 48 81 EC A8 04 00 00 48 8D 6C 24 20 48 C7 45 68 FE FF FF FF"); 
        rc != SPIReturn::Success)
    {
        writeln(L"Attach - failed to find CallFunction pattern: %d / %s", rc, SPIReturnToString(rc));
        return false;
    }

    if (auto rc = InterfacePtr->InstallHook(MYHOOK "CallFunction", CallFunction, CallFunction_hook, (void**)&CallFunction_orig); 
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
