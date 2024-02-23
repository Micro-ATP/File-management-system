#include <stdio.h>
#include <string.h>
#ifndef uninstall_H
#define uninstall_H

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

int uninstallSoftware(char *softwareName) {
    char command[256];
    sprintf(command, "wmic product where \"name like '%%%s%%'\" call uninstall", softwareName);
    
    FILE *fp = _popen(command, "r");
    if (fp == NULL) {
        printf("Error: Failed to execute command.\n");
        return 0; 
    }

    char output[256];
    int uninstallSuccess = 0; 
    while (fgets(output, sizeof(output), fp) != NULL) {
        if (strstr(output, "ReturnValue = 0;") != NULL) {
            uninstallSuccess = 1;
            break;
        }
    }

    _pclose(fp); 

    if (uninstallSuccess) {
        printf("Software '%s' uninstalled successfully.\n", softwareName);
        return 1; 
    } else {
        printf("Error: Failed to uninstall software '%s'.\n", softwareName);
        return 0; 
    }
}

#endif // uninstall_H