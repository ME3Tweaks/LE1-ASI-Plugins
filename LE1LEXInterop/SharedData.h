#pragma once

// Common data
class SharedData
{
public:
	// The player camera POV
	static FTPOV cachedPlayerPOV;

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
			}
		}

		// Always allow others to handle
		return true;
	}
};