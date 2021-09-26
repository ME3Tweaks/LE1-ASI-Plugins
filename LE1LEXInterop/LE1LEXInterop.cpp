#include <stdio.h>
#include <io.h>
#include <string>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <streambuf>
#include <shlwapi.h>
#include <sstream>
#include "Strsafe.h"
#include "../Interface.h"
#include "../Common.h"
#include "../SDK/LE1SDK/SdkHeaders.h"
#include "../ME3TweaksHeader.h"

#pragma comment(lib, "shlwapi.lib")

#define MYHOOK "LE1LEXInterop_"

SPI_PLUGINSIDE_SUPPORT(L"LE1 LEX Interop", L"1.0.0", L"ME3Tweaks", SPI_GAME_LE1, SPI_VERSION_ANY);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

TCHAR SplashPath[MAX_PATH];

char* GetUObjectClassName(UObject* object)
{
	static char cOutBuffer[256];

	sprintf_s(cOutBuffer, "%s", object->Class->GetName());

	return cOutBuffer;
}

char* GetContainingMapName(UObject* object)
{
	if (object->Class && object->Outer)
	{
		class UObject* OuterObj = object->Outer;
		static std::string lastName = "Undefined";
		UINT32 lastIndex = -1;
		while (OuterObj->Class && OuterObj->Outer)
		{
			lastName = OuterObj->Outer->GetName();
			lastIndex = OuterObj->Outer->Name.Number;

			OuterObj = OuterObj->Outer;
		}
		if (lastIndex > 0) {
			lastIndex--; //Subtract 1 to match filesystem indexing
			lastName += "_" + std::to_string(lastIndex);
		}
		return (char*)lastName.c_str();
	}
	return "(null)";
}

wchar_t msgBuffer[512];
wchar_t* msgPtr;
int writePos = 0;
void WriteToMsgBuffer(const wchar_t* wstr, const int len, const bool msgStart = false) {
	if (msgStart)
	{
		if (writePos > 400)
		{
			writePos = 0;
		}
		msgPtr = msgBuffer + writePos;
	}
	else
	{
		msgBuffer[writePos] = ' ';
		writePos++;
	}
	for (auto i = 0; i < len && wstr[i] != 0 && writePos < 512; i++, writePos++)
	{
		msgBuffer[writePos] = wstr[i];
	}
}

void WriteToMsgBuffer(const FString& fstr, const bool msgStart = false) {
	WriteToMsgBuffer(fstr.Data, fstr.Count, msgStart);
}

void WriteToMsgBuffer(wstring wstr, const bool msgStart = false) {
	WriteToMsgBuffer(wstr.c_str(), wstr.length(), msgStart);
}

struct ME3ExpMsg
{
	wchar_t msg[100];
};

void SendMessageToLEX(USequenceOp* op)
{
	const auto numVarLinks = op->VariableLinks.Num();
	for (auto i = 0; i < numVarLinks; i++)
	{
		const auto& varLink = op->VariableLinks(i);
		for (auto j = 0; j < varLink.LinkedVariables.Count; ++j)
		{
			const auto seqVar = varLink.LinkedVariables(j);
			if (!_wcsnicmp(varLink.LinkDesc.Data, L"MessageName", 12) && IsA<USeqVar_String>(seqVar))
			{
				const USeqVar_String* strVar = static_cast<USeqVar_String*>(seqVar);
				WriteToMsgBuffer(strVar->StrValue, true);
			}
			else if (!_wcsnicmp(varLink.LinkDesc.Data, L"String", 7) && IsA<USeqVar_String>(seqVar))
			{
				const USeqVar_String* strVar = static_cast<USeqVar_String*>(seqVar);
				WriteToMsgBuffer(L"string", 7);
				WriteToMsgBuffer(strVar->StrValue);
			}
			else if (!_wcsnicmp(varLink.LinkDesc.Data, L"Vector", 7) && IsA<USeqVar_Vector>(seqVar))
			{
				const USeqVar_Vector* vectorVar = static_cast<USeqVar_Vector*>(seqVar);
				WriteToMsgBuffer(L"vector", 7);
				WriteToMsgBuffer(to_wstring(vectorVar->VectValue.X));
				WriteToMsgBuffer(to_wstring(vectorVar->VectValue.Y));
				WriteToMsgBuffer(to_wstring(vectorVar->VectValue.Z));
			}
			else if (!_wcsnicmp(varLink.LinkDesc.Data, L"Float", 5) && IsA<USeqVar_Float>(seqVar))
			{
				const USeqVar_Float* floatVar = static_cast<USeqVar_Float*>(seqVar);
				WriteToMsgBuffer(L"float", 6);
				WriteToMsgBuffer(to_wstring(floatVar->FloatValue));
			}
			else if (!_wcsnicmp(varLink.LinkDesc.Data, L"Int", 3) && IsA<USeqVar_Int>(seqVar))
			{
				const USeqVar_Int* intVar = static_cast<USeqVar_Int*>(seqVar);
				WriteToMsgBuffer(L"int", 4);
				WriteToMsgBuffer(to_wstring(intVar->IntValue));
			}
			else if (!_wcsnicmp(varLink.LinkDesc.Data, L"Bool", 4) && IsA<USeqVar_Bool>(seqVar))
			{
				const USeqVar_Bool* boolVar = static_cast<USeqVar_Bool*>(seqVar);
				WriteToMsgBuffer(L"bool", 5);
				WriteToMsgBuffer(to_wstring(boolVar->bValue));
			}
		}
	}
	msgBuffer[writePos] = 0;
	writePos++;
	auto handle = FindWindow(nullptr, L"Legendary Explorer");
	if (handle)
	{
		constexpr unsigned long SENT_FROM_LE1 = 0x02AC00C7;
		ME3ExpMsg msg;
		const auto len = writePos - (msgPtr - msgBuffer);
		wcsncpy_s(msg.msg, msgPtr, len);
		COPYDATASTRUCT cds;
		ZeroMemory(&cds, sizeof(COPYDATASTRUCT));
		cds.dwData = SENT_FROM_LE1;
		cds.cbData = sizeof(msg);
		cds.lpData = &msg;
		SendMessageTimeout(handle, WM_COPYDATA, NULL, reinterpret_cast<LPARAM>(&cds), 0, 10, nullptr);
	}
}

TArray<UObject*> Actors;

void DumpActors(USequenceOp* const op)
{
	const auto numVarLinks = op->VariableLinks.Num();
	const auto objCount = UObject::GObjObjects()->Count;
	const auto objArray = UObject::GObjObjects()->Data;

	Actors.Count = 0; //clear the array without de-allocating any memory.
	ofstream ofs;
	ofs.open(SplashPath);
	const auto actorClass = AActor::StaticClass();
	for (auto j = 0; j < objCount; j++)
	{
		auto obj = objArray[j];
		if (obj && obj->IsA(actorClass))
		{
			auto actor = static_cast<AActor*>(obj);
			const auto name = actor->Name.GetName();
			if (strstr(name, "Default_"))// || actor->bStatic || !actor->bMovable)
			{
				continue;
			}
			Actors.Add(actor);
			ofs << GetContainingMapName(actor) << ":" << name;
			const auto index = actor->Name.Number;
			if (index > 0)
			{
				ofs << '_' << index - 1;
			}
			if (actor->bStatic || !actor->bMovable)
			{
				ofs << ":static";
			}
			ofs << endl;
		}
	}
	ofs.close();

	for (auto i = 0; i < numVarLinks; i++)
	{

		if (op->VariableLinks(i).LinkedVariables.Count == 0)
		{
			continue;
		}
		const auto seqVar = op->VariableLinks(i).LinkedVariables(0);
		if (!_wcsnicmp(op->VariableLinks(i).LinkDesc.Data,  L"Length", 7) && IsA<USeqVar_Int>(seqVar))
		{
			const auto lenVar = static_cast<USeqVar_Int*>(seqVar);
			lenVar->IntValue = Actors.Count;
			break;
		}
	}
}

void AccessDumpedActorsList(USequenceOp* const op)
{
	const auto numVarLinks = op->VariableLinks.Num();
	int index = 0;
	for (auto i = 0; i < numVarLinks; i++)
	{
		if (op->VariableLinks(i).LinkedVariables.Count == 0)
		{
			continue;
		}
		const auto seqVar = op->VariableLinks(i).LinkedVariables(0);
		if (!_wcsnicmp(op->VariableLinks(i).LinkDesc.Data, L"Index", 5) && IsA<USeqVar_Int>(seqVar))
		{
			const auto idxVar = static_cast<USeqVar_Int*>(seqVar);
			index = idxVar->IntValue;
		}
		if (!_wcsnicmp(op->VariableLinks(i).LinkDesc.Data, L"Output Object", 15) && IsA<USeqVar_Object>(seqVar))
		{
			const auto outputVar = static_cast<USeqVar_Object*>(seqVar);
			if (index >= 0 && index < Actors.Count)
			{
				outputVar->ObjValue = Actors(index);
			}
			else
			{
				outputVar->ObjValue = nullptr;
			}
		}
	}
}

float ToRadians(const int unrealRotationUnits)
{
	return unrealRotationUnits * 360.0f / 65536.0f * 3.1415926535897931f / 180.0f;
}

FTPOV cachedPOV;
void GetCamPOV(USequenceOp* const op)
{
	const auto numVarLinks = op->VariableLinks.Num();
	for (auto i = 0; i < numVarLinks; i++)
	{

		if (op->VariableLinks(i).LinkedVariables.Count == 0)
		{
			continue;
		}
		const auto seqVar = op->VariableLinks(i).LinkedVariables(0);
		if (!_wcsnicmp(op->VariableLinks(i).LinkDesc.Data, L"Position", 10) && IsA<USeqVar_Vector>(seqVar))
		{
			const auto posVar = static_cast<USeqVar_Vector*>(seqVar);
			posVar->VectValue = cachedPOV.Location;
		}
		else if (!_wcsnicmp(op->VariableLinks(i).LinkDesc.Data, L"Rotation", 10) && IsA<USeqVar_Vector>(seqVar))
		{
			const auto pitch = ToRadians(cachedPOV.Rotation.Pitch);
			const auto yaw = ToRadians(cachedPOV.Rotation.Yaw);
			const auto cp = cos(pitch);
			const auto sp = sin(pitch);
			const auto cy = cos(yaw);
			const auto sy = sin(yaw);
			FVector rotVect;
			rotVect.X = cp * cy;
			rotVect.Y = cp * sy;
			rotVect.Z = sp;

			auto* rotVar = static_cast<USeqVar_Vector*>(seqVar);
			rotVar->VectValue = rotVect;
		}
	}
}


// ProcessEvent hook
// ======================================================================

typedef void (*tProcessEvent)(UObject* Context, UFunction* Function, void* Parms, void* Result);
tProcessEvent ProcessEvent = nullptr;

tProcessEvent ProcessEvent_orig = nullptr;
void ProcessEvent_hook(UObject* Context, UFunction* Function, void* Parms, void* Result)
{
    const auto className = Context->Class->Name.GetName();
    if(!strcmp(className, "SeqAct_SendMessageToLEX"))
    {
        if(!strcmp(Function->GetFullName(), "Function Engine.SequenceOp.Activated"))
        {
            const auto op = static_cast<USequenceOp*>(Context);
            SendMessageToLEX(op);
        }
    }
    else if(!strcmp(className, "SeqAct_LEXDumpActors"))
    {
        if(!strcmp(Function->GetFullName(), "Function Engine.SequenceOp.Activated"))
        {
            const auto op = static_cast<USequenceOp*>(Context);
            DumpActors(op);
        }
    }
    else if(!strcmp(className, "SeqAct_LEXAccessDumpedActorsList"))
    {
        if(!strcmp(Function->GetFullName(), "Function Engine.SequenceOp.Activated"))
        {
            const auto op = static_cast<USequenceOp*>(Context);
            AccessDumpedActorsList(op);
        }
    }
    else if(!strcmp(className, "SeqAct_LEXGetPlayerCamPOV"))
    {
        if(!strcmp(Function->GetFullName(), "Function Engine.SequenceOp.Activated"))
        {
            const auto op = static_cast<USequenceOp*>(Context);
            GetCamPOV(op);
        }
    }
	else if (IsA<ABioPlayerController>(Context) && strcmp(Function->GetName(), "PlayerTick") == 0)
	{
		const auto playerController = static_cast<ABioPlayerController*>(Context);
		cachedPOV = playerController->PlayerCamera->CameraCache.POV;
	}
    ProcessEvent_orig(Context, Function, Parms, Result);
}



SPI_IMPLEMENT_ATTACH
{
    Common::OpenConsole();

    auto _ = SDKInitializer::Instance();

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

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID) {
	if (reason == DLL_PROCESS_ATTACH) 
	{
		GetModuleFileName(hModule, SplashPath, MAX_PATH);
		PathRemoveFileSpec(SplashPath);
		PathRemoveFileSpec(SplashPath);
		StringCchCat(SplashPath, MAX_PATH, L"\\ME3ExpActorDump.txt");
	}

	return TRUE;
}
