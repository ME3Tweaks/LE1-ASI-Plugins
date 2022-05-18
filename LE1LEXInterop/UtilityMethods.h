#pragma once

// LEX COMMUNICATIONS

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

inline std::wostream& operator<< (std::wostream& out, FString const& fString)
{
	out.write(fString.Data, fString.Count);
	return out;
}

// Strings sent to LEX should use the following format:
// [FEATURENAME] [Args...]
// e.g. PATHFINDING_GPS PLAYERLOC=1,2,3
void SendStringToLEX(const wstring& wstr) {
	if (const auto handle = FindWindow(nullptr, L"Legendary Explorer"))
	{
		constexpr unsigned long SENT_FROM_LE1 = 0x02AC00C7;
		COPYDATASTRUCT cds;
		ZeroMemory(&cds, sizeof(COPYDATASTRUCT));
		cds.dwData = SENT_FROM_LE1;
		cds.cbData = (wstr.length() + 1) * sizeof(wchar_t);
		cds.lpData = PVOID(wstr.c_str());
		SendMessageTimeout(handle, WM_COPYDATA, NULL, reinterpret_cast<LPARAM>(&cds), 0, 10, nullptr);
	}
}

void SendMessageToLEX(USequenceOp* op)
{
	wstringstream wss;
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
				wss << strVar->StrValue;
			}
			else if (!_wcsnicmp(varLink.LinkDesc.Data, L"String", 7) && IsA<USeqVar_String>(seqVar))
			{
				const USeqVar_String* strVar = static_cast<USeqVar_String*>(seqVar);
				wss << L" string " << strVar->StrValue;
			}
			else if (!_wcsnicmp(varLink.LinkDesc.Data, L"Vector", 7) && IsA<USeqVar_Vector>(seqVar))
			{
				const USeqVar_Vector* vectorVar = static_cast<USeqVar_Vector*>(seqVar);
				wss << L" vector " << vectorVar->VectValue.X << L" " << vectorVar->VectValue.Y << L" " << vectorVar->VectValue.Z;
			}
			else if (!_wcsnicmp(varLink.LinkDesc.Data, L"Float", 5) && IsA<USeqVar_Float>(seqVar))
			{
				const USeqVar_Float* floatVar = static_cast<USeqVar_Float*>(seqVar);
				wss << L" float " << floatVar->FloatValue;
			}
			else if (!_wcsnicmp(varLink.LinkDesc.Data, L"Int", 3) && IsA<USeqVar_Int>(seqVar))
			{
				const USeqVar_Int* intVar = static_cast<USeqVar_Int*>(seqVar);
				wss << L" int " << intVar->IntValue;
			}
			else if (!_wcsnicmp(varLink.LinkDesc.Data, L"Bool", 4) && IsA<USeqVar_Bool>(seqVar))
			{
				const USeqVar_Bool* boolVar = static_cast<USeqVar_Bool*>(seqVar);
				wss << L" bool " << boolVar->bValue;
			}
		}
	}
	const wstring msg = wss.str();
	SendStringToLEX(msg);
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