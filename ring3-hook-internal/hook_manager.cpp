#include "hook_manager.h"

uintptr_t(*hook_manager::DC_InjectDllOriginal)(HANDLE, char*, uintptr_t, uintptr_t, LPVOID(__fastcall* VirtaulAllocEx_t)(HANDLE, LPVOID, SIZE_T, DWORD, DWORD), char, uintptr_t) = 0;

uintptr_t hook_manager::DC_InjectDll(HANDLE hProcess, char* dll_path,
    uintptr_t CreateRemoteThread_t,
    uintptr_t WriteProcessMemory_t, 
    LPVOID(__fastcall* VirtaulAllocEx_t)(HANDLE, LPVOID, SIZE_T, DWORD, DWORD),
    char arg6, 
    uintptr_t LoadLibraryA_t)
{

    MessageBoxA(NULL, NULL, NULL, MB_OK);

    void* result = VirtaulAllocEx_t(hProcess, NULL, 10, 0x3000, PAGE_READWRITE);

    if (result)
        MessageBoxA(NULL, NULL, NULL, MB_OK);
    
        utility::inject_dll(hProcess, "C:\\Users\\zpes\\source\\repos\\ring3-hook-injector\\x64\\Release\\ring3-hook-target.dll");
    return hook_manager::DC_InjectDllOriginal(hProcess, dll_path, CreateRemoteThread_t, WriteProcessMemory_t, VirtaulAllocEx_t, arg6, LoadLibraryA_t);
}
