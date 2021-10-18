#include <windows.h>
#include <psapi.h>
#include "MinHook.h"
#include "hook_manager.h"
#pragma comment(lib, "libMinHook.x64.lib")

BOOLEAN WINAPI main()
{
    uintptr_t DC_InjectDllAddress = (uintptr_t)GetModuleHandle(NULL) + 0x3C60;

    if (MH_Initialize() != MH_OK)
    {
        return TRUE;
    }

    if (MH_CreateHook((LPVOID)DC_InjectDllAddress, &hook_manager::DC_InjectDll,
        reinterpret_cast<LPVOID*>(&hook_manager::DC_InjectDllOriginal)) != MH_OK)
    {
        return TRUE;
    }

    if (MH_EnableHook((LPVOID)DC_InjectDllAddress) != MH_OK)
    {
        return TRUE;
    }
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        main();
    }
    return TRUE;
}

