#pragma once
#include <windows.h>
#include <tlhelp32.h>
#include <string>

namespace utility
{
	int get_pid_by_name(std::string name);
	void inject_dll(int pid, LPCSTR dll_path);
	bool is_string_in_string(const wchar_t* string, std::string to_find);
}