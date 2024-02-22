// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

// // 导入头文件
// // #include "directory_operations.h"
// // #include "file_operations.h"
// #include "E:\\GitHub\\File-management-system\\C\\file_list.h"
// // #include "whereis.h"
// // #include "fetch_soft.h"
// // #include "uninstall_soft.h"
// #include "E:\\GitHub\\File-management-system\\C\\help.h"
// // #include "clear.h"
// // #include "diskpart.h"
// // #include "everything.h"
// // #include "chkssd.h"


// // 主函数
// int main() {
//     // 设置默认路径为 "C:\\"
//     chdir("C:\\");

//     printf("Welcome to ATP_Shell, the friendly interactive shell\n");
//     printf("Type help for instructions on how to use ATP_Shell\n");

//     char choice[256];
//     char current_directory[512];
//     while (1) {
//         getcwd(current_directory, sizeof(current_directory));
//         printf("atp@ATP_Shell ~%s ~> ", current_directory);
//         fgets(choice, sizeof(choice), stdin);
//         choice[strcspn(choice, "\n")] = '\0';  // 移除换行符

//         if (strcmp(choice, "ls") == 0) {
//             list_files(current_directory);
//         } else if (strncmp(choice, "touch ", 6) == 0) {
//             char file_path[512];
//             strcpy(file_path, choice + 6);
//             create_file(file_path);
//         } else if (strncmp(choice, "rm -f ", 6) == 0) {
//             char file_path[512];
//             strcpy(file_path, choice + 6);
//             delete_file(file_path);
//         } else if (strncmp(choice, "open ", 5) == 0) {
//             char file_path[512];
//             strcpy(file_path, choice + 5);
//             open_file(file_path);
//         } else if (strncmp(choice, "cd ", 3) == 0) {
//             char new_directory[512];
//             strcpy(new_directory, choice + 3);
//             change_directory(new_directory);
//             getcwd(current_directory, sizeof(current_directory));  // 更新当前目录
//         } else if (strcmp(choice, "cd") == 0) {
//             char new_directory[] = "C:\\";
//             change_directory(new_directory);
//             getcwd(current_directory, sizeof(current_directory));  // 更新当前目录
//         } else if (strncmp(choice, "whereis ", 8) == 0) {
//             char target_name[256];
//             strcpy(target_name, choice + 8);
//             global_search(target_name);
//         } else if (strcmp(choice, "neofetch") == 0) {
// printf("             .-/+oossssoo+/-.              atp@ATP_Shell\n");
// printf("        `:+ssssssssssssssssss+:`           -----------\n");
// printf("      -+ssssssssssssssssssyyssss+-         OS: Microsoft Windows 11 专业版 64 位\n");
// printf("    .ossssssssssssssssssdMMMNysssso.       Kernel: 10.0.22631\n");
// printf("   /ssssssssssshdmmNNmmyNMMMMhssssss/      Uptime: 11d 4h 51m 4s\n");
// printf("  +ssssssssshmydMMMMMMMNddddyssssssss+     Motherboard: ROG MAXIMUS Z790 FORMULA D5\n");
// printf(" /sssssssshNMMMyhhyyyyhmNMMMNhssssssss/    Shell: ATP_Shell\n");
// printf(".ssssssssdMMMNhsssssssssshNMMMdssssssss.   Packages: 991 (dpkg), 6 (snap)\n");
// printf("+sssshhhyNMMNyssssssssssssyNMMMysssssss+   Resolution: 7680 x 4320\n");
// printf("ossyNMMMNyMMhsssssssssssssshmmmhssssssso   Font: Segoe UI\n");
// printf("ossyNMMMNyMMhsssssssssssssshmmmhssssssso   CPU: 14th Gen Intel(R) Core(TM) i9-14900KS\n");
// printf("+sssshhhyNMMNyssssssssssssyNMMMysssssss+   GPU: NVIDIA RTX™ 6000 Ada\n");
// printf(" /sssssssshNMMMyhhyyyyhdNMMMNhssssssss/    RAM: 130,944MB / 25038 MB (19%%)\n");
// printf("  +sssssssssdmydMMMMMMMMddddyssssssss+     Disk C: 330GB / 4,096GB (8%%)\n");
// printf("   /ssssssssssshdmNNNNmyNMMMMhssssss/      Disk D: 1609GB / 4,096GB (39%%)\n");
// printf("    .ossssssssssssssssssdMMMNysssso.\n");
// printf("      -+sssssssssssssssssyyyssss+-\n");
// printf("        `:+ssssssssssssssssss+:-\n");
// printf("            .-/+oossssoo+/-.\n");


//         } else if (strcmp(choice, "fetchsoft") == 0) {
//             get_installed_software();
//         } else if (strncmp(choice, "unsoft ", 7) == 0) {
//             char software_name[256];
//             strcpy(software_name, choice + 7);
//             uninstall_software(software_name);
//         } else if (strcmp(choice, "help") == 0) {
//             help_log();
//         } else if (strcmp(choice, "clear") == 0) {
//             clear_screen();
//         } else if (strcmp(choice, "diskpart") == 0) {
//             open_diskpart_with_admin();
//         } else if (strncmp(choice, "everything ", 11) == 0) {
//             char keyword[256];
//             strcpy(keyword, choice + 11);
//             search_files(keyword);
//         } else if (strcmp(choice, "chkssd") == 0) {
//             open_urwtest_v18();
//         } else if (strcmp(choice, "exit") == 0 || strcmp(choice, "quit") == 0) {
//             printf("Exiting...\n");
//             break;
//         } else {
//             printf("Invalid choice. Please enter a valid option. If you need help, type 'help' and press Enter.\n");
//         }
//     }

//     return 0;
// }
