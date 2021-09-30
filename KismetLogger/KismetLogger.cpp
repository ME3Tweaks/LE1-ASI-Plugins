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

SPI_PLUGINSIDE_SUPPORT(L"KismetLogger", L"3.0.0", L"ME3Tweaks", SPI_GAME_LE1, SPI_VERSION_ANY);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

ME3TweaksASILogger logger("Kismet Logger v3", "KismetLog.txt");



// ProcessEvent hook (for non-native .Activated())
// ======================================================================

typedef void (*tProcessEvent)(UObject* Context, UFunction* Function, void* Parms, void* Result);
tProcessEvent ProcessEvent = nullptr;

tProcessEvent ProcessEvent_orig = nullptr;
void ProcessEvent_hook(UObject* Context, UFunction* Function, void* Parms, void* Result)
{
	if (!strcmp(Function->GetFullName(), "Function Engine.SequenceOp.Activated"))
	{
		const auto op = reinterpret_cast<USequenceOp*>(Context);
		char* fullInstancedPath = op->GetFullPath();
		char* className = op->Class->Name.GetName();
		wchar_t* inputPin = {};
		bool hasInputPin = false;
		for (int i = 0; i < op->InputLinks.Count; i++)
		{
			auto t = op->InputLinks.Data[i];
			if (t.bHasImpulse)
			{
				inputPin = t.LinkDesc.Data;
				hasInputPin = true;
				break;
			}
		}

		if (hasInputPin)
		{
			// C strings are literally the WORST
			char inputPinNonWide[256];
			sprintf(inputPinNonWide, "%ws", inputPin);
			logger.writeToLog(string_format("%s %s %s\n", className, fullInstancedPath, inputPinNonWide), true);
		}
		else
		{
			logger.writeToLog(string_format("%s %s\n", className, fullInstancedPath), true); // could not see input pin
		}

	}
	ProcessEvent_orig(Context, Function, Parms, Result);
}

// ======================================================================
// ProcessInternal hook (for native .Activated())
// ======================================================================

struct OutParmInfo
{
	UProperty* Prop;
	BYTE* PropAddr;
	OutParmInfo* Next;
};

struct LE1FFrame
{
	void* vtable;
	int unks[3];
	UStruct* Node;
	UObject* Object;
	BYTE* Code;
	BYTE* Locals;
	LE1FFrame* PreviousFrame;
	OutParmInfo* OutParms;
};

typedef void (*tProcessInternal)(UObject* Context, LE1FFrame* Stack, void* Result);
tProcessInternal ProcessInternal = nullptr;
tProcessInternal ProcessInternal_orig = nullptr;
void ProcessInternal_hook(UObject* Context, LE1FFrame* Stack, void* Result)
{
	auto func = Stack->Node;
	auto obj = Stack->Object;
	if (obj->IsA(USequenceOp::StaticClass()) && !strcmp(func->GetName(), "Activated"))
	{
		const auto op = reinterpret_cast<USequenceOp*>(Context);
		char* fullInstancedPath = op->GetFullPath();
		char* className = op->Class->Name.GetName();
		logger.writeToLog(string_format("%s %s\n", className, fullInstancedPath), true);
	}
	ProcessInternal_orig(Context, Stack, Result);
}


SPI_IMPLEMENT_ATTACH
{
	Common::OpenConsole();

	auto _ = SDKInitializer::Instance();
	writeln(L"Attach - names at 0x%p, objects at 0x%p",
		SDKInitializer::Instance()->GetBioNamePools(),
		SDKInitializer::Instance()->GetObjects());

	// Hook ProcessEvent for Non-Native
    INIT_FIND_PATTERN_POSTHOOK(ProcessEvent, /* 40 55 41 56 41 */ "57 48 81 EC 90 00 00 00 48 8D 6C 24 20");
    if (auto rc = InterfacePtr->InstallHook(MYHOOK "ProcessEvent", ProcessEvent, ProcessEvent_hook, (void**)&ProcessEvent_orig); 
        rc != SPIReturn::Success)
    {
        writeln(L"Attach - failed to hook ProcessEvent: %d / %s", rc, SPIReturnToString(rc));
        return false;
    }

	// DOESN'T WORK
	//INIT_FIND_PATTERN_POSTHOOK(ProcessInternal, /*"40 53 55 56 57*/ "48 81 EC 88 00 00 00 48 8B 05 B5 25 58 01");
	//if (auto rc = InterfacePtr->InstallHook(MYHOOK "ProcessInternal", ProcessInternal, ProcessInternal, reinterpret_cast<void**>(&ProcessInternal_orig));
	//	rc != SPIReturn::Success)
	//{
	//	writeln(L"Attach - failed to hook ProcessInternal: %d / %s", rc, SPIReturnToString(rc));
	//	return false;
	//}

	if (const auto rc = InterfacePtr->FindPattern(reinterpret_cast<void**>(&ProcessInternal), "40 53 55 56 57 48 81 EC 88 00 00 00 48 8B 05 B5 25 58 01");
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to find ProcessInternal pattern: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}
	if (const auto rc = InterfacePtr->InstallHook(MYHOOK "ProcessInternal", ProcessInternal, ProcessInternal_hook, reinterpret_cast<void**>(&ProcessInternal_orig));
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook ProcessInternal: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}

    return true;
}

SPI_IMPLEMENT_DETACH
{
	Common::CloseConsole();
	logger.flush();
	return true;
}
