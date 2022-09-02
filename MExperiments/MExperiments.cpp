#include <cstdio>
#include <io.h>
#include <string>
#include <fstream>
#include <iostream>
#include <ostream>
#include <random>
#include <streambuf>
#include <sstream>

#define GAMELE1

#include "../../Shared-ASI/Common.h"
#include "../../Shared-ASI/Interface.h"
#include "../../Shared-ASI/ME3Tweaks/ME3TweaksHeader.h"

#define MYHOOK "MExperiments_"

SPI_PLUGINSIDE_SUPPORT(L"MExperiments", L"1.0.0", L"Mgamerz", SPI_GAME_LE1, SPI_VERSION_ANY);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

//ME3TweaksASILogger logger("MExperiments v1", "FunctionLog.txt");



// ProcessEvent hook
// ======================================================================

typedef void (*tProcessEvent)(UObject* Context, UFunction* Function, void* Parms, void* Result);
tProcessEvent ProcessEvent = nullptr;

static std::default_random_engine e;
static uniform_real_distribution<> dis(0, 1); // rage 0 - 1

tProcessEvent ProcessEvent_orig = nullptr;
void ProcessEvent_hook(UObject* Context, UFunction* Function, void* Parms, void* Result)
{
    auto szName = Function->GetFullName();
	if (!strcmp(szName, "Function SFXGame.BioHUD.PostRender"))
	{
        auto materials = FindObjectsOfType(UMaterial::StaticClass());
		if (materials.Any())
		{
            writeln("doing stuff");
		}
        for (int i = 0; i < materials.Count; i++)
		{
            auto mat = reinterpret_cast<UMaterial*>(materials.Data[i]);
        	if (mat->Expressions.Any())
        	{
        		for (int j = 0; j < mat->Expressions.Count; j++)
        		{
                    auto matExp = mat->Expressions.Data[j];
        			if (matExp->IsA(UMaterialExpressionVectorParameter::StaticClass()))
        			{
                        auto vectParm = reinterpret_cast<UMaterialExpressionVectorParameter*>(matExp);
                        vectParm->DefaultValue.A = dis(e);
                        vectParm->DefaultValue.R = dis(e);
                        vectParm->DefaultValue.G = dis(e);
                        vectParm->DefaultValue.B = dis(e);
                    }
        		}
        	}
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

    return true;
}

SPI_IMPLEMENT_DETACH
{
    Common::CloseConsole();
    return true;
}
