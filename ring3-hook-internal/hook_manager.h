#pragma once
#include "utility.h"
#include <windows.h>

namespace hook_manager
{
	uintptr_t DC_InjectDll(HANDLE hProcess,
		char* dll_path,
		uintptr_t CreateRemoteThread_t,
		uintptr_t WriteProcessMemory_t,
		LPVOID(__fastcall* VirtaulAllocEx_t)(HANDLE, LPVOID, SIZE_T, DWORD, DWORD),
		char arg6,
		uintptr_t LoadLibraryA_t);

	extern uintptr_t(*DC_InjectDllOriginal)(HANDLE, char*, uintptr_t, uintptr_t, LPVOID(__fastcall* VirtaulAllocEx_t)(HANDLE, LPVOID, SIZE_T, DWORD, DWORD), char, uintptr_t);
}