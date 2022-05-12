#pragma once
#include "../LE1-SDK/Interface.h"
#include "../LE1-SDK/Common.h"
#include "../LE1-SDK/ME3TweaksHeader.h"

#define MYHOOK "DebugLogger_"


//typedef bool (*tFPackageFileCacheFindPackageFile) (wchar_t* packageName, FGuid* guid, FString& OutFileName, wchar_t* language, bool unknown);


// USystem implementation
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

#define GSysAddress 0x7ff713726760;
BioSystem GSys; // Have to assign a bit after game startup


//struct FPackageFileCache;
//bool hookLoggingFunctions(ISharedProxyInterface* interface_ptr);
//
//
//typedef bool (*tFPackageFileCacheFindPackageFile) (wchar_t* packageName, FGuid* guid, FString& OutFileName, wchar_t* language, bool unknown);
//typedef wchar_t** (*tFPackageFileCacheGetPackageFileList) (FPackageFileCache* cache, wchar_t* FileName);
//
//// Used to lookup packages. Fully native
//struct FPackageFileCache
//{
//    virtual void Unknown0() = 0;
//    virtual void Unknown1() = 0;
//    // Finds a package file by name
//    virtual bool FindPackageFile(wchar_t* packageName, FGuid* guid, FString& OutFileName, wchar_t* language, bool unknown) = 0;
//    // Returns list of packages. In shipping build of game this just says this method shouldn't be called
//    virtual TArray<FString> GetPackageFileList(TArray<FString> outData) = 0;
//    // Not sure on the parameters for this func. It's never called by game directly. Just prints out shouldn't happen in ship
//    virtual TArray<FString> GetPackageNameList(TArray<FString> outData) = 0;
//};
//
//#define GPackageFileCacheOffset 0x7ff74c08dab0;
//
//FPackageFileCache* GPackageFileCache = nullptr; // Have to assign a bit after game startup
