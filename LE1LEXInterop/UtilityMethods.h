#pragma once

// Not sure this works!
bool NopOutMemory(void* startPos, int patchSize)
{
	//make the memory we're going to patch writeable
	DWORD  oldProtect;
	if (!VirtualProtect(startPos, patchSize, PAGE_EXECUTE_READWRITE, &oldProtect))
		return false;

	// Nop it out
	writeln(L"Nopping memory: %p for %i bytes", startPos, patchSize);
	for (int i = 0; i < patchSize; i++)
	{
		*(char*)((int64)startPos + i) = 0x90; // This line only has 3 underlines in visual studio
	}

	//restore the memory's old protection level
	VirtualProtect(startPos, patchSize, oldProtect, &oldProtect);
	FlushInstructionCache(GetCurrentProcess(), startPos, patchSize);
	return true;
}

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

// Gets the string up to the end of the next space. The input parameter will be modified.
std::string GetCommandParam(std::string& commandStr)
{
	auto spacePos = commandStr.find(' ', 0);
	if (spacePos == string::npos)
	{
		return commandStr; // Return the rest of the string
	}

	auto param = commandStr.substr(0, spacePos);
	commandStr = commandStr.substr(spacePos + 1, commandStr.length() - 1 - spacePos);
	return param;
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

void SetSequenceString(USequenceOp* op, wchar_t* linkName, wchar_t* value)
{
	const auto numVarLinks = op->VariableLinks.Num();
	for (auto i = 0; i < numVarLinks; i++)
	{
		const auto& varLink = op->VariableLinks(i);
		for (auto j = 0; j < varLink.LinkedVariables.Count; ++j)
		{
			const auto seqVar = varLink.LinkedVariables(j);
			if (!_wcsnicmp(varLink.LinkDesc.Data, linkName, 256) && IsA<USeqVar_String>(seqVar))
			{
				USeqVar_String* strVar = reinterpret_cast<USeqVar_String*>(seqVar);
				auto strVal = strVar->StrValue;
				strVal.Data = value;
				strVal.Count = wcslen(value);
				strVar->StrValue = strVal; // Value is updated but kismet behavior doesn't change
			}
		}
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
typedef BOOL(*tCachePackage)(void* parm1, wchar_t* filePath, bool replaceIfExisting, bool warnIfExists);
tCachePackage CacheContent = nullptr;

tCachePackage CacheContentWrapper = nullptr; // capture pointer
tCachePackage CacheContentWrapper_orig = nullptr;
void* CacheContentWrapperClassPointer = nullptr; // Pointer we will use when we call the orig method on our own
BOOL CacheContentWrapper_hook(void* parm1, wchar_t* filePath, bool replaceIfExisting, bool warnIfExists)
{
	CacheContentWrapperClassPointer = parm1;
	return CacheContentWrapper_orig(parm1, filePath, replaceIfExisting, warnIfExists);
}