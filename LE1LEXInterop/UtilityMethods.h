#pragma once

// LEX COMMUNICATIONS
struct ME3ExpMsg
{
	wchar_t msg[100];
};

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

// Strings sent to LEX should use the following format:
// [FEATURENAME] [Args...]
// e.g. PATHFINDING_GPS PLAYERLOC=1,2,3
void SendStringToLEX(wstring wstr) {
	WriteToMsgBuffer(wstr, true);
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


// Utility methods
float ToRadians(const int unrealRotationUnits)
{
	return unrealRotationUnits * 360.0f / 65536.0f * 3.1415926535897931f / 180.0f;
}

// Game utility methods
typedef void (*tCachePackage)(void* parm1, wchar_t* filePath, bool replaceIfExisting, bool warnIfExists);
tCachePackage CacheContentWrapper = nullptr;
tCachePackage CacheContentWrapper_orig = nullptr;
void* CacheContentWrapperClassPointer = nullptr; // Pointer we will use when we call the orig method on our own
void CacheContentWrapper_hook(void* parm1, wchar_t* filePath, bool replaceIfExisting, bool warnIfExists)
{
	CacheContentWrapperClassPointer = parm1;
	CacheContentWrapper_orig(parm1, filePath, replaceIfExisting, warnIfExists);
}

typedef void (*tSFXNameConstructor)(FName* outValue, const wchar_t* nameValue, int nameNumber, BOOL createIfNotFoundMaybe, BOOL unk2);
tSFXNameConstructor sfxNameConstructor = nullptr;
// Creates a new name in the game process.
// Note: return value is not used; it only indicates if locating the name generation function succeeded
BOOL CreateName(const wchar_t* name, int number, FName* outName)
{
	if (sfxNameConstructor == nullptr)
	{
		// This is so we can use the macro for slightly cleaner code.
		auto InterfacePtr = SPIInterfacePtr;
		INIT_FIND_PATTERN_POSTHOOK(sfxNameConstructor, /*"40 55 56 57 41*/ "54 41 55 41 56 41 57 48 81 ec 00 07 00 00 48 c7 44 24 50 fe ff ff ff 48 89 9c 24 50 07 00 00 48 8b 05 fd 2d 5d 01 48 33 c4 48 89 84 24 f0 06 00 00");
	}

	sfxNameConstructor(outName, name, number, TRUE, 0);
	return TRUE; // We made a name
}