#pragma once
// typedefs
typedef bool (*tIsWindowFocused)();

class LEAnimViewer
{
private:

#ifdef LE1
	// Memory pre-allocated for use with passing to kismet, since FString doesn't copy it
	static wchar_t ActorFullMemoryPath[1024];
	static std::wstring ActorMemoryPath;
	static std::wstring ActorPackageFile;
#endif

	// BioWorldInfo internal native
	static tIsWindowFocused IsWindowFocused;
	static tIsWindowFocused IsWindowFocused_orig;

	static bool IsWindowFocused_hook()
	{
		// We don't report that the window is not focused, ever.
		return true;
	}

	// Return value is not used; it's only to allow usage of macro
	static bool AllowWindowPausing(bool allow)
	{
		auto InterfacePtr = SharedData::SPIInterfacePtr;
		if (allow)
		{
			InterfacePtr->UninstallHook("IsWindowFocused");
		}
		else
		{
			INIT_FIND_PATTERN_POSTHOOK(IsWindowFocused, /*"48 83 ec 28 48*/ "8b 05 5d 3f c2 00 48 85 c0 74 2c 48 8b 88 c8 07 00 00 48 85 c9 74 20 48 8b 89 68 01 00 00");
			INIT_HOOK_PATTERN(IsWindowFocused);
		}
		return true;
	}

	static void Initialize(ISharedProxyInterface* InterfacePtr)
	{
		AllowWindowPausing(false);
	}

public:

	// Return true if handled.
	// Return false if not handled.
	static bool HandleCommand(std::string command)
	{
		// All AnimViwere commands start with ANIMV_
		if (!stringStartsWith("ANIMV_", command))
			return false;

		if (stringStartsWith("ANIMV_ALLOW_WINDOW_PAUSE", command))
		{
			AllowWindowPausing(true);
			return true;
		}
		else if (stringStartsWith("ANIMV_DISALLOW_WINDOW_PAUSE", command))
		{
			AllowWindowPausing(false);
			return true;
		}

#ifdef LE1
		else if (stringStartsWith("ANIMV_CHANGE_PAWN ", command))
		{
			// Test code.
			auto subCommand = GetCommandParam(command);
			auto actorFullPath = s2ws(GetCommandParam(command));

			// Copy the string to the buffer
			wcscpy(LEAnimViewer::ActorFullMemoryPath, actorFullPath.c_str());

			// CauseEvent: ChangeActor
			//auto player = reinterpret_cast<ABioPlayerController*>(FindObjectOfType(ABioPlayerController::StaticClass()));
			//if (player)
			//{
			//	FName foundName;
			//	StaticVariables::CreateName(L"ChangeActor", 0, & foundName);
			//	player->CauseEvent(foundName);
			//}
			//return true;

			//ActorPackageFile = s2ws(GetCommandParam(command));
			//ActorMemoryPath = s2ws(GetCommandParam(command));



			return true;

		}
#endif

		return false;
	}

	// Return true if other features should also be able to handle this function call
	// Return false if other features shouldn't be able to also handle this function call
	static bool ProcessEvent(UObject* Context, UFunction* Function, void* Parms, void* Result)
	{
		if (!strcmp(Context->Class->GetName(), "LEXSeqAct_SpawnPawn") && !strcmp(Function->GetName(), "Activated"))
		{
			// Make sure the variables are set
			//SetSequenceString(static_cast<USequenceOp*>(Context), L"Type", LEAnimViewer::ActorFullMemoryPath);

			auto spGame = static_cast<ABioSPGame*>(FindObjectOfType(ABioSPGame::StaticClass()));
			spGame->ServerOptions = FString(ActorFullMemoryPath);
			auto t = "";
			//FVector v = FVector();
			//v.X = -4013;
			//v.Y = -6046;
			//v.Z = -26559;
			//FRotator r = FRotator();

			//auto pf = FString(ActorPackageFile.data());
			//spGame->PreloadPackage(pf); // Load into memory

			//// How do we know when this is done...?
			////std::this_thread::sleep_for(std::chrono::seconds(1));

			//auto mp = FString(ActorMemoryPath.data());
			//auto pawn = spGame->SpawnPawn(mp, v, r, false);
			//FName tag;
			//StaticVariables::CreateName(L"AnimatedActor", 0, &tag);
			//pawn->Tag = tag;
		}

		//if (!strcmp(Context->Class->GetName(), "LEXSeqAct_SpawnPawn") && !strcmp(Function->GetName(), "HookedSpawn"))
		//{
		//	// Make sure the variables are set
		//	SetSequenceString(static_cast<USequenceOp*>(Context), L"Type", LEAnimViewer::ActorFullMemoryPath);
		//}

		// Still process it
		return true;
	}


private:
	static bool initialized;
	static void DumpActors() {

	}

};

// Static variable initialization
bool LEAnimViewer::initialized = false;
tIsWindowFocused LEAnimViewer::IsWindowFocused = nullptr;
tIsWindowFocused LEAnimViewer::IsWindowFocused_orig = nullptr;

#ifdef LE1
wchar_t LEAnimViewer::ActorFullMemoryPath[1024];
std::wstring LEAnimViewer::ActorMemoryPath = L"BIOA_NOR_C.HMM.hench_pilot";
std::wstring LEAnimViewer::ActorPackageFile = L"BIOA_NOR10_01_DS1";

#endif