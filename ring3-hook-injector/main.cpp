#include "utility.h"

BOOLEAN WINAPI main()
{
	int pid = 0;
	while (!(pid = utility::get_pid_by_name("DiscordHookHelper64.exe")));

	utility::inject_dll(pid, "C:\\Users\\zpes\\source\\repos\\ring3-hook-injector\\x64\\Release\\ring3-hook-internal.dll");
	printf_s("[>] injected into -> %d\n", pid);
	std::getchar();
}