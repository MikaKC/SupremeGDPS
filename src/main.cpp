#include <matdash.hpp>
#include <matdash/boilerplate.hpp>
#include <matdash/console.hpp>

#define PLATFORM_WIN32
#define DEBUG

#ifdef PLATFORM_WIN32
#include "ModBadgesMod.h"
#endif

#include "MenuLayerHook.h"
#include "LoadingLayerHook.h"

void mod_main(HMODULE) 
{
#ifdef DEBUG
	matdash::create_console();
#endif

    WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(gd::base + 0x226E19), "\xE9\x59\x01\x00\x00\x90", 6, nullptr);
    WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(gd::base + 0x226FB8), "\xE9\x59\x01\x00\x00\x90", 6, nullptr);
    WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(gd::base + 0x227157), "\xE9\x30\x02\x00\x00\x90", 6, nullptr);

#ifdef PLATFORM_WIN32
    SupremeGDPS::ModBadgesMod::ApplyHooks();
#endif
	SupremeGDPS::LoadingLayerHook::ApplyHooks();
    SupremeGDPS::MenuLayerHook::ApplyHooks();
}