#pragma once
#include "ExtraContent.h"

struct CompileTimeSelectedStreamProvider final
    : public NonCopyMovable
{
private:
    FILE* stream_;

public:
    CompileTimeSelectedStreamProvider()
        : stream_{ nullptr }
    {}

    void Initialize()
    {
#if NDEBUG
    	stream_ = _wfsopen((GetGameExePath() / L"LE1Autoload.log").c_str(), L"w", _SH_DENYWR);
        if (!stream_)
        {
            MessageBoxA(nullptr, "Failed to open log file in Release build, logging is disabled.", "LE1Autoload error", MB_OK | MB_ICONERROR);
            stream_ = nullptr;
        }
#else
        Common::OpenConsole();
#endif
    }


    void Wrapup()
    {
#if NDEBUG
        if (stream_)
        {
            fclose(stream_);
        }
#else
        Common::CloseConsole();
#endif
    }


    FILE* Stream() const noexcept
    {
#if FNDEBUG
        return stream_ ? stream_ : stdout;
#else
        return stdout;
#endif
    }
};

CompileTimeSelectedStreamProvider GLogStreamProvider;

#define initLog()           GLogStreamProvider.Initialize();
#define closeLog()          GLogStreamProvider.Wrapup();
#define writeln(msg,...)    if (GLogStreamProvider.Stream() != nullptr) { fwprintf_s(GLogStreamProvider.Stream(), msg "\n", __VA_ARGS__); }
