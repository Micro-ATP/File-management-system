#include <stdio.h>
#include <stdlib.h>

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
    system("ls -l");
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
        printf("6. Exit\n");
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
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
