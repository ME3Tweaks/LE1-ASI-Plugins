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

#define MYHOOK "2DAPrinter_"

SPI_PLUGINSIDE_SUPPORT(L"2DAPrinter", L"1.0.0", L"ME3Tweaks", SPI_GAME_LE1, SPI_VERSION_ANY);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

ME3TweaksASILogger logger("2DA Printer v1", "2DAPrintLog.txt");

int remainingToGo = 500;


// ProcessEvent hook (for non-native .Activated())
// ======================================================================

typedef void (*tProcessEvent)(UObject* Context, UFunction* Function, void* Parms, void* Result);
tProcessEvent ProcessEvent = nullptr;

tProcessEvent ProcessEvent_orig = nullptr;
void Parse2DA(UBio2DA* twoDA)
{
	if (twoDA)
	{
		auto colNames = twoDA->GetColumnNames();
		auto rowNames = twoDA->GetRowNames();

		char* buffer = new char[512];
		sprintf(buffer, "Printout for Bio2DA %hs\n", twoDA->GetFullName());
		logger.writeToLog(buffer, false, false);
		for (int j = 0; j < rowNames.Count; j++)
		{
			for (int k = 0; k < colNames.Count; k++)
			{
				char* buffer = new char[512];
				if (FName nameVal; twoDA->GetNameEntryII(j, k, &nameVal))
				{
					sprintf(buffer, "2DA[%hs][%hs] = %hs NAME\n", rowNames.Data[j].GetName(), colNames.Data[k].GetName(), nameVal.Instanced());
				}
				else if (FString strVal; twoDA->GetStringEntryII(j, k, &strVal))
				{
					sprintf(buffer, "2DA[%hs][%hs] = %ls STRING\n", rowNames.Data[j].GetName(), colNames.Data[k].GetName(), strVal.Data);
				}
				else if (float floatVal = -123.35; twoDA->GetFloatEntryII(j, k, &floatVal))
				{
					sprintf(buffer, "2DA[%hs][%hs] = %f FLOAT\n", rowNames.Data[j].GetName(), colNames.Data[k].GetName(), floatVal);
				}
				else if (int intVal = -895; twoDA->GetIntEntryII(j, k, &intVal))
				{
					sprintf(buffer, "2DA[%hs][%hs] = %d INT\n", rowNames.Data[j].GetName(), colNames.Data[k].GetName(), intVal);
				}
				else
				{
					sprintf(buffer, "2DA[%hs][%hs] = NULL\n", rowNames.Data[j].GetName(), colNames.Data[k].GetName());
				}

				logger.writeToLog(buffer, false, false);
			}
		}
	}
}

void Parse2DANR(UBio2DANumberedRows* twoDA)
{
	if (twoDA)
	{
		auto colNames = twoDA->GetColumnNames();
		auto rowCount = twoDA->GetNumRows();

		char* buffer = new char[512];
		sprintf(buffer, "Printout for Bio2DANumberedRows %hs\n", twoDA->GetFullName());
		logger.writeToLog(buffer, false, false);
		for (int j = 0; j < rowCount; j++)
		{
			auto rowIndex = twoDA->GetRowNumber(j);
			for (int k = 0; k < colNames.Count; k++)
			{
				buffer = new char[512];
				if (FName nameVal; twoDA->GetNameEntryII(j, k, &nameVal))
				{
					sprintf(buffer, "2DANR[%d][%hs] = %hs NAME\n", rowIndex, colNames.Data[k].GetName(), nameVal.Instanced());
				}
				else if (FString strVal; twoDA->GetStringEntryII(j, k, &strVal))
				{
					sprintf(buffer, "2DANR[%d][%hs] = %ls STRING\n", rowIndex, colNames.Data[k].GetName(), strVal.Data);
				}
				else if (float floatVal = -123.35; twoDA->GetFloatEntryII(j, k, &floatVal))
				{
					sprintf(buffer, "2DANR[%d][%hs] = %f FLOAT\n", rowIndex, colNames.Data[k].GetName(), floatVal);
				}
				else if (int intVal = -895; twoDA->GetIntEntryII(j, k, &intVal))
				{
					sprintf(buffer, "2DANR[%d][%hs] = %d INT\n", rowIndex, colNames.Data[k].GetName(), intVal);
				}
				else
				{
					sprintf(buffer, "2DANR[%d][%hs] = NULL\n", rowIndex, colNames.Data[k].GetName());
				}

				logger.writeToLog(buffer, false, false);
			}
		}
	}
}

void Print2DAs()
{
	auto twoDAs = FindObjectsOfType(UBio2DA::StaticClass());
	for (int i = 0; i < twoDAs.Count; i++)
	{
		auto twoDA = reinterpret_cast<UBio2DA*>(twoDAs.Data[i]);
		if (twoDA->Class == UBio2DANumberedRows::StaticClass())
		{
			Parse2DANR(reinterpret_cast<UBio2DANumberedRows*>(twoDA));
		}
		else
		{
			Parse2DA(twoDA);
		}
	}
}

bool CanPrint2DAs = true;

void ProcessEvent_hook(UObject* Context, UFunction* Function, void* Parms, void* Result)
{
	if (CanPrint2DAs && !strcmp(Function->GetFullName(), "Function SFXGame.BioHUD.PostRender"))
	{
		// Toggle drawing/not drawing
		if ((GetKeyState('2') & 0x8000) && (GetKeyState(VK_CONTROL) & 0x8000)) {
			if (CanPrint2DAs) {
				Print2DAs();
				CanPrint2DAs = false; // Will not activate combo again until you re-press combo
				writeln("Printed 2DAs to log. Can no longer print 2DAs in this session.");
			}
		}
	}
	ProcessEvent_orig(Context, Function, Parms, Result);
}


SPI_IMPLEMENT_ATTACH
{
	Common::OpenConsole();

	auto _ = SDKInitializer::Instance();
	// Hook ProcessEvent for Non-Native
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
	logger.flush();
	return true;
}
