#pragma once

// Common data
class SharedData
{
public:
	// The pointer for installing hook and finding patterns
	static ISharedProxyInterface* SPIInterfacePtr;

	// The player camera POV
	static FTPOV cachedPlayerPOV;

	// The player location
	static FVector cachedPlayerPosition;

	// Method should always return true; this method collects data automatically for other features to use

	// Return false if other features shouldn't be able to also handle this function call
	// Return true if other features should also be able to handle this function call
	static bool ProcessEvent(UObject* Context, UFunction* Function, void* Parms, void* Result)
	{
		if (IsA<ABioPlayerController>(Context) && strcmp(Function->GetName(), "PlayerTick") == 0)
		{
			const auto playerController = static_cast<ABioPlayerController*>(Context);
			if (playerController) {
				cachedPlayerPOV = playerController->PlayerCamera->CameraCache.POV;
				cachedPlayerPosition = playerController->Pawn ? playerController->Pawn->Location : cachedPlayerPosition;
			}
		}

		// Always allow others to handle
		return true;
	}
};

// Static variable initialization
FTPOV SharedData::cachedPlayerPOV = FTPOV();
FVector SharedData::cachedPlayerPosition = FVector();
ISharedProxyInterface* SharedData::SPIInterfacePtr = nullptr;