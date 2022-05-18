#pragma once
class LE1PathfindingGPS
{
private:


public:
	// If the GPS is currently active and should be sending messages to LEX
	static bool playerGPSActive;

	// Return true if handled.
	// Return false if not handled.
	static bool HandleCommand(char* command)
	{
		if (startsWith("ACTIVATE_GPS", command))
		{
			playerGPSActive = true;
			return true;
		}
		if (startsWith("DEACTIVATE_GPS", command))
		{
			playerGPSActive = false;
			return true;
		}

		return false; // Was not handled
	}

	// Return true if other features should also be able to handle this function call
	// Return false if other features shouldn't be able to also handle this function call
	static bool ProcessEvent(UObject* Context, UFunction* Function, void* Parms, void* Result)
	{
		if (LE1PathfindingGPS::playerGPSActive && IsA<ABioPlayerController>(Context) && strcmp(Function->GetName(), "PlayerTick") == 0)
		{
			const auto playerController = static_cast<ABioPlayerController*>(Context);
			if (playerController) {
				// PLAYER GPS
				if (playerController->Pawn != nullptr)
				{
					// What happens when you don't have an interpolation method
					std::wstringstream ss;
					ss << "PATHFINDING_GPS PLAYERLOC=" << playerController->Pawn->Location.X << "," << playerController->Pawn->Location.Y << "," << playerController->Pawn->Location.Z;
					SendStringToLEX(ss.str());

					std::wstringstream ss2;
					ss2 << "PATHFINDING_GPS PLAYERROT=" << playerController->Pawn->Rotation.Pitch << "," << playerController->Pawn->Rotation.Yaw << "," << playerController->Pawn->Rotation.Roll;
					SendStringToLEX(ss2.str());
				}
			}
		}

		return true; // Other features can use this function call
	}
};

// Static variable initialization
bool LE1PathfindingGPS::playerGPSActive = false;
