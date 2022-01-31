#include <stdio.h>
#include <io.h>
#include <string>
#include <fstream>
#include <iostream>
#include <ostream>
#include <streambuf>
#include <sstream>
#include "../LE1-SDK/Interface.h"
#include "../LE1-SDK/Common.h"
#include "../LE1-SDK/ME3TweaksHeader.h"
#include "fpng/fpng.h"

#define MYHOOK "PNGScreenShots_"

SPI_PLUGINSIDE_SUPPORT(L"PNGScreenShots", L"1.0.0", L"ME3Tweaks", SPI_GAME_LE1, SPI_VERSION_ANY);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

//ME3TweaksASILogger logger("2DA Printer v1", "2DAPrintLog.txt");


// ProcessEvent hook (for non-native .Activated())
// ======================================================================

typedef void (*tAppCreateBitmap)(wchar_t* pattern, int width, int height, FColor* data, void* fileManager); // ghidra shows 5th param but not sure what it is
tAppCreateBitmap appCreateBitmap = nullptr;
tAppCreateBitmap appCreateBitmap_orig = nullptr;

bool fpngInitialized = false;

// data is an array of FColor structs (BGRA) of size width * height
void appCreateBitmap_hook(wchar_t* pattern, int width, int height, FColor* data, void* fileManager)
{
	if (!fpngInitialized)
	{
		// Initialize the library before use
		fpng::fpng_init();
		fpngInitialized = true;
	}

	int byteCount = width * height * 3;

	// Color order needs swapped around for FPNG to access data
	// since nothing supports BRGA.
	std::vector<unsigned char> newImageData(byteCount);
	int pixelIndex = 0; // Which pixel we are one
	int totalCount = width * height; // how many pixels
	int position = 0; // Where to place into vector
	for (int i = 0; i < totalCount; i++)
	{
		auto color = &data[pixelIndex];
		newImageData[position] = color->R;
		newImageData[position + 1] = color->G;
		newImageData[position + 2] = color->B;

		pixelIndex++;
		position = pixelIndex * 3;
	}

	fpng::fpng_encode_image_to_file("C:\\users\\mgame\\desktop\\test.png", newImageData.data(), width, height, 3, fpng::FPNG_DECODE_NOT_FPNG); // 4 bpp, no flags
	// Do nothing.
	//appCreateBitmap_orig(pattern, width, height, data, fileManager);
}


SPI_IMPLEMENT_ATTACH
{
	Common::OpenConsole();

	auto _ = SDKInitializer::Instance();
	// Hook ProcessEvent for Non-Native
	INIT_FIND_PATTERN_POSTHOOK(appCreateBitmap, /*40 55 53 56 57*/ "41 54 41 55 41 56 41 57 48 8d ac 24 38 f8 ff ff 48 81 ec c8 08 00 00 48 c7 44 24 70 fe ff ff ff 48 8b 05 3c b6 55 01 48 33 c4 48 89 85 b0 07 00 00 4c 89 4c 24 48 44 89 44 24 58");
	if (auto rc = InterfacePtr->InstallHook(MYHOOK "appCreateBitmap", appCreateBitmap, appCreateBitmap_hook, (void**)&appCreateBitmap_orig);
		rc != SPIReturn::Success)
	{
		writeln(L"Attach - failed to hook appCreateBitmap: %d / %s", rc, SPIReturnToString(rc));
		return false;
	}
	return true;
}

SPI_IMPLEMENT_DETACH
{
	Common::CloseConsole();
		return true;
}
