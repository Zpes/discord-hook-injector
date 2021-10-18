# discord-hook-injector

What is this?
Discord "overlay" gets injected into the game by the discordhelper64.exe. They create a full access handle and just do a normal LoadLibrary injection. This project hooks the inject function and uses the handle that has been created by the discordhelper64.exe and injects our own dll.

This will not work for any games protected by a kernel anticheat. On those games they inject their dll using SetWindowsHookExA. Wich you might also be able to exploit.

## NOTE
All the paths are hardcoded. So just plain running this wont work. You have to replace the path. For an improvement you could maybe use socket communication or shared memory.

## There are 3 projects in here
* ring3-hook-internal -> This is the dll that gets injected into the discordhookhelper64.exe.
* ring3-hook-main     -> This injects the ring3-hook-internal into discordhookhelper64.exe.
* ring3-hook-target   -> This is the dll that gets injected into the target process.

## Functionality
* Not having to create a handle to the target process.

## Need help?
* Build the program in release x64 and with multibyte.
* Still cant figure it out? join the discord!

## Links
* [Discord](https://discord.gg/9XykzWqVMP) - GameReversalClub
