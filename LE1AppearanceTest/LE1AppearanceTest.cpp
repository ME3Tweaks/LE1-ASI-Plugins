#include <string>

#include "AppearanceHUD.h"
#include "../../Shared-ASI/Interface.h"
#include "../../Shared-ASI/Common.h"
#include "../../Shared-ASI/ME3Tweaks/ME3TweaksHeader.h"
#include "../../Shared-ASI/ConsoleCommandParsing.h"


#define MYHOOK "HBTesting_"

SPI_PLUGINSIDE_SUPPORT(L"HBTesting", L"1.0.0", L"HenBagle", SPI_GAME_LE1, 2);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

AppearanceHUD* customHud = new AppearanceHUD;

// ======================================================================
// ExecHandler hook
// ======================================================================

typedef unsigned (*tExecHandler)(UEngine* Context, wchar_t* cmd, void* unk);
tExecHandler ExecHandler = nullptr;
tExecHandler ExecHandler_orig = nullptr;
unsigned ExecHandler_hook(UEngine* Context, wchar_t* cmd, void* unk)
{
    if (ExecHandler_orig(Context, cmd, unk))
    {
        return TRUE;
    }
	if (IsCmd(&cmd, L"appearance"))
	{
        customHud->ShouldDraw = !customHud->ShouldDraw;
        return TRUE;
	}
    return FALSE;
}

ABioPawn* GetPlayer(AWorldInfo* worldInfo)
{
    if (!worldInfo) return nullptr;
    auto bioWorldInfo = (ABioWorldInfo*)worldInfo;
    auto pc = bioWorldInfo->LocalPlayerController;
    if (!pc) return nullptr;
    auto player = pc->Pawn;
    if (!player || !player->IsA(ABioPawn::StaticClass())) return nullptr;
    else return static_cast<ABioPawn*>(player);
}

// ProcessEvent hook
// ======================================================================

typedef void (*tProcessEvent)(UObject* Context, UFunction* Function, void* Parms, void* Result);
tProcessEvent ProcessEvent = nullptr;
tProcessEvent ProcessEvent_orig = nullptr;

void ProcessEvent_hook(UObject* Context, UFunction* Function, void* Parms, void* Result)
{
    static AppearanceHUD* hud = nullptr;
    if (!strcmp(Function->GetFullName(), "Function SFXGame.BioHUD.PostRender"))
    {
        auto biohud = reinterpret_cast<ABioHUD*>(Context);
        if (biohud != nullptr)
        {
            customHud->Update(((ABioHUD*)Context)->Canvas, GetPlayer(biohud->WorldInfo));
            customHud->Draw();
        }
    }
    ProcessEvent_orig(Context, Function, Parms, Result);
}


SPI_IMPLEMENT_ATTACH
{
    Common::OpenConsole();

	INIT_CHECK_SDK()

    INIT_FIND_PATTERN_POSTHOOK(ProcessEvent, /* 40 55 41 56 41 */ "57 48 81 EC 90 00 00 00 48 8D 6C 24 20");
    if (auto rc = InterfacePtr->InstallHook(MYHOOK "ProcessEvent", ProcessEvent, ProcessEvent_hook, (void**)&ProcessEvent_orig);
        rc != SPIReturn::Success)
    {
        writeln(L"Attach - failed to hook ProcessEvent: %d / %s", rc, SPIReturnToString(rc));
        return false;
    }

    if (const auto rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&ExecHandler), "48 8b c4 48 89 50 10 55 56 57 41 54 41 55 41 56 41 57 48 8d a8 d8 fe ff ff");
        rc != SPIReturn::Success)
    {
        writeln(L"Attach - failed to find ExecHandler pattern: %d / %s", rc, SPIReturnToString(rc));
        return false;
    }
    if (const auto rc = InterfacePtr->InstallHook(MYHOOK "ExecHandler", ExecHandler, ExecHandler_hook, reinterpret_cast<void**>(&ExecHandler_orig));
        rc != SPIReturn::Success)
    {
        writeln(L"Attach - failed to hook ExecHandler: %d / %s", rc, SPIReturnToString(rc));
        return false;
    }

    return true;
}

SPI_IMPLEMENT_DETACH
{
    Common::CloseConsole();
    return true;
}
