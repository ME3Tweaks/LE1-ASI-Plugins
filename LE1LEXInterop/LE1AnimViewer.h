#pragma once
// typedefs
typedef bool (*tIsWindowFocused)();

class LEAnimViewer
{
private:
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
	static bool HandleCommand(char* command)
	{
		// All AnimViwere commands start with ANIMV_
		if (!startsWith("ANIMV_", command))
			return false;

		if (startsWith("ANIMV_ALLOW_WINDOW_PAUSE", command))
		{
			AllowWindowPausing(true);
			return true;
		}
		else if (startsWith("ANIMV_DISALLOW_WINDOW_PAUSE", command))
		{
			AllowWindowPausing(false);
			return true;
		}

#ifdef LE1
		else if (startsWith("CHANGEPAWN ", command))
		{
			// Test code.
			auto subCommand = command + 11;

			auto spGame = static_cast<ABioSPGame*>(FindObjectOfType(ABioSPGame::StaticClass()));
			FVector v = FVector();
			v.X = -4300;
			v.Y = -6280;
			v.Z = -26560;
			FRotator r = FRotator();
			// This doesn't work. IDK why
			auto pawn = spGame->SpawnPawn(L"BIOA_JUG80_00_DSG.BIOG_Pilot_Hench_C.hench_pilot", v, r, false);

			return true;

		}
#endif

		return false;
	}

	// Return true if other features should also be able to handle this function call
	// Return false if other features shouldn't be able to also handle this function call
	static bool ProcessEvent(UObject* Context, UFunction* Function, void* Parms, void* Result)
	{
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