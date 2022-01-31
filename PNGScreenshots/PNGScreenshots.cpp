#include <filesystem>
#include <stdio.h>
#include <fstream>
#include <Shlwapi.h>
#include "../LE1-SDK/SdkInitializer.h"
#include "../LE1-SDK/SdkHeaders.h"
#include "../LE1-SDK/Interface.h"
#include "../LE1-SDK/Common.h"
#include "fpng/fpng.h"

#define MYHOOK "PNGScreenShots_"

SPI_PLUGINSIDE_SUPPORT(L"PNGScreenShots", L"1.0.0", L"ME3Tweaks", SPI_GAME_LE1, SPI_VERSION_ANY);
SPI_PLUGINSIDE_POSTLOAD;
SPI_PLUGINSIDE_ASYNCATTACH;

// This project doesn't use C++ 20 (due to it making it not compilable) so we use c++ 11
// Taken from https://stackoverflow.com/a/26221725/800318
template<typename ... Args>
std::wstring wstring_format(const std::wstring& format, Args ... args)
{
	int size_s = _snwprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
	if (size_s <= 0) { throw std::runtime_error("Error during formatting."); }
	auto size = static_cast<size_t>(size_s);
	auto buf = std::make_unique<wchar_t[]>(size);
	_snwprintf(buf.get(), size, format.c_str(), args ...);
	return std::wstring(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

// ProcessEvent hook (for non-native .Activated())
// ======================================================================

typedef void (*tAppCreateBitmap)(wchar_t* pattern, int width, int height, FColor* data, void* fileManager); // ghidra shows 5th param but not sure what it is
tAppCreateBitmap appCreateBitmap = nullptr;
tAppCreateBitmap appCreateBitmap_orig = nullptr;

bool fpngInitialized = false;

// The initial screenshot index we should check against. As we take screenshots we know the previous images will always exist
// and as such we can just increment this on auto-generated screenshots to match the game's incremental system
int cachedScreenshotIndex = 1;

// Hopefully user never gets here but this is so it doesn't make an infinite loop
int maxScreenshotIndex = 99999;

// data is an array of FColor structs (BGRA) of size width * height
void appCreateBitmap_hook(wchar_t* inputBaseName, int width, int height, FColor* data, void* fileManager)
{
	if (!fpngInitialized)
	{
		// Initialize the library before use
		fpng::fpng_init();
		fpngInitialized = true;
	}

	long byteCount = width * height * 3;

	// Color order needs swapped around for FPNG to access data
	// since nothing supports BRGA.
	std::vector<unsigned char> newImageData(byteCount);
	int pixelIndex = 0; // Which pixel we are one
	long totalCount = width * height; // how many pixels
	long position = 0; // Where to place into vector
	for (long i = 0; i < totalCount; i++)
	{
		auto color = &data[pixelIndex];
		newImageData[position] = color->R;
		newImageData[position + 1L] = color->G;
		newImageData[position + 2L] = color->B;

		pixelIndex++;
		position = pixelIndex * 3;
	}

	// Determine output filename.
	auto path = std::filesystem::path(inputBaseName);
	auto extension = path.extension();
	if (extension != "png")
	{
		auto outPath = std::filesystem::path(inputBaseName);
		std::wstring newFname;
		while (cachedScreenshotIndex < maxScreenshotIndex)
		{
			newFname = wstring_format(L"PNGScreenShot%05i.png", cachedScreenshotIndex);
			cachedScreenshotIndex++;
			outPath.replace_filename(newFname);

			// Check if file exists
			if (!std::filesystem::exists(outPath))
			{
				path = outPath;
				break;
			}
		}

		if (cachedScreenshotIndex == maxScreenshotIndex)
			return; // Can't take any more screenshots
	}


	fpng::fpng_encode_image_to_wfile(path.c_str(), newImageData.data(), width, height, 3, fpng::FPNG_DECODE_NOT_FPNG); // 4 bpp, no flags
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
