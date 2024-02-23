#ifndef SOFT_H
#define SOFT_H

#include <stdio.h>
#include <string.h>
#include <windows.h>

// 卸载指定软件
int uninstallSoftware(const wchar_t *softwareName) {
    wchar_t command[256];
    swprintf(command, 256, L"wmic product where \"name like '%%%s%%'\" call uninstall", softwareName);
    
    FILE *fp = _wpopen(command, L"r");
    if (fp == NULL) {
        wprintf(L"Error: Failed to execute command.\n");
        return 0; 
    }

    wchar_t output[256];
    int uninstallSuccess = 0; 
    while (fgetws(output, sizeof(output) / sizeof(output[0]), fp) != NULL) {
        if (wcsstr(output, L"ReturnValue = 0;") != NULL) {
            uninstallSuccess = 1;
            break;
        }
    }

    _pclose(fp); 

    if (uninstallSuccess) {
        wprintf(L"Software '%s' uninstalled successfully.\n", softwareName);
        return 1; 
    } else {
        wprintf(L"Error: Failed to uninstall software '%s'.\n", softwareName);
        return 0; 
    }
}

// 从注册表中获取已安装软件列表
void fetch_installed_software() {
    HKEY hKey;
    LONG lResult;

    // 打开注册表项
    lResult = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall", 0, KEY_READ, &hKey);
    if (lResult != ERROR_SUCCESS) {
        wprintf(L"Error opening registry key.\n");
        return;
    }

    // 枚举子项
    wchar_t subkeyName[1024];
    DWORD subkeyNameSize = sizeof(subkeyName);
    DWORD index = 0;

    while (RegEnumKeyExW(hKey, index, subkeyName, &subkeyNameSize, NULL, NULL, NULL, NULL) == ERROR_SUCCESS) {
        HKEY hSubKey;
        if (RegOpenKeyExW(hKey, subkeyName, 0, KEY_READ, &hSubKey) == ERROR_SUCCESS) {
            wchar_t displayName[1024];
            DWORD displayNameSize = sizeof(displayName);

            // 获取 DisplayName 值
            if (RegQueryValueExW(hSubKey, L"DisplayName", NULL, NULL, (LPBYTE)displayName, &displayNameSize) == ERROR_SUCCESS) {
                wprintf(L"Software Name: %s\n", displayName);
            }

            // 关闭子项
            RegCloseKey(hSubKey);
        }

        // 重置子项名大小以便下一次迭代
        subkeyNameSize = sizeof(subkeyName);
        index++;
    }

    // 关闭注册表项
    RegCloseKey(hKey);
}

// 使用 WMIC 获取已安装软件列表
void fetch_installed_software_wmic() {
    system("wmic product get name");
}


// int uninstallSoftware(char *softwareName);

// int uninstallSoftware(char *softwareName) {
//     // 构建命令字符串
//     char command[256];
//     sprintf(command, "wmic product where name=\"%s\" call uninstall", softwareName);
    
//     // 执行命令并获取输出
//     FILE *fp = _popen(command, "r");
//     if (fp == NULL) {
//         printf("Error: Failed to execute command.\n");
//         return 0; // 返回0表示卸载失败
//     }

//     // 读取输出，检查是否成功卸载
//     char output[256];
//     int uninstallSuccess = 0; // 标志位，表示是否成功卸载
//     while (fgets(output, sizeof(output), fp) != NULL) {
//         if (strstr(output, "ReturnValue = 0;") != NULL) {
//             uninstallSuccess = 1;
//             break;
//         }
//     }

//     _pclose(fp); // 关闭文件指针

//     if (uninstallSuccess) {
//         printf("Software '%s' uninstalled successfully.\n", softwareName);
//         return 1; // 返回1表示成功卸载
//     } else {
//         printf("Error: Failed to uninstall software '%s'.\n", softwareName);
//         return 0; // 返回0表示卸载失败
//     }
// }


#endif // SOFT_H
