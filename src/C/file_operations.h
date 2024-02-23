#include <stdio.h>
#ifndef file_operations_H
#define file_operations_H

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

void openFile(char *filename) {
    ShellExecute(NULL, "open", filename, NULL, NULL, SW_SHOWNORMAL);
}



#endif // file_operations_H