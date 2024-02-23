#include <stdio.h>
#include <stdlib.h> // 为了使用 system 函数
#include <windows.h>
#include <E:\GitHub\File-management-system\src\C\help.h>
#include <E:\GitHub\File-management-system\src\C\neofetch.h>
#include <E:\GitHub\File-management-system\src\C\file_operations.h>
#include <E:\GitHub\File-management-system\src\C\file_list.h>
// #include <E:\GitHub\File-management-system\src\C\neofetch.h>

void createFile(char *filename);
void readFile(char *filename);
void writeFile(char *filename);
void deleteFile(char *filename);
void listFiles();
void openFile(char *filename);
void changeDirectory(char *newDirectory);
// void searchFiles(char *target_name);
void help_log();
void neofetch_opt();

void changeDirectory(char *newDirectory) {
    if (SetCurrentDirectory(newDirectory) == 0) {
        printf("Error: Unable to change directory.\n");
    }
}



int main() {
    // int choice;

    char command[256]; // Command line input buffer
    char cdCommand[256]; // Buffer for storing cd command and its arguments
    char openCommand[256]; // Buffer for storing open command and its arguments
    char rmCommand[256]; // Buffer for storing rm command and its arguments
    char tchCommand[256]; // Buffer for storing touch command and its arguments
    // char wheisCommand[256]; // Buffer for storing whereis command and its arguments

    char current_directory[MAX_PATH] = "C:\\"; // Set the current directory to "C:\"

    SetCurrentDirectory(current_directory); // Set the current directory

    printf("Welcome to ATP_Shell, the friendly interactive shell\n");
    printf("Type help for instructions on how to use ATP_Shell\n");

    while (1) {
        GetCurrentDirectory(MAX_PATH, current_directory);
        printf("atp@ATP_Shell ~ %s ~> ", current_directory);
        
        // 读取命令
        fgets(command, sizeof(command), stdin);

        if (strcmp(command, "\n") == 0) {
        continue; // 如果用户只输入了回车，则继续循环等待用户输入
}


        // Check the user input command
        if (strcmp(command, "cd\n") == 0) {
            // If the user input is just "cd" command, then change directory to "C:\"
            SetCurrentDirectory("C:\\");
        } else if (sscanf(command, "cd %s", cdCommand) == 1) {
            changeDirectory(cdCommand); // If the user input is cd command, then change directory
        } else if (strcmp(command, "ls\n") == 0) {
            // If the user input is "ls" command, then list files
            printf("List of files:\n");
            listFiles();
        } else if (strcmp(command, "help\n") == 0) {
            help_log(); // If the user input is "help" command, then display help information
        } else if (sscanf(command, "open %s", openCommand) == 1) {
            // If the user input is "open <filename>" command, then open the file
            openFile(openCommand);
        } else if (sscanf(command, "rm -f %s", rmCommand) == 1) {
            // If the user input is "rm -f <filename>" command, then delete the file
            deleteFile(rmCommand);
        } else if (strstr(command, "neofetch") != NULL) {
            neofetch_opt(); // If the user input is "neofetch" command, then display system information
        } else if (sscanf(command, "touch %s", tchCommand) == 1) {
            createFile(tchCommand);
        } else if (strcmp(command, "exit && quit") == 0) {
            printf("Exiting...\n");
            exit(0);
        } else {
                    printf("Invalid choice. Please enter a valid option.\n");
            }
    }

    return 0;
}
