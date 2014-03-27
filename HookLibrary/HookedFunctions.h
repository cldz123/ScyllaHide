#pragma once

#include <windows.h>

typedef void  (WINAPI * t_GetSystemTime)(LPSYSTEMTIME lpSystemTime); //Kernel32.dll
typedef void  (WINAPI * t_GetLocalTime)(LPSYSTEMTIME lpSystemTime); //Kernel32.dll
typedef DWORD (WINAPI * t_timeGetTime)(void); //Winmm.dll
typedef DWORD (WINAPI * t_GetTickCount)(void); //Kernel32.dll
typedef BOOL  (WINAPI * t_QueryPerformanceCounter)(LARGE_INTEGER *lpPerformanceCount); //Kernel32.dll
typedef BOOL  (WINAPI * t_BlockInput)(BOOL fBlockIt); //user32.dll
typedef DWORD (WINAPI * t_OutputDebugStringA)(LPCSTR lpOutputString); //Kernel32.dll
typedef DWORD (WINAPI * t_OutputDebugStringW)(LPCWSTR lpOutputString); //Kernel32.dll
//WIN 7 X64: OutputDebugStringW -> OutputDebugStringA

//DbgBreakPoint

NTSTATUS NTAPI HookedNtSetInformationThread(HANDLE ThreadHandle, THREADINFOCLASS ThreadInformationClass, PVOID ThreadInformation, ULONG ThreadInformationLength);
NTSTATUS NTAPI HookedNtQuerySystemInformation(SYSTEM_INFORMATION_CLASS SystemInformationClass, PVOID SystemInformation, ULONG SystemInformationLength, PULONG ReturnLength);
NTSTATUS NTAPI HookedNtQueryInformationProcess(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength, PULONG ReturnLength);
NTSTATUS NTAPI HookedNtQueryObject(HANDLE Handle, OBJECT_INFORMATION_CLASS ObjectInformationClass, PVOID ObjectInformation, ULONG ObjectInformationLength, PULONG ReturnLength);

BOOL WINAPI HookedBlockInput(BOOL fBlockIt);
DWORD WINAPI HookedGetTickCount(void);
