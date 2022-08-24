#pragma once

#include "../../Shared-ASI/Interface.h"
#include "../../Shared-ASI/Common.h"
#include "../../Shared-ASI/ME3Tweaks/ME3TweaksHeader.h"

#define MYHOOK "DebugLogger_"

// ENUMS =================================================

// Flags used to control loading
enum ELoadFlags
{
	LOAD_None = 0x00000000,	// No flags
	LOAD_SeekFree = 0x00000001,	// Load the file using seekfree
	LOAD_NoWarn = 0x00000002,	// Don't warn if there's a problem
	LOAD_Throw = 0x00000008,	// Throw an exception if there's a problem
	LOAD_Verify = 0x00000010,	// Test if it exists; don't actually load the file
	LOAD_AllowDll = 0x00000020, // ???
	LOAD_DisallowFiles = 0x00000040,	// ???
	LOAD_NoVerify = 0x00000080,   // Don't verify imports exist
	LOAD_Quiet = 0x00002000,   // Don't log anything
	LOAD_FindIfFail = 0x00004000,	// If object fails to load, try to find in memory instead...?
	LOAD_MemoryReader = 0x00008000,	// Load into memory, and then load from memory instead of piece-by-piece from disk
	LOAD_RemappedPackage = 0x00010000,	// Unused in ME
	LOAD_NoRedirects = 0x00020000,	// Ignore object redirectors
};

// STRUCTS ===============================================
struct OutParmInfo
{
	UProperty* Prop;
	BYTE* PropAddr;
	OutParmInfo* Next;
};

struct LE1FFrame
{
	void* vtable; // 0x0
	int unknown[3];
	UStruct* Node;
	UObject* Object;
	BYTE* Code;
	BYTE* Locals;
	LE1FFrame* PreviousFrame;
	OutParmInfo* OutParms;
};


struct FPackageFileCache;

typedef bool (*tFPackageFileCacheFindPackageFile) (wchar_t* packageName, FGuid* guid, FString& OutFileName, wchar_t* language, bool unknown);
typedef wchar_t** (*tFPackageFileCacheGetPackageFileList) (FPackageFileCache* cache, wchar_t* FileName);

// Used to lookup packages. Fully native
struct FPackageFileCache
{
	virtual void Unknown0() = 0;
	virtual void Unknown1() = 0;
	// Finds a package file by name
	virtual bool FindPackageFile(wchar_t* packageName, FGuid* guid, FString& OutFileName, wchar_t* language, bool unknown) = 0;
	// Returns list of packages. In shipping build of game this just says this method shouldn't be called
	virtual TArray<FString> GetPackageFileList(TArray<FString> outData) = 0;
	// Not sure on the parameters for this func. It's never called by game directly. Just prints out shouldn't happen in ship
	virtual TArray<FString> GetPackageNameList(TArray<FString> outData) = 0;
};


// The address at this location points to the static GPackageFileCache object pointer
FPackageFileCache* GPackageFileCache = nullptr;

// Used to lookup packages. Fully native
struct FFileManager
{
	virtual void Unknown0() = 0;
	virtual void Unknown1() = 0;
	virtual void Unknown2() = 0;
	virtual void Unknown3() = 0;
	virtual void Unknown4() = 0;
	virtual void Unknown5() = 0;
	virtual void Unknown6() = 0;
	virtual void Unknown7() = 0;
	virtual void Unknown8() = 0;
	virtual void Unknown9() = 0;
	virtual void Unknown10() = 0;
	virtual void Unknown11() = 0;
	virtual void Unknown12() = 0;
	virtual void Unknown13() = 0;
	virtual void Unknown14() = 0;
	virtual void Unknown15() = 0;
	virtual void Unknown16() = 0;
	virtual void Unknown17() = 0;
	virtual void Unknown18() = 0;
	virtual void Unknown19() = 0;
	virtual void Unknown20() = 0;
	virtual void Unknown21() = 0;
	virtual void Unknown22() = 0;
	virtual void Unknown23() = 0;
	virtual void Unknown24() = 0;
	virtual void Unknown25() = 0;
	virtual void Unknown26() = 0;
	virtual void Unknown27() = 0;
	virtual void Unknown28() = 0;
	virtual void Unknown29() = 0;

	virtual WCHAR** GetLoadingFileName(void* something) = 0;
};

FFileManager* GFileManager = nullptr;

// Used to load packages
struct UnLinker
{
	virtual void Unknown0() = 0;
	wchar_t* PackageName;
	//virtual void Unknown3() = 0;
	//virtual void Unknown4() = 0;
	//virtual void Unknown5() = 0;
	//virtual void Unknown6() = 0;
	//virtual void Unknown7() = 0;
	//virtual void Unknown8() = 0;
	//virtual void Unknown9() = 0;
	//virtual void Unknown10() = 0;
	//virtual void Unknown11() = 0;
	//virtual void Unknown12() = 0;
	//virtual void Unknown13() = 0;
	INT NameCount1; // IDK
	INT NameCount2; // IDK
	FGuid PackageGuid;
	ULinkerLoad* Linker;
	TArray<void*> CompletionCallbacks;
	INT ImportIndex;
	INT ExportIndex;
	INT PreLoadIndex;
	INT PostLoadIndex;
	FLOAT TimeLimit;
	BOOL bUseTimeLimit;
	BOOL bTimeLimitExceeded;
	DOUBLE TickStartTime;
	//UObject* LastObjectWorkWasPeformedOn;
	//TCHAR* LastTypeOfWorkPerformed;
	//DOUBLE LoadStartTime;
	//FLOAT LoadPercentage;
	//BOOL bHasFinishedExportGuids;

	FLOAT Load1;
	FLOAT Load2;
	FLOAT Load3;
	FLOAT Load4;
	FLOAT Load5;
	FLOAT Load6;
	FLOAT Load7;
	FLOAT EstimatedLoadPercentage;

};

typedef void (*tNativeFunction) (UObject* Context, LE1FFrame* Stack, void* Result);
tNativeFunction* GNatives = nullptr;


// BioWare USystem implementation
struct BioSystem
{
	BYTE Unk[0x68];
	int StaleCacheDays; // 0x68
	int MaxStaleCacheSize; // 0x6C
	int OverallMaxCacheSize; // 0x70
	int PackageSoftSizeLimit; // 0x74
	int AsyncIOBandwidthLimit; // 0x78
	// Where to save games?
	FString SavePath; // 0x7C
	// Where to... cache things during build?
	FString CachePath; // 0x8C
	FString CacheExt; // 0x9C
	FString ScreenshotPath; // 0xAC
	TArray<FString> Paths; // 0xBC
	TArray<FString> ScriptPaths; //?
};
BioSystem* GSys = nullptr;

// This is defined in the SDK... technically
UWorld* GWorld = nullptr;

// UTILITY METHODS ======================================================================

// Searches for the specified byte pattern, which is a 7-byte mov or lea instruction, with the 'source' operand being the address being calculated
void* findAddressLeaMov(ISharedProxyInterface* InterfacePtr, const char* name, const char* bytePattern)
{
	void* patternAddr;
	if (const auto rc = InterfacePtr->FindPattern(&patternAddr, bytePattern);
		rc != SPIReturn::Success)
	{
		writeln(L"Failed to find %hs pattern: %d / %s", name, rc, SPIReturnToString(rc));
		return nullptr; // Will be 0
	}

	// This is the address of the instruction
	const auto instruction = static_cast<BYTE*>(patternAddr);
	const auto RIPaddress = instruction + 7; // Relative Instruction Pointer (after instruction)
	const auto offset = *reinterpret_cast<int32_t*>(instruction + 3); // Offset listed in the instruction
	return RIPaddress + offset; // Added together we get the actual address
}

// Loads commonly used class pointers
void LoadCommonClassPointers(ISharedProxyInterface* InterfacePtr)
{
	// NEEDS UPDATED FOR LE1
	// 0x7ff74a9df82d DRM free | MOV RCX, qword ptr [GFileManager]
	/*auto addr = findAddressLeaMov(InterfacePtr, "GFileManager", "48 8b 0d 9c dd 67 01 ff d3 90 4c 89 6c 24 60 48 8b 4c 24 58");
	if (addr != nullptr)
	{
		GFileManager = static_cast<FFileManager*>(addr);
		writeln("Found GFileManager at %p", GFileManager);
	}
	else
	{
		writeln(" >> FAILED TO FIND GFileManager!");
	}*/

	// 0x7ff71216d5ef DRM free | MOV RAX, qword ptr [GPackageFileCache]
	/*addr = findAddressLeaMov(InterfacePtr, "GPackageFileCache", "48 8b 05 ca 8c 5e 01 48 8b 08 4c 8b 71 10 83 7b 08 ff 75 46");
	if (addr != nullptr)
	{
		GPackageFileCache = static_cast<FPackageFileCache*>(addr);
		writeln("Found GPackageFileCache at %p", GPackageFileCache);
	}
	else
	{
		writeln(" >> FAILED TO FIND GPackageFileCache!");
	}*/

	// 0x7ff7123b52fe DRM free | LEA R9, [GNatives]
	auto addr = findAddressLeaMov(InterfacePtr, "GNatives", "4c 8d 0d bb 80 39 01 48 8b f9 48 8b da 48 8b 4a 1c 44 0f b6 00");
	if (addr != nullptr)
	{
		GNatives = static_cast<tNativeFunction*>(addr);
		writeln("Found GNatives at %p", GNatives);
	}
	else
	{
		writeln(" >> FAILED TO FIND GNatives!");
	}

	// 0x7ff71243aea1 DRM free | MOV R15, [GSys]
	/*addr = findAddressLeaMov(InterfacePtr, "GSys", "4c 8b 3d b8 b8 2e 01 41 8b dd 0f 1f 44 00 00");
	if (addr != nullptr)
	{
		GSys = static_cast<BioSystem*>(addr);
		writeln("Found GSys at %p", GNatives);
	}
	else
	{
		writeln(" >> FAILED TO FIND GSys!");
	}*/

	// 0x7ff712380fd6 DRM free | MOV RCX, qword ptr [GWorld]
	/*addr = findAddressLeaMov(InterfacePtr, "GWorld", "48 8b 0d 6b 2b 47 01 e8 2e 63 30 00 0f 28 f8 48 8b 0d 5c 2b 47 01");
	if (addr != nullptr)
	{
		GWorld = static_cast<UWorld*>(addr);
		writeln("Found GWorld at %p", GWorld);
	}
	else
	{
		writeln(" >> FAILED TO FIND GWorld!");
	}*/
}

// Converts a load flags bitmask to it's string representation
std::string GetLoadFlagsString(ELoadFlags flags)
{
	if (flags == ELoadFlags::LOAD_None) return "LOAD_None"; // There is no flags set
	std::string flagStr;

	// Kind of a brute force
	if (flags & ELoadFlags::LOAD_SeekFree) flagStr.append("LOAD_SeekFree ");
	if (flags & ELoadFlags::LOAD_NoWarn) flagStr.append("LOAD_NoWarn ");
	if (flags & ELoadFlags::LOAD_Throw) flagStr.append("LOAD_Throw ");
	if (flags & ELoadFlags::LOAD_Verify) flagStr.append("LOAD_Verify ");
	if (flags & ELoadFlags::LOAD_AllowDll) flagStr.append("LOAD_AllowDll ");
	if (flags & ELoadFlags::LOAD_DisallowFiles) flagStr.append("LOAD_DisallowFiles ");
	if (flags & ELoadFlags::LOAD_NoVerify) flagStr.append("LOAD_NoVerify ");
	if (flags & ELoadFlags::LOAD_Quiet) flagStr.append("LOAD_Quiet ");
	if (flags & ELoadFlags::LOAD_FindIfFail)  flagStr.append("LOAD_FindIfFail ");
	if (flags & ELoadFlags::LOAD_MemoryReader)  flagStr.append("LOAD_MemoryReader ");
	if (flags & ELoadFlags::LOAD_RemappedPackage)  flagStr.append("LOAD_RemappedPackage ");
	if (flags & ELoadFlags::LOAD_NoRedirects)  flagStr.append("LOAD_NoRedirects");

	return flagStr;
}

// HOOK SIGNATURES =======================================

// REVERSE ENGINEERING
typedef void* (*tGenerateName)(void* param1, void* parm2, wchar_t* nameValue);
tGenerateName generateNameFromDisk = nullptr;
tGenerateName generateNameFromDisk_orig = nullptr;

// First parameter is actually an array of 2 integers
typedef void* (*tGenerateName2)(unsigned int* param1, wchar_t* nameValue, int indexValue, BOOL parm4, BOOL parm5);
tGenerateName2 sfxNameConstructor = nullptr;
tGenerateName2 sfxNameConstructor_orig = nullptr;



// Known to work --------------------

// Loading file to string
typedef bool (*tappLoadFileToString)(FString* result, wchar_t* filename, void* fileManager, unsigned int flags1);
tappLoadFileToString appLoadFileToString_orig = nullptr;
tappLoadFileToString appLoadFileToString = nullptr;

// Creating an import
typedef UObject* (*tCreateImport)(ULinkerLoad* Context, int UIndex);
tCreateImport CreateImport = nullptr;
tCreateImport CreateImport_orig = nullptr;

// Package Loading
// =========================================
typedef UPackage* (*tLoadPackage)(void* param1, wchar_t* packageName, ELoadFlags loadFlags);
tLoadPackage LoadPackage = nullptr;
tLoadPackage LoadPackage_orig = nullptr;

typedef uint32(*tAsyncLoadMethod)(UnLinker* linker, int a2, float a3);
tAsyncLoadMethod LoadPackageAsyncTick = nullptr;
tAsyncLoadMethod LoadPackageAsyncTick_orig = nullptr;

typedef void (*uLinkerPreload)(UnLinker* linker, UObject* objectToLoad);
uLinkerPreload LinkerLoadPreload = nullptr;
uLinkerPreload LinkerLoadPreload_orig = nullptr;

typedef UObject* (*tLoadPackagePersistent)(int64 param1, const wchar_t* param2, uint32 param3, int64* param4, uint32* param5);
tLoadPackagePersistent LoadPackagePersistent = nullptr;
tLoadPackagePersistent LoadPackagePersistent_orig = nullptr;

// Sets the RF_Root flag, as part of making object startup
typedef void (*tUObjectRoot)(UObject* callingObject);
tUObjectRoot RootObject = nullptr;
tUObjectRoot RootObject_orig = nullptr;

// Adds the specified package to the extra content list of global packages
typedef void (*tBioDownloadableContentAddRootedPackage)(void* extraContent, UPackage* package);
tBioDownloadableContentAddRootedPackage BioDownloadableContentRootPackage = nullptr;
tBioDownloadableContentAddRootedPackage BioDownloadableContentRootPackage_orig = nullptr;

typedef void (*tLoadSlider2DA)(void* param1);
tLoadSlider2DA LoadSlider2DA = nullptr;
tLoadSlider2DA LoadSlider2DA_orig = nullptr;

// In-game logging functions
// =========================================

// LogF
typedef void (*tFOutputDeviceLogF)(void* outputDevice, wchar_t* formatStr, void* param1, void* param2); // Used by multiple methods
tFOutputDeviceLogF FOutputDeviceLogf = nullptr;
tFOutputDeviceLogF FOutputDeviceLogf_orig = nullptr;

// LogErrorF
typedef void (*tFOutputDeviceErrorLogF)(void* outputDevice, int* code, wchar_t* formatStr, void* param1);
tFOutputDeviceErrorLogF FErrorOutputDeviceLogf = nullptr;
tFOutputDeviceErrorLogF FErrorOutputDeviceLogf_orig = nullptr;

tFOutputDeviceLogF MsgF = nullptr;
tFOutputDeviceLogF MsgF_orig = nullptr;

// Shows message to screen (disabled in release builds of game)
typedef void (*tMessageBoxF)(int messageBoxType, wchar_t* formatString, wchar_t* param3);
tMessageBoxF MsgFDialog = nullptr;
tMessageBoxF MsgFDialog_orig = nullptr;

// Called by UnrealScript
typedef void (*tLogInternalNative)(UObject* callingObject, LE1FFrame* param2);
tLogInternalNative LogInternal = nullptr;
tLogInternalNative LogInternal_orig = nullptr;

// RE
// Unknown function that was tested for registering TFCs, called reliably before Core loads
typedef void (*tLogSomething)(void* something, wchar_t* parm);
tLogSomething logMemorySmth = nullptr;
tLogSomething logMemorySmth_orig = nullptr;

// DebugLogger stuff for devs
// ==========================================
typedef UObject* (*tStaticAllocateObject)(
	UClass* objectClass, // What class of object is being instantiated?
	UObject* inObject, // The 'Outer' of the object will be set to this 
	FName a3, // Name of object?
	long long loadFlags,
	void* a5, // often 0
	void* errorDevice, //Often GError
	const wchar_t* a7, // Often 0
	void* a8, // Often 0
	void* a9); // Often 0
tStaticAllocateObject StaticAllocateObject = nullptr;
tStaticAllocateObject StaticAllocateObject_orig = nullptr;

// GAME INI FUNCTIONS
//===========================================

// Called when combining file from buffer
typedef void (*tCombineFromBuffer)(void* Context, wchar_t* filePath, FString* contents, int extra);
tCombineFromBuffer FConfigCombineFromBuffer = nullptr;
tCombineFromBuffer FConfigCombineFromBuffer_orig = nullptr;

// LE1 SPECIFIC
//===========================================

// Event Notifier is the right side HUD popups.
typedef void (*tBENAddNotice)(void* bioEventNotifier, int nType, int nContext, int nTimeToLive, int nIconIndex,
	INT srTitle, wchar_t* strTitle, int nQuantity, int nQuantMin, int nQuantMax);
tBENAddNotice EventNotifierAddNotice = nullptr;
tBENAddNotice EventNotifierAddNotice_orig = nullptr;



// MISC THINGS
// ==========================================

// Called when registering a TFC file
typedef void (*tRegisterTFC)(FString* name);
tRegisterTFC RegisterTFC = nullptr;
tRegisterTFC RegisterTFC_orig = nullptr;

// Method signature for appFindFiles
typedef void (*tFindFiles)(void* classPtr, TArray<wchar_t>* outFiles, wchar_t* searchPattern, bool files, bool directories, int flagSet);
tFindFiles FindFiles = nullptr;
tFindFiles FindFiles_orig = nullptr;