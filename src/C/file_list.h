#include <stdio.h>
#include <windows.h>
#ifndef file_list_H
#define file_list_H

void listFiles() {
    WIN32_FIND_DATA findData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    TCHAR searchPath[MAX_PATH];

    // Specify the search path
    GetCurrentDirectory(MAX_PATH, searchPath);
    strcat_s(searchPath, MAX_PATH, "\\*"); // 使用strcat_s

    // Find the first file in the directory
    hFind = FindFirstFile(searchPath, &findData);
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Error: Unable to find files.\n");
        return;
    }

    // Print table header
    printf("%-40s %-15s %-25s\n", "Name", "Size (bytes)", "Created");

    // Print separator line
    printf("===============================================================================\n");

    do {
        // Print file details
        printf("%-40s %-15I64u ", findData.cFileName, ((unsigned long long)findData.nFileSizeHigh * (MAXDWORD + 1)) + findData.nFileSizeLow); // 修改为%I64u
        SYSTEMTIME sysTime;
        FileTimeToSystemTime(&findData.ftCreationTime, &sysTime);
        printf("%02d/%02d/%d %02d:%02d:%02d\n", sysTime.wMonth, sysTime.wDay, sysTime.wYear,sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
    } while (FindNextFile(hFind, &findData) != 0);

    // Close the search handle
    FindClose(hFind);
}
# endif // file_list_H