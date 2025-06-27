#pragma once
#include <chrono>
#include <thread>
#include <set>
#include <map>

// This file self contains shader binding research code.

// Prints out ghidra addresses for construct functions for import
#define PRINT_FOR_GHIDRA_CONSTRUCT FALSE
// Prints out binding information
#define PRINT_BINDING_INFO TRUE



// ===============================================================================================
// TypeDefs
// ===============================================================================================
typedef void (*tFShaderParameterBind)(void*, void*, wchar_t*, BOOL);
typedef TLinkedList<FShaderTypeSub*>** (*tGetShaderTypeList)();
typedef TLinkedList<FVertexFactoryType*>** (*tGetVertexFactoryTypeList)();
typedef void (*tSubStructBind)(FArchive*, FShaderParameterMap*);
// Param 2 might be the construct compiled data?
typedef void (*tSubStruct3Bind)(FArchive*, void*, FShaderParameterMap*);
typedef FArchive* (*tFShaderSerialize)(FShader*, FArchive*, void*, void*);
typedef void (*tDeregisterShader)(FShaderType*, FShader*);
typedef FArchive* (*tFShaderParameterSerialize)(FArchive*, void*);
typedef FShader* (*tFShaderConstructFromCompiled)(FShader*, CompiledShaderData*, void*, void*);


// ===============================================================================================
// Globals
// ===============================================================================================
bool AllHooksInstalled = false;
bool IsRecording = false;

// ===============================================================================================
// HOOKING VARIABLES
// ===============================================================================================
// Used by both parameter types.
tFShaderParameterBind FShaderParameterBind = nullptr;
tFShaderParameterBind FShaderParameterBind_orig = nullptr;
tFShaderParameterBind FShaderResourceParameterBind = nullptr;
tFShaderParameterBind FShaderResourceParameterBind_orig = nullptr;
tGetShaderTypeList GetShaderTypeList = nullptr; // @ 0x253cc0 LE1
tGetVertexFactoryTypeList GetVertexFactoryTypeList = nullptr; // @ 0x62b940 LE1 
tFShaderSerialize FShaderSerialize = nullptr;
tFShaderSerialize FShaderSerialize_orig = nullptr;
// Not hooked but invokable
tDeregisterShader DeregisterShader = nullptr;
tFShaderParameterSerialize FShaderParameterSerialize = nullptr;
tFShaderParameterSerialize FShaderParameterSerialize_orig = nullptr;
tFShaderConstructFromCompiled FShaderConstructFromCompiled = nullptr;
tFShaderConstructFromCompiled FShaderConstructFromCompiled_orig = nullptr;


// ===============================================================================================
// VTables
// ===============================================================================================

void* MemoryArchiveReaderVTableStart = nullptr;
void* MemoryArchiveWriterVTableStart = nullptr;
void* FileReaderVTableStart = nullptr;
void SetVTable(void** objectStartAddress, void* newVTableStartAddress) {
	*objectStartAddress = newVTableStartAddress; // Set the vtable pointer to the new table
}

void* GetVTable(void** objectStartAddress) {
	return *objectStartAddress;
}

// ===============================================================================================
// CUSTOM OBJECTS
// ===============================================================================================
// Type of the parameter that is bound/serialized.
enum EShaderParameterType : int {
	SPT_Normal = 0,
	SPT_Resource = 1,
	SPT_VertexFactory = 2
};




// ===============================================================================================
// BINDING NAME RECORDING =======================================================================
// ===============================================================================================

// BINDING GLOBALS ======================
// Prefixes output to denote sublevels of structs.
std::wstring RecordingPrefix(L"  ");
// The current deserialized shader
FShader* DeserializedShader = nullptr;
// The address we base relative addressing off, as the game
// malloc'd it
void* BaseShaderAddress = nullptr;
// Types of shadsers we have recorded data for to filter out further recording
std::set<const wchar_t*> recordedTypes;
// A dummy uniform expression set that we only allocate once and feed into compiled
// construtor. It doesn't have any data.
FUniformExpressionSet DummySet{};
// Map of Shader Type -> Map of Address->Type/Name combo.
// Map
//   ShaderType -> Map 
//                    Offset -> Type, ParameterName
std::map<std::wstring, std::map<DWORD, std::tuple<EShaderParameterType,std::wstring>>> bindingMap;


// BINDING METHODS AND HOOKS ===========
void FShaderParameterBind_hook(void* varAddr, void* parameterMap, wchar_t* parameterName, BOOL isOptional) {
	auto offset = (long long)varAddr - (long long)BaseShaderAddress;
	if (PRINT_BINDING_INFO) {
		std::wcout << RecordingPrefix.c_str() << L"FShaderParameter " << parameterName << L" @ " << std::hex << offset << std::endl;
	}
	// FShaderResourceParameterBind_orig(varAddr, parameterMap, parameterName, TRUE); // true suppresses messages
}

void FShaderResourceParameterBind_hook(void* varAddr, void* parameterMap, wchar_t* parameterName, BOOL isOptional) {
	auto offset = (long long)varAddr - (long long)BaseShaderAddress;
	if (PRINT_BINDING_INFO) {
		std::wcout << RecordingPrefix.c_str() << L"FShaderResourceParameter " << parameterName << L" @ " << std::hex << offset << std::endl;
	}

	// FShaderResourceParameterBind_orig(varAddr, parameterMap, parameterName, TRUE); // true suppresses messages
}


// FSceneTextureShaderParameters -----------------------------------------------------------------
const std::wstring FSceneTextureShaderParametersPrefix = L"[FSceneTextureShaderParameters]";
tSubStructBind FSceneTextureShaderParametersBind = nullptr;
tSubStructBind FSceneTextureShaderParametersBind_orig = nullptr;
void FSceneTextureShaderParametersBind_hook(FArchive* Ar, FShaderParameterMap* Map) {
	if (IsRecording) {
		auto originalPrefix = RecordingPrefix;
		RecordingPrefix = RecordingPrefix.append(FSceneTextureShaderParametersPrefix);
		FSceneTextureShaderParametersBind_orig(Ar, Map);
		RecordingPrefix = originalPrefix;
	}
	else {
		FSceneTextureShaderParametersBind_orig(Ar, Map);
	}
}

// FLightShaftPixelShaderParameters --------------------------------------------------------------
const std::wstring FLightShaftPixelShaderParametersPrefix = L"[FLightShaftPixelShaderParameters]";
tSubStructBind FLightShaftPixelShaderParametersBind = nullptr;
tSubStructBind FLightShaftPixelShaderParametersBind_orig = nullptr;
void FLightShaftPixelShaderParametersBind_hook(FArchive* Ar, FShaderParameterMap* Map) {
	if (IsRecording) {
		auto originalPrefix = RecordingPrefix;
		RecordingPrefix = RecordingPrefix.append(FLightShaftPixelShaderParametersPrefix);
		FLightShaftPixelShaderParametersBind_orig(Ar, Map);
		RecordingPrefix = originalPrefix;
	}
	else {
		FLightShaftPixelShaderParametersBind_orig(Ar, Map);
	}
}

// FDOFShaderParameters --------------------------------------------------------------
const std::wstring FDOFShaderParametersPrefix = L"[FDOFShaderParameters]";
tSubStructBind FDOFShaderParametersBind = nullptr;
tSubStructBind FDOFShaderParametersBind_orig = nullptr;
void FDOFShaderParametersBind_hook(FArchive* Ar, FShaderParameterMap* Map) {
	if (IsRecording) {
		auto originalPrefix = RecordingPrefix;
		RecordingPrefix = RecordingPrefix.append(FDOFShaderParametersPrefix);
		FDOFShaderParametersBind_orig(Ar, Map);
		RecordingPrefix = originalPrefix;
	}
	else {
		FDOFShaderParametersBind_orig(Ar, Map);
	}
}

// FMaterialPixelShaderParameters --------------------------------------------------------------
const std::wstring FMaterialPixelShaderParametersPrefix = L"[FMaterialPixelShaderParameters]";
tSubStruct3Bind FMaterialPixelShaderParametersBind = nullptr;
tSubStruct3Bind FMaterialPixelShaderParametersBind_orig = nullptr;
void FMaterialPixelShaderParametersBind_hook(FArchive* Ar, void* unk2, FShaderParameterMap* Map) {
	if (IsRecording) {
		auto originalPrefix = RecordingPrefix;
		RecordingPrefix = RecordingPrefix.append(FMaterialPixelShaderParametersPrefix);
		FMaterialPixelShaderParametersBind_orig(Ar, unk2, Map);
		RecordingPrefix = originalPrefix;
	}
	else {
		FMaterialPixelShaderParametersBind_orig(Ar, unk2, Map);
	}
}

// FSpotLightPolicy_ModShadowPixelParamsType --------------------------------------------------------------
const std::wstring FSpotLightPolicy_ModShadowPixelParamsTypePrefix = L"[FSpotLightPolicy_ModShadowPixelParamsType]";
tSubStructBind FSpotLightPolicy_ModShadowPixelParamsTypeBind = nullptr;
tSubStructBind FSpotLightPolicy_ModShadowPixelParamsTypeBind_orig = nullptr;
void FSpotLightPolicy_ModShadowPixelParamsTypeBind_hook(FArchive* Ar, FShaderParameterMap* Map) {
	if (IsRecording) {
		auto originalPrefix = RecordingPrefix;
		RecordingPrefix = RecordingPrefix.append(FSpotLightPolicy_ModShadowPixelParamsTypePrefix);
		FSpotLightPolicy_ModShadowPixelParamsTypeBind_orig(Ar, Map);
		RecordingPrefix = originalPrefix;
	}
	else {
		FSpotLightPolicy_ModShadowPixelParamsTypeBind_orig(Ar, Map);
	}
}

// FAmbientOcclusionParams --------------------------------------------------------------
const std::wstring FAmbientOcclusionParamsPrefix = L"[FAmbientOcclusionParams]";
tSubStructBind FAmbientOcclusionParamsBind = nullptr;
tSubStructBind FAmbientOcclusionParamsBind_orig = nullptr;
void FAmbientOcclusionParamsBind_hook(FArchive* Ar, FShaderParameterMap* Map) {
	if (IsRecording) {
		auto originalPrefix = RecordingPrefix;
		RecordingPrefix = RecordingPrefix.append(FAmbientOcclusionParamsPrefix);
		FAmbientOcclusionParamsBind_orig(Ar, Map);
		RecordingPrefix = originalPrefix;
	}
	else {
		FAmbientOcclusionParamsBind_orig(Ar, Map);
	}
}

// FMaterialBaseShaderParameters --------------------------------------------------------------
const std::wstring FMaterialBaseShaderParametersPrefix = L"[FMaterialBaseShaderParameters]";
tSubStruct3Bind FMaterialBaseShaderParametersBind = nullptr;
tSubStruct3Bind FMaterialBaseShaderParametersBind_orig = nullptr;
void FMaterialBaseShaderParametersBind_hook(FArchive* Ar, void* parm2,  FShaderParameterMap* Map) {
	if (IsRecording) {
		auto originalPrefix = RecordingPrefix;
		RecordingPrefix = RecordingPrefix.append(FMaterialBaseShaderParametersPrefix);
		FMaterialBaseShaderParametersBind_orig(Ar, parm2, Map);
		RecordingPrefix = originalPrefix;
	}
	else {
		FMaterialBaseShaderParametersBind_orig(Ar, parm2, Map);
	}
}

// FFogVolumeVertexShaderParameters --------------------------------------------------------------
const std::wstring FFogVolumeVertexShaderParametersPrefix = L"[FFogVolumeVertexShaderParameters]";
tSubStructBind FFogVolumeVertexShaderParametersBind = nullptr;
tSubStructBind FFogVolumeVertexShaderParametersBind_orig = nullptr;
void FFogVolumeVertexShaderParametersBind_hook(FArchive* Ar, FShaderParameterMap* Map) {
	if (IsRecording) {
		auto originalPrefix = RecordingPrefix;
		RecordingPrefix = RecordingPrefix.append(FFogVolumeVertexShaderParametersPrefix);
		FFogVolumeVertexShaderParametersBind_orig(Ar, Map);
		RecordingPrefix = originalPrefix;
	}
	else {
		FFogVolumeVertexShaderParametersBind_orig(Ar, Map);
	}
}

// FHeightFogVertexShaderParameters --------------------------------------------------------------
const std::wstring FHeightFogVertexShaderParametersPrefix = L"[FHeightFogVertexShaderParameters]";
tSubStructBind FHeightFogVertexShaderParametersBind = nullptr;
tSubStructBind FHeightFogVertexShaderParametersBind_orig = nullptr;
void FHeightFogVertexShaderParametersBind_hook(FArchive* Ar, FShaderParameterMap* Map) {
	if (IsRecording) {
		auto originalPrefix = RecordingPrefix;
		RecordingPrefix = RecordingPrefix.append(FHeightFogVertexShaderParametersPrefix);
		FHeightFogVertexShaderParametersBind_orig(Ar, Map);
		RecordingPrefix = originalPrefix;
	}
	else {
		FHeightFogVertexShaderParametersBind_orig(Ar, Map);
	}
}

// FDirectionalLightPolicyPixelParameters --------------------------------------------------------------
const std::wstring FDirectionalLightPolicyPixelParametersPrefix = L"[FDirectionalLightPolicyPixelParameters]";
tSubStructBind FDirectionalLightPolicyPixelParametersBind = nullptr;
tSubStructBind FDirectionalLightPolicyPixelParametersBind_orig = nullptr;
void FDirectionalLightPolicyPixelParametersBind_hook(FArchive* Ar, FShaderParameterMap* Map) {
	if (IsRecording) {
		auto originalPrefix = RecordingPrefix;
		RecordingPrefix = RecordingPrefix.append(FDirectionalLightPolicyPixelParametersPrefix);
		FDirectionalLightPolicyPixelParametersBind_orig(Ar, Map);
		RecordingPrefix = originalPrefix;
	}
	else {
		FDirectionalLightPolicyPixelParametersBind_orig(Ar, Map);
	}
}

// FHBAOShaderParameters --------------------------------------------------------------
const std::wstring FHBAOShaderParametersPrefix = L"[FHBAOShaderParameters]";
tSubStructBind FHBAOShaderParametersBind = nullptr;
tSubStructBind FHBAOShaderParametersBind_orig = nullptr;
void FHBAOShaderParametersBind_hook(FArchive* Ar, FShaderParameterMap* Map) {
	if (IsRecording) {
		auto originalPrefix = RecordingPrefix;
		RecordingPrefix = RecordingPrefix.append(FHBAOShaderParametersPrefix);
		FHBAOShaderParametersBind_orig(Ar, Map);
		RecordingPrefix = originalPrefix;
	}
	else {
		FHBAOShaderParametersBind_orig(Ar, Map);
	}
}

// FGammaShaderParameters --------------------------------------------------------------
const std::wstring FGammaShaderParametersPrefix = L"[FGammaShaderParameters]";
tSubStructBind FGammaShaderParametersBind = nullptr;
tSubStructBind FGammaShaderParametersBind_orig = nullptr;
void FGammaShaderParametersBind_hook(FArchive* Ar, FShaderParameterMap* Map) {
	if (IsRecording) {
		auto originalPrefix = RecordingPrefix;
		RecordingPrefix = RecordingPrefix.append(FGammaShaderParametersPrefix);
		FGammaShaderParametersBind_orig(Ar, Map);
		RecordingPrefix = originalPrefix;
	}
	else {
		FGammaShaderParametersBind_orig(Ar, Map);
	}
}

// FColorRemapShaderParameters --------------------------------------------------------------
const std::wstring FColorRemapShaderParametersPrefix = L"[FColorRemapShaderParameters]";
tSubStructBind FColorRemapShaderParametersBind = nullptr;
tSubStructBind FColorRemapShaderParametersBind_orig = nullptr;
void FColorRemapShaderParametersBind_hook(FArchive* Ar, FShaderParameterMap* Map) {
	if (IsRecording) {
		auto originalPrefix = RecordingPrefix;
		RecordingPrefix = RecordingPrefix.append(FColorRemapShaderParametersPrefix);
		FColorRemapShaderParametersBind_orig(Ar, Map);
		RecordingPrefix = originalPrefix;
	}
	else {
		FColorRemapShaderParametersBind_orig(Ar, Map);
	}
}

FArchive* FShaderSerialize_hook(FShader* shader, FArchiveFileReader* ar, void* unk3, void* unk4) {
	IsRecording = false;

	while (AllHooksInstalled == false) {
		std::cout << "Waiting for hooks to install...\n";
		std::this_thread::sleep_for(200ms);
	}

	auto res = FShaderSerialize_orig(shader, ar, unk3, unk4);

	// This is at the end of the original shader serialization func;
	// we should not be at the position where we read the parameters
	auto pos = ar->VTable->Tell(ar);

	if (recordedTypes.find(shader->Type->Name) == recordedTypes.end()) {
		if (PRINT_BINDING_INFO) {
			std::wcout << shader->Type->Name << std::endl;
		}
		IsRecording = true;

		// Assign this here, we will access it later in the hooks
		DeserializedShader = shader;

		// Step 1: Find the bind points for the shader.
		// We do a fake construct from compiled call, as we have hooked the bind methods.
		// We then record the calls to bind, calculating the offset from the address we record when
		// ConstructFromCompiled is called and the FShader is malloc'd.

		VertexCompiledShaderData compiledInfo{};
		FShaderParameterMap parameterMap{}; // empty parameter map. Don't care about uniform expressions.
		// Just kidding. A few shaders need it for who knows why.
		parameterMap.UniformExpressionSet = &DummySet;
		compiledInfo.ParameterMap = &parameterMap;
		if (shader->Target.Frequency == SF_VERTEX) {
			// Vertex shaders need a vertex factory, not sure if it matters which one.
			compiledInfo.VertexFactoryType = (*GetVertexFactoryTypeList())->CurrentItem;
		}
		int unk2 = 0;
		int unk3 = 0;
		int unk4 = 0;

		if (PRINT_FOR_GHIDRA_CONSTRUCT) {
			// For printing out a table you can import with ghidra's ImportSymbols script. It doesn't do namespaces though.
			auto funcAddr = *(shader->Type->ConstructCompiledRef);
			std::wcout << shader->Type->Name << L"::ConstructFromCompiled 0x" << std::hex << funcAddr << L" f" << std::endl;
		}
		else 
		{
			// This will invoke the ::Bind hooks
			shader->Type->ConstructCompiledRef((CompiledShaderData*)&compiledInfo, &unk2, &unk3, &unk4);
		}
		recordedTypes.insert(shader->Type->Name);
	}
	IsRecording = false;
	return res;
}


// ===============================================================================================
// SERIALIZATION RECORDING =======================================================================
// ===============================================================================================

INT basePosition = 0;

FArchive* FShaderParameterSerialize_hook(FArchive* ar, void* param) {
	if (IsRecording) {
		auto offset = ar->VTable->Tell(ar) - basePosition;
		// std::cout << "  Serialize parameter at " << std::hex << offset << std::endl;
	}
	return FShaderParameterSerialize_orig(ar, param);
}

FShader* FShaderConstructFromCompiled_hook(FShader* inShader, CompiledShaderData* compiledInfo, void* unk3, void* unk4)
{
	// This method normally sets up a freshly malloc'd shader object from the compiledInfo object.
	if (IsRecording) {
		// We don't care about the malloc'd shader. Use the one we already have set up.
		*inShader = *DeserializedShader;
		BaseShaderAddress = inShader;
		return inShader;
	}
	else
	{
		return FShaderConstructFromCompiled_orig(inShader, compiledInfo, unk3, unk4);
	}
}



typedef void (*tSFXNameConstructor)(FName* outValue, const wchar_t* nameValue, int nameNumber, BOOL createIfNotFoundMaybe, BOOL unk2);
tSFXNameConstructor _CreateName = nullptr;
void CreateName(FName* outName, const wchar_t* nameValue, int num = 0) {
	_CreateName(outName, nameValue, num, TRUE, 0);
}

// For creating archive proxies
typedef FArchiveProxy* (*tCreateArchiveProxy)(FArchiveProxy* self, FArchive* arcToProxy);
tCreateArchiveProxy CreateArchiveProxy = nullptr;

// Set to FArchiveProxy vtable
void* StringArchiveProxyVTableStart = nullptr;


// ================================================================================================
// ASI INITIALIZATION
// ================================================================================================
// This method is invoke on attach, set up your hooks here.
// THIS ASI DOES NOT WORK IF OTHER ASIS HOOK THE SAME FUNCTIONS, WE DON'T DO POSTHOOK. At least I think
// the SPI system doesn't know how to hook a hook
bool hookShaderResearch(ISharedProxyInterface* InterfacePtr) {

	// PUT THIS FIRST AS SHADER SERIALIZATION HAPPENS EARLY!
	FShaderSerialize = (tFShaderSerialize)SDKInitializer::Instance()->GetAbsoluteAddress(0x259b20); // LE1
	InterfacePtr->InstallHook("FShaderSerialize", FShaderSerialize, FShaderSerialize_hook, (void**)&FShaderSerialize_orig);

	DeregisterShader = (tDeregisterShader)SDKInitializer::Instance()->GetAbsoluteAddress(0x24e2c0); // LE1

	FShaderParameterSerialize = (tFShaderParameterSerialize)SDKInitializer::Instance()->GetAbsoluteAddress(0x249230); // LE1
	InterfacePtr->InstallHook("FShaderParameterSerialize", FShaderParameterSerialize, FShaderParameterSerialize_hook, (void**)&FShaderParameterSerialize_orig);

	FSceneTextureShaderParametersBind = (tSubStructBind)SDKInitializer::Instance()->GetAbsoluteAddress(0x774380); // LE1
	InterfacePtr->InstallHook("FSceneTextureShaderParametersBind", FSceneTextureShaderParametersBind, FSceneTextureShaderParametersBind_hook, (void**)&FSceneTextureShaderParametersBind_orig);

	FLightShaftPixelShaderParametersBind = (tSubStructBind)SDKInitializer::Instance()->GetAbsoluteAddress(0x1deef0); // LE1
	InterfacePtr->InstallHook("FLightShaftPixelShaderParametersBind", FLightShaftPixelShaderParametersBind, FLightShaftPixelShaderParametersBind_hook, (void**)&FLightShaftPixelShaderParametersBind_orig);

	FDOFShaderParametersBind = (tSubStructBind)SDKInitializer::Instance()->GetAbsoluteAddress(0x1b4b20); // LE1
	InterfacePtr->InstallHook("FDOFShaderParametersBind", FDOFShaderParametersBind, FDOFShaderParametersBind_hook, (void**)&FDOFShaderParametersBind_orig);

	FMaterialPixelShaderParametersBind = (tSubStruct3Bind)SDKInitializer::Instance()->GetAbsoluteAddress(0x672970); // LE1
	InterfacePtr->InstallHook("FMaterialPixelShaderParametersBind", FMaterialPixelShaderParametersBind, FMaterialPixelShaderParametersBind_hook, (void**)&FMaterialPixelShaderParametersBind_orig);

	FSpotLightPolicy_ModShadowPixelParamsTypeBind = (tSubStructBind)SDKInitializer::Instance()->GetAbsoluteAddress(0x263950); // LE1
	InterfacePtr->InstallHook("FSpotLightPolicy_ModShadowPixelParamsTypeBind", FSpotLightPolicy_ModShadowPixelParamsTypeBind, FSpotLightPolicy_ModShadowPixelParamsTypeBind_hook, (void**)&FSpotLightPolicy_ModShadowPixelParamsTypeBind_orig);

	FAmbientOcclusionParamsBind = (tSubStructBind)SDKInitializer::Instance()->GetAbsoluteAddress(0x7c3760); // LE1
	InterfacePtr->InstallHook("FAmbientOcclusionParamsBind", FAmbientOcclusionParamsBind, FAmbientOcclusionParamsBind_hook, (void**)&FAmbientOcclusionParamsBind_orig);

	// This seems to not be in LEC as a struct but the patterns are there. LE1 has this in its own function.
	FMaterialBaseShaderParametersBind = (tSubStruct3Bind)SDKInitializer::Instance()->GetAbsoluteAddress(0x672f40); // LE1
	InterfacePtr->InstallHook("FMaterialBaseShaderParametersBind", FMaterialBaseShaderParametersBind, FMaterialBaseShaderParametersBind_hook, (void**)&FMaterialBaseShaderParametersBind_orig);

	FFogVolumeVertexShaderParametersBind = (tSubStructBind)SDKInitializer::Instance()->GetAbsoluteAddress(0x822100); // LE1
	InterfacePtr->InstallHook("FFogVolumeVertexShaderParametersBind", FFogVolumeVertexShaderParametersBind, FFogVolumeVertexShaderParametersBind_hook, (void**)&FFogVolumeVertexShaderParametersBind_orig);

	FShaderConstructFromCompiled = (tFShaderConstructFromCompiled)SDKInitializer::Instance()->GetAbsoluteAddress(0x247300); // LE1
	InterfacePtr->InstallHook("FShaderConstructFromCompiled", FShaderConstructFromCompiled, FShaderConstructFromCompiled_hook, (void**)&FShaderConstructFromCompiled_orig);

	FHeightFogVertexShaderParametersBind = (tSubStructBind)SDKInitializer::Instance()->GetAbsoluteAddress(0x742bd0); // LE1
	InterfacePtr->InstallHook("FHeightFogVertexShaderParametersBind", FHeightFogVertexShaderParametersBind, FHeightFogVertexShaderParametersBind_hook, (void**)&FHeightFogVertexShaderParametersBind_orig);

	FDirectionalLightPolicyPixelParametersBind = (tSubStructBind)SDKInitializer::Instance()->GetAbsoluteAddress(0x1bca80); // LE1
	InterfacePtr->InstallHook("FDirectionalLightPolicyPixelParametersBind", FDirectionalLightPolicyPixelParametersBind, FDirectionalLightPolicyPixelParametersBind_hook, (void**)&FDirectionalLightPolicyPixelParametersBind_orig);

	FHBAOShaderParametersBind = (tSubStructBind)SDKInitializer::Instance()->GetAbsoluteAddress(0x7c37e0); // LE1
	InterfacePtr->InstallHook("FHBAOShaderParametersBind", FHBAOShaderParametersBind, FHBAOShaderParametersBind_hook, (void**)&FHBAOShaderParametersBind_orig);

	FGammaShaderParametersBind = (tSubStructBind)SDKInitializer::Instance()->GetAbsoluteAddress(0x27cc80); // LE1
	InterfacePtr->InstallHook("FGammaShaderParametersBind", FGammaShaderParametersBind, FGammaShaderParametersBind_hook, (void**)&FGammaShaderParametersBind_orig);

	FColorRemapShaderParametersBind = (tSubStructBind)SDKInitializer::Instance()->GetAbsoluteAddress(0x27cb80); // LE1
	InterfacePtr->InstallHook("FColorRemapShaderParametersBind", FColorRemapShaderParametersBind, FColorRemapShaderParametersBind_hook, (void**)&FColorRemapShaderParametersBind_orig);


	// Todo convert to direct binding
	// FShaderParameter::Bind 0x24C3A0 in LE1
	INIT_FIND_PATTERN_POSTHOOK(FShaderParameterBind, /*"48 89 5c 24 10*/ "57 48 83 ec 30 4c 8b d2 48 8d 41 04 49 8b d8 48 8d 54 24 40 48 89 54 24 28 41 8b f9 4c 8d 49 02 48 89 44 24 20");
	INIT_HOOK_PATTERN(FShaderParameterBind);

	// FShaderResourceParameter::Bind 0x24C430 in LE1
	INIT_FIND_PATTERN_POSTHOOK(FShaderResourceParameterBind, /*"48 89 5c 24 10*/ "57 48 83 ec 30 49 8b d8 48 8d 41 04 4c 8b da 48 89 44 24 28 4c 8d 51 02");
	INIT_HOOK_PATTERN(FShaderResourceParameterBind);

	// Direct addresses
	GetShaderTypeList = (tGetShaderTypeList)SDKInitializer::Instance()->GetAbsoluteAddress(0x253cc0); // LE1
	GetVertexFactoryTypeList = (tGetVertexFactoryTypeList)SDKInitializer::Instance()->GetAbsoluteAddress(0x62b940); // LE1
	MemoryArchiveReaderVTableStart = SDKInitializer::Instance()->GetAbsoluteAddress(0x1427428); // LE1
	MemoryArchiveWriterVTableStart = SDKInitializer::Instance()->GetAbsoluteAddress(0xfbbdb0); // LE1
	FileReaderVTableStart = SDKInitializer::Instance()->GetAbsoluteAddress(0xfb8c38); // LE1
	StringArchiveProxyVTableStart = SDKInitializer::Instance()->GetAbsoluteAddress(0x11b03a0); // LE1
	CreateArchiveProxy = (tCreateArchiveProxy)SDKInitializer::Instance()->GetAbsoluteAddress(0x81d750); // LE1
	_CreateName = (tSFXNameConstructor)SDKInitializer::Instance()->GetAbsoluteAddress(0xdd800); // LE1

	// Globals
	GFileManager = (FFileManager**)SDKInitializer::Instance()->GetAbsoluteAddress(0x16b6758);
	GError = (FArchive**)SDKInitializer::Instance()->GetAbsoluteAddress(0x16b66c8);

	AllHooksInstalled = true;
	return true;


	// OLD CODE ===================
	// Get a vertex factory as it seems necessary...
	auto vertexFactoryTypeListPointer = GetVertexFactoryTypeList();
	auto shaderTypeListPointer = GetShaderTypeList();
	std::this_thread::sleep_for(1500ms);
	auto vertexFactoryTypeList = *vertexFactoryTypeListPointer;

	auto shaderTypeList = *shaderTypeListPointer;
	std::cout << "LE1 Shader Types\n";
	while (shaderTypeList != nullptr) {
		auto serializableShader = shaderTypeList->CurrentItem->ConstructSerializedRef(shaderTypeList->CurrentItem);

		// Get the address of the Serialize function.
		auto vtable = (char*)GetVTable((void**)serializableShader);
		auto serialize = (void**)(vtable + 0x40);
		auto deref = *serialize; // Some shaders don't have parameters, so they just serialize like normal

		if (deref == FShaderSerialize) {
			// No parameters on this shader type.
			std::wcout << shaderTypeList->CurrentItem->Name << L" [No Parameters]" << std::endl;
		}
		else
		{
			TArray<BYTE> BaseData;
			DWORD zero = 0;
			FMemoryWriter ArW(BaseData);
			SetVTable((void**)&ArW, MemoryArchiveWriterVTableStart);

			// We have to serialize names as strings, otherwise lookup seems to fail. 
			// Wrap writer in names-only serializer
			FArchiveProxy ProxyArchive;
			CreateArchiveProxy((FArchiveProxy*)&ProxyArchive, &ArW);
			SetVTable((void**)&ProxyArchive, StringArchiveProxyVTableStart);

			// Write a fake FShader header block.
			BYTE platform = 5;
			BYTE frequency = shaderTypeList->CurrentItem->Frequency;

			ProxyArchive.VTable->Serialize(&ProxyArchive, &platform, 1);
			ProxyArchive.VTable->Serialize(&ProxyArchive, &frequency, 1);

			// Shader File Size
			DWORD four = 4;
			ProxyArchive.VTable->SerializeInt(&ProxyArchive, four, 60000);
			// Shader bytes (dummy)
			ProxyArchive.VTable->SerializeInt(&ProxyArchive, zero, 60000);
			ProxyArchive.VTable->SerializeInt(&ProxyArchive, zero, 60000); // Parameter Map CRC

			// Guid
			DWORD one = 1;
			ProxyArchive.VTable->SerializeInt(&ProxyArchive, one, 60000);
			ProxyArchive.VTable->SerializeInt(&ProxyArchive, one, 60000);
			ProxyArchive.VTable->SerializeInt(&ProxyArchive, one, 60000);
			ProxyArchive.VTable->SerializeInt(&ProxyArchive, one, 60000);

			FName shaderName;
			CreateName(&shaderName, shaderTypeList->CurrentItem->Name);
			ProxyArchive.VTable->SerializeName(&ProxyArchive, shaderName);

			// Num Instructions
			ProxyArchive.VTable->SerializeInt(&ProxyArchive, zero, 60000);

			// Shader Parameters follow.
			if (shaderTypeList->CurrentItem->Frequency == SF_VERTEX) {
				// It will have a vertex factory parameter
				FName vfName;
				CreateName(&vfName, vertexFactoryTypeList->CurrentItem->Name);
				ProxyArchive.VTable->SerializeName(&ProxyArchive, vfName);
			}

			// Write a bunch of data
			for (int i = 400; i > 0; i--) {
				ProxyArchive.VTable->SerializeInt(&ProxyArchive, zero, sizeof(DWORD));
			}

			// DEBUG - Write out Data
			//auto writer = (*GFileManager)->CreateFileWriter(L"C:\\users\\mgame\\fakeshader.bin", 0, GError, 10000000);
			//writer->VTable->Serialize(writer, BaseData.Data, BaseData.Count);
			//writer->VTable->Destructor(writer); // flushes


			FMemoryReader ArR(BaseData);
			SetVTable((void**)&ArR, MemoryArchiveReaderVTableStart);

			// We have to serialize names as strings, otherwise lookup seems to fail. 
			// Wrap reader in names-only serializer
			FArchiveProxy ProxyArchiveR;
			CreateArchiveProxy((FArchiveProxy*)&ProxyArchiveR, &ArR);
			SetVTable((void**)&ProxyArchiveR, StringArchiveProxyVTableStart);

			std::wcout << shaderTypeList->CurrentItem->Name << L" " << deref << std::endl;
			serializableShader->Serialize(ProxyArchiveR);

		}


		shaderTypeList = shaderTypeList->NextItem;
	}

	return true;
}

