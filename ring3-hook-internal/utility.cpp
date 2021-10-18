#include "utility.h"

int utility::get_pid_by_name(std::string name)
{
    HANDLE snap_handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (snap_handle != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 entry;
        entry.dwSize = sizeof(entry);

        if (Process32First(snap_handle, &entry))
        {
            do
            {
                if (!name.compare(entry.szExeFile))
                {
                    return entry.th32ProcessID;
                }
            }             while (Process32Next(snap_handle, &entry));
        }
    }

    return 0;
}

void utility::inject_dll(HANDLE proc_handle, LPCSTR dll_path)
{
    if (proc_handle != INVALID_HANDLE_VALUE)
    {
        void* alloc = VirtualAllocEx(proc_handle, NULL, strlen(dll_path) + 1, 0x3000, PAGE_READWRITE);

        if (alloc)
        {
            if (WriteProcessMemory(proc_handle, alloc, dll_path, strlen(dll_path) + 1, 0))
            {
                HMODULE kernel_base = GetModuleHandle("kernelbase.dll");

                if (kernel_base)
                {
                    void* LoadLibraryA_t = GetProcAddress(kernel_base, "LoadLibraryA");

                    if (LoadLibraryA_t)
                    {
                        HANDLE thread_handle = CreateRemoteThread(proc_handle, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA_t, alloc, 0, 0);

                        if (!thread_handle)
                            return;

                        WaitForSingleObject(thread_handle, INFINITE);

                    }
                }
            }
        }

        VirtualFreeEx(proc_handle, alloc, strlen(dll_path) + 1, MEM_RELEASE);
        return;
    }
}

bool utility::is_string_in_string(const wchar_t* string, std::string to_find)
{
    int found_count = 0;
    for (int i = 0; i < wcslen(string) && found_count < to_find.length(); i++)
    {
        if (string[i] == to_find[i])
        {
            found_count++;
            if (found_count == to_find.length())
                return true;
        }

        found_count = 0;
    }
}
