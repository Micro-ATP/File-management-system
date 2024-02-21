#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <E:\GitHub\File-management-system\C\help.h>
#include <E:\GitHub\File-management-system\C\neofetch.h>

void createFile(char *filename);
void readFile(char *filename);
void writeFile(char *filename);
void deleteFile(char *filename);
void listFiles();
void openFile(char *filename);
void changeDirectory(char *newDirectory);

void createFile(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to create file.\n");
        return;
    }
    fclose(file);
    printf("File created successfully.\n");
}

void readFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }
    
    char ch;
    printf("File contents:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void writeFile(char *filename) {
    FILE *file = fopen(filename, "a"); // Append mode, to keep existing content
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }
    
    char data[100];
    printf("Enter data to write to file (max 100 characters):\n");
    fgets(data, sizeof(data), stdin);
    
    fprintf(file, "%s", data);
    fclose(file);
    printf("Data written to file successfully.\n");
}

void deleteFile(char *filename) {
    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error: Unable to delete file.\n");
    }
}

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

void openFile(char *filename) {
    ShellExecute(NULL, "open", filename, NULL, NULL, SW_SHOWNORMAL);
}

void changeDirectory(char *newDirectory) {
    if (SetCurrentDirectory(newDirectory) == 0) {
        printf("Error: Unable to change directory.\n");
    }
}

int main() {
    char filename[50];
    int choice;

    char command[256]; // Command line input buffer
    char cdCommand[256]; // Buffer for storing cd command and its arguments
    char openCommand[256]; // Buffer for storing open command and its arguments
    char rmCommand[256]; // Buffer for storing rm command and its arguments
    char tchCommand[256]; // Buffer for storing touch command and its arguments
    
    char current_directory[MAX_PATH] = "C:\\"; // Set the current directory to "C:\"

    SetCurrentDirectory(current_directory); // Set the current directory

    printf("Welcome to ATP_Shell, the friendly interactive shell\n");
    printf("Type help for instructions on how to use ATP_Shell\n");

    while (1) {
        GetCurrentDirectory(MAX_PATH, current_directory); // Get the current directory
        printf("atp@ATP_Shell ~ %s ~> ", current_directory); // Print the prompt including the current directory
        fgets(command, sizeof(command), stdin); // Read the command line from standard input

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
        } else {
            // If the user input is not cd, cd xxx, ls, help, open, or rm command, then proceed with the original flow
            sscanf(command, "%d", &choice);
            switch (choice) {
                case 2:
                    printf("Enter filename to create: ");
                    scanf("%s", filename);
                    createFile(filename);
                    break;
                // case 3:
                //     printf("Enter filename to delete: ");
                //     scanf("%s", filename);
                //     deleteFile(filename);
                //     break;
                // case 4:
                //     printf("Enter filename to open: ");
                //     scanf("%s", filename);
                //     openFile(filename);
                //     break;
                case 0:
                    printf("Exiting...\n");
                    exit(0);
                default:
                    printf("Invalid choice. Please enter a valid option.\n");
            }
        }
    }

    return 0;
}
