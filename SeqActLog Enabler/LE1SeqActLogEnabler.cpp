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

#define MYHOOK "LE1SeqActLogEnabler_"

SPI_PLUGINSIDE_SUPPORT(L"LE1SeqActLogEnabler", L"0.1.0", L"HenBagle", SPI_GAME_LE1, SPI_VERSION_ANY);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;


std::wstringstream& operator<<(std::wstringstream& ss, const FString& fStr)
{
	
	for (auto i = 0; i < fStr.Count && fStr(i) != 0; i++)
	{
		ss << fStr(i);
	}
	return ss;
}

// ProcessEvent hook
// ======================================================================

typedef void (*tProcessEvent)(UObject* Context, UFunction* Function, void* Parms, void* Result);
tProcessEvent ProcessEvent = nullptr;

tProcessEvent ProcessEvent_orig = nullptr;
void ProcessEvent_hook(UObject* Context, UFunction* Function, void* Parms, void* Result)
{
    if(!strcmp(Function->GetFullName(), "Function Engine.SequenceOp.Activated") && Context->IsA(USeqAct_Log::StaticClass()))
    {
        const auto seqLog = reinterpret_cast<USeqAct_Log*>(Context);
        const auto numVarLinks = seqLog->VariableLinks.Count;
        std::wstringstream ss;

        // This doesn't work
        /*if(seqLog->bOutputObjCommentToScreen == 1ul)
        {
            const auto numLines = seqLog->m_aObjComment.Num();
            for(auto k = 0; k < numLines; k++)
            {
                ss << seqLog->m_aObjComment(k) << " ";
            }
        }*/

        for(auto i = 0; i < numVarLinks; i++)
        {
            const auto numVars = seqLog->VariableLinks(i).LinkedVariables.Count;
            for(auto j = 0; j < numVars; j++)
            {
                auto seqVar = seqLog->VariableLinks(i).LinkedVariables(j);
                if(seqVar->IsA(USeqVar_String::StaticClass()))
                {
                    ss << static_cast<USeqVar_String*>(seqVar)->StrValue << " ";
                }
                else if(seqVar->IsA(USeqVar_Float::StaticClass()))
                {
                    ss << static_cast<USeqVar_Float*>(seqVar)->FloatValue << " ";
                }
                else if(seqVar->IsA(USeqVar_Int::StaticClass()))
                {
                    ss << static_cast<USeqVar_Int*>(seqVar)->IntValue << " ";
                }
                else if(seqVar->IsA(USeqVar_Bool::StaticClass()))
                {
                    ss << (static_cast<USeqVar_Bool*>(seqVar)->bValue ? "True" : "False") << " ";
                }
                else if (seqVar->IsA(USeqVar_Object::StaticClass()))
				{
					const auto seqVarObj = static_cast<USeqVar_Object*>(seqVar);
					auto referencedObj = seqVarObj->ObjValue;
					if (referencedObj != nullptr)
					{
						ss << referencedObj->GetName() << " ";
					}
				}
                else if (seqVar->IsA(USeqVar_Name::StaticClass()))
				{
					ss << static_cast<USeqVar_Name*>(seqVar)->NameValue.GetName() << " ";
				}
            }
            
        }
        writeln(L"SeqAct_Log: %s", ss.str().c_str());
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
