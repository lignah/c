#include <windows.h>
#include <stdio.h>

typedef DWORD (*F_POINTER)();

int main(int argc, char **argv) {
    HMODULE hDLL = LoadLibrary("C:\\Windows\\SysWOW64\\kernel32.dll");
    if (!hDLL) {
        printf("dLL load failed: %lu\n", GetLastError());
        return 1;
    }

    printf("dLL successfully loaded\n");

    // get address GetTickCount() in kernel32.dll
    F_POINTER f_address = (F_POINTER)GetProcAddress(hDLL, "GetTickCount");
    if (!f_address) {
        printf("function load failed: %lu\n", GetLastError());
        FreeLibrary(hDLL);
        return 1;
    }

    // GetTickCount()
    DWORD tick = f_address();
    DWORD total_seconds = tick / 1000;                    // ms → s
    DWORD days = total_seconds / (24 * 3600);             // 1day = 86400s
    DWORD hours = (total_seconds % (24 * 3600)) / 3600;   // 1h = 3600s
    DWORD minutes = (total_seconds % 3600) / 60;          // 1min = 60s
    DWORD seconds = total_seconds % 60;                   // remain second

    printf("time since windows boot: %lu days %lu hours %lu minutes %lu seconds\n",
           days, hours, minutes, seconds);

    FreeLibrary(hDLL);
    return 0;
}
/* The exported functions of the DLL
dumpbin /exports C:\Windows\SysWOW64\kernel32.dll

Microsoft (R) COFF/PE Dumper Version 14.39.33523.0
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file C:\Windows\SysWOW64\kernel32.dll

File Type: DLL

  Section contains the following exports for KERNEL32.dll

    00000000 characteristics
    4E7DA243 time date stamp
        0.00 version
           1 ordinal base
        1608 number of functions
        1608 number of names

    ordinal hint RVA      name

          4    0          AcquireSRWLockExclusive (forwarded to NTDLL.RtlAcquireSRWLockExclusive)
        ...
        779  308 00022210 GetThreadTimes
        780  309 00017530 GetThreadUILanguage
        782  30A 00022640 GetTickCount
        781  30B 0001CC60 GetTickCount64
        ...
       1606  645 00061CA0 timeGetDevCaps
       1607  646 00061CF0 timeGetSystemTime
       1608  647 00014E20 timeGetTime

  Summary

       10000 .data
       10000 .didat
       30000 .rdata
       10000 .reloc
       10000 .rsrc
       70000 .text
*/

// System32 - 64bit dll
// SysWOW64 - 32bit dll