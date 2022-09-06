/*
#############################################################################################
# Mass Effect 1 (Legendary Edition) (2.0.0.48602) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: SdkHeaders.h
# ========================================================================================= #
# Credits: uNrEaL, Tamimego, SystemFiles, R00T88, _silencer, the1domo, K@N@VEL
# Thanks: HOOAH07, lowHertz
# Forums: www.uc-forum.com, www.gamedeception.net
#############################################################################################
*/


#pragma once
#include <Windows.h>
#include <cstdio>
#include "SdkInitializer.h"



/*
# ========================================================================================= #
# Defines
# ========================================================================================= #
*/

#undef lst1
#undef lst2
#undef lst3
#undef lst4
#undef lst5
#undef lst6
#undef lst7
#undef lst8
#undef lst9
#undef lst10
#undef lst11
#undef lst12
#undef lst13
#undef lst14
#undef lst15
#undef lst16

/*
# ========================================================================================= #
# Structs
# ========================================================================================= #
*/

template< class T > struct TArray
{
public:
	T* Data;
	int Count;
	int Max;

public:
	TArray()
	{
		Data = NULL;
		Count = Max = 0;
	};

public:
	int Num()
	{
		return this->Count;
	};

	bool Any()
	{
		return this->Count > 0;
	}

	/// <summary>
	/// Do not use this on TArrays you don't create yourself, as the Unreal allocator won't work with them.
	/// </summary>
	/// <param name="InputData"></param>
	void Add(T InputData)
	{
		if (Count >= Max)
		{
			Max = Count + 3 * Count / 8 + 16;
			Data = (T*)realloc(Data, sizeof(T) * Max);
		}
		Data[Count++] = InputData;
	};

	const T& operator() (int i) const
	{
		return this->Data[i];
	};

};

/** Packed index DWORD as seen in FNameEntry. */
struct PackedIndex
{
	DWORD Offset : 20;  // The actual index, I guess???
	DWORD Length : 9;   // Length of the AnsiName or WideName in symbols \wo null-terminator.
	DWORD Bits : 3;     // Always 4 or 0. No idea wtf it really is, flags maybe?
};

// ----------------------------------------------------------------
// FNameEntry bitmasks
// ----------------------------------------------------------------

const UINT    NAMEENTRY_CONST = 0x80000000;
const UINT    NAMEENTRY_UNICODE = 0x40000000;
const UINT    NAMEENTRY_ANSI = 0x00000000;
const UINT    NAMEENTRY_LOGSUPPRESSED = 0x20000000;
const UINT    NAMEENTRY_UPPERHASH_BITS = 32 - 3; // Length is 9 bits, so 512 is max length
const UINT    NAMEENTRY_UPPERHASH_MASK = (1 << NAMEENTRY_UPPERHASH_BITS) - 1;
const UINT    NAMEENTRY_LENGTH_MASK = (512 - 1) << NAMEENTRY_UPPERHASH_BITS;
const UINT    NAMEENTRY_LENGTH_SHIFT = NAMEENTRY_UPPERHASH_BITS;
const UINT    NAMEENTRY_COMPARE_MASK = 0x5fffffff;

#pragma pack(push, 1)
/** Name as seen in some kind of name pool. */
struct FNameEntry
{
	UINT FlagsAndMeta;     // 0x00
	FNameEntry* HashNext;  // 0x04  Some pointer, often NULL.
	union
	{
		char AnsiName[512];
		wchar_t UniName[512]; // 512 is max NAME_SIZE, according to d00t's PackedIndex of Length 2^9
	};

	FORCEINLINE bool IsUnicode() const
	{
		return this != NULL && (FlagsAndMeta & NAMEENTRY_UNICODE) != 0;
	}
};

/** Name reference as seen in individual UObjects. */
struct FName
{
	DWORD Offset : 29;  // Binary offset into an individual chunk.
	DWORD Chunk : 3;    // Index of the chunk, I've only seen 0 or 1.
	signed long Number;        // ?= InstanceIndex

	__forceinline char* GetName() const noexcept
	{
		auto chunk = SDKInitializer::Instance()->GetBioNamePools()[Chunk];
		auto entry = (FNameEntry*)((BYTE*)chunk + Offset);
		return entry->AnsiName;
	}

	bool operator==(const FName& A) const noexcept
	{
		return Offset == A.Offset && Chunk == A.Chunk && Number == A.Number;
	}

	// This is not reliable for "None"
	static INT GetNameLength(const FNameEntry* Entry)
	{
		// NULL = "None"
		return Entry == NULL ? 4 : (Entry->FlagsAndMeta & NAMEENTRY_LENGTH_MASK) >> NAMEENTRY_LENGTH_SHIFT;
	}

	/** IDK if this actually works yet. */
	// Should use in-game FName constructor instead, it'll be way more reliable.
	static bool TryFind(char* lookup, signed long instance, FName* outName)
	{
		auto gBioNamePools = SDKInitializer::Instance()->GetBioNamePools();

		for (FNameEntry** namePool = reinterpret_cast<FNameEntry**>(gBioNamePools);
			*namePool != nullptr;
			namePool++)
		{
			for (FNameEntry* nameEntry = *namePool;
				(nameEntry->FlagsAndMeta & NAMEENTRY_LENGTH_MASK) != 0;
				nameEntry = reinterpret_cast<FNameEntry*>(reinterpret_cast<BYTE*>(nameEntry) + sizeof FNameEntry + GetNameLength(nameEntry)))
			{
				if (!strcmp(lookup, nameEntry->AnsiName))
				{
					FName name{};
					name.Offset = (DWORD)((unsigned long long)nameEntry - (unsigned long long)namePool);
					name.Chunk = (DWORD)((unsigned long long)namePool - (unsigned long long)gBioNamePools);
					name.Number = instance;
					*outName = name;
					return true;
				}
			}
		}
		outName = nullptr;
		return false;
	}


	char* Instanced() const
	{
		if (Number > 0)
		{
			static char cOutBuffer[256];
			sprintf_s(cOutBuffer, "%s_%d", GetName(), Number - 1);
			return cOutBuffer;
		}
		else
		{
			return GetName();
		}

	}
};

struct FString : public TArray<wchar_t> {
	FString() {};

	FString(wchar_t* Other)
	{
		this->Max = this->Count = *Other ? (wcslen(Other) + 1) : 0;

		if (this->Count)
			this->Data = Other;
	};

	~FString() { };

	FString operator = (wchar_t* Other)
	{
		if (this->Data != Other)
		{
			this->Max = this->Count = *Other ? (wcslen(Other) + 1) : 0;

			if (this->Count)
				this->Data = Other;
		}

		return *this;
	};
};

struct FScriptDelegate
{
	class UObject* Object;
	struct FName		FunctionName;
};

struct FScriptInterface
{
	UObject* Object;
	void* Interface;
};

struct FObjectResource
{
	struct FName ObjectName;
	int	OuterIndex;
};

struct FObjectImport : public FObjectResource
{
	struct FName ClassPackage;
	struct FName ClassName;
	class UObject* Object;
	class ULinkerLoad* SourceLinker;
	int SourceIndex;
};

/*
# ========================================================================================= #
# Includes
# ========================================================================================= #
*/


#pragma warning( disable : 26495 )

#include "SDK_HEADERS\\Core_structs.h"
#include "SDK_HEADERS\\Core_classes.h"
#include "SDK_HEADERS\\Core_f_structs.h"
#include "SDK_HEADERS\\Core_functions.h"
#include "SDK_HEADERS\\Engine_structs.h"
#include "SDK_HEADERS\\Engine_classes.h"
#include "SDK_HEADERS\\Engine_f_structs.h"
#include "SDK_HEADERS\\Engine_functions.h"
#include "SDK_HEADERS\\IpDrv_structs.h"
#include "SDK_HEADERS\\IpDrv_classes.h"
#include "SDK_HEADERS\\IpDrv_f_structs.h"
#include "SDK_HEADERS\\IpDrv_functions.h"
#include "SDK_HEADERS\\GFxUI_structs.h"
#include "SDK_HEADERS\\GFxUI_classes.h"
#include "SDK_HEADERS\\GFxUI_f_structs.h"
#include "SDK_HEADERS\\GFxUI_functions.h"
#include "SDK_HEADERS\\ISACTAudio_structs.h"
#include "SDK_HEADERS\\ISACTAudio_classes.h"
#include "SDK_HEADERS\\ISACTAudio_f_structs.h"
#include "SDK_HEADERS\\ISACTAudio_functions.h"
#include "SDK_HEADERS\\WinDrv_structs.h"
#include "SDK_HEADERS\\WinDrv_classes.h"
#include "SDK_HEADERS\\WinDrv_f_structs.h"
#include "SDK_HEADERS\\WinDrv_functions.h"
#include "SDK_HEADERS\\SFXGame_structs.h"
#include "SDK_HEADERS\\SFXGame_classes.h"
#include "SDK_HEADERS\\SFXGame_f_structs.h"
#include "SDK_HEADERS\\SFXGame_functions.h"
#include "SDK_HEADERS\\SFXOnlineFoundation_structs.h"
#include "SDK_HEADERS\\SFXOnlineFoundation_classes.h"
#include "SDK_HEADERS\\SFXOnlineFoundation_f_structs.h"
#include "SDK_HEADERS\SFXOnlineFoundation_functions.h"
#include "SDK_HEADERS\\PlotManagerMap_structs.h"
#include "SDK_HEADERS\\PlotManagerMap_classes.h"
#include "SDK_HEADERS\\PlotManagerMap_f_structs.h"
#include "SDK_HEADERS\\PlotManagerMap_functions.h"
#include "SDK_HEADERS\\SFXStrategicAI_structs.h"
#include "SDK_HEADERS\\SFXStrategicAI_classes.h"
#include "SDK_HEADERS\\SFXStrategicAI_f_structs.h"
#include "SDK_HEADERS\\SFXStrategicAI_functions.h"
#include "SDK_HEADERS\\SFXGameContent_Powers_structs.h"
#include "SDK_HEADERS\\SFXGameContent_Powers_classes.h"
#include "SDK_HEADERS\\SFXGameContent_Powers_f_structs.h"
#include "SDK_HEADERS\\SFXGameContent_Powers_functions.h"
#include "SDK_HEADERS\\PlotManager_structs.h"
#include "SDK_HEADERS\\PlotManager_classes.h"
#include "SDK_HEADERS\\PlotManager_f_structs.h"
#include "SDK_HEADERS\\PlotManager_functions.h"
//#include "SDK_HEADERS\\PlotManagerDLC_UNC_structs.h"
//#include "SDK_HEADERS\\PlotManagerDLC_UNC_classes.h"
//#include "SDK_HEADERS\\PlotManagerDLC_UNC_f_structs.h"
//#include "SDK_HEADERS\\PlotManagerDLC_UNC_functions.h"
#include "SDK_HEADERS\\BIOC_Materials_structs.h"
#include "SDK_HEADERS\\BIOC_Materials_classes.h"
#include "SDK_HEADERS\\BIOC_Materials_f_structs.h"
#include "SDK_HEADERS\\BIOC_Materials_functions.h"
#include "SDK_HEADERS\\SFXWorldResources_structs.h"
#include "SDK_HEADERS\\SFXWorldResources_classes.h"
#include "SDK_HEADERS\\SFXWorldResources_f_structs.h"
#include "SDK_HEADERS\\SFXWorldResources_functions.h"
#include "SDK_HEADERS\\SFXVehicleResources_structs.h"
#include "SDK_HEADERS\\SFXVehicleResources_classes.h"
#include "SDK_HEADERS\\SFXVehicleResources_f_structs.h"
#include "SDK_HEADERS\\SFXVehicleResources_functions.h"
#include "SDK_HEADERS\\SFXQA_structs.h"
#include "SDK_HEADERS\\SFXQA_classes.h"
#include "SDK_HEADERS\\SFXQA_f_structs.h"
#include "SDK_HEADERS\\SFXQA_functions.h"

#pragma warning( enable : 26495 )

#pragma pack(pop)