#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void createFile(char *filename);
void readFile(char *filename);
void writeFile(char *filename);
void deleteFile(char *filename);
void listFiles();
void openFile(char *filename);

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

    printf("Listing of files:\n");
    do {
        // Print file details
        printf("Name: %s\n", findData.cFileName);
        printf("  Size: %I64u bytes\n", ((unsigned long long)findData.nFileSizeHigh * (MAXDWORD + 1)) + findData.nFileSizeLow); // 修改为%I64u
        SYSTEMTIME sysTime;
        FileTimeToSystemTime(&findData.ftCreationTime, &sysTime);
        printf("  Created: %02d/%02d/%d %02d:%02d:%02d\n", sysTime.wMonth, sysTime.wDay, sysTime.wYear,
               sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
        printf("  Attributes: ");
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            printf("Directory ");
        } else {
            printf("File ");
        }
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
            printf("Read-only ");
        } else {
            printf("Read/Write ");
        }
        printf("\n\n");
    } while (FindNextFile(hFind, &findData) != 0);

    // Close the search handle
    FindClose(hFind);
}


void openFile(char *filename) {
    ShellExecute(NULL, "open", filename, NULL, NULL, SW_SHOWNORMAL);
}

int main() {
    char filename[50];
    int choice;

    while (1) {
        printf("\nSimple File Management System\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Write to File\n");
        printf("4. Delete File\n");
        printf("5. List Files\n");
        printf("6. Open File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename to create: ");
                scanf("%s", filename);
                createFile(filename);
                break;
            case 2:
                printf("Enter filename to read: ");
                scanf("%s", filename);
                readFile(filename);
                break;
            case 3:
                printf("Enter filename to write: ");
                scanf("%s", filename);
                getchar(); // Consume newline character left in the buffer
                writeFile(filename);
                break;
            case 4:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                deleteFile(filename);
                break;
            case 5:
                printf("List of files:\n");
                listFiles();
                break;
            case 6:
                printf("Enter filename to open: ");
                scanf("%s", filename);
                openFile(filename);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
