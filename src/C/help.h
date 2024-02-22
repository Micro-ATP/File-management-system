#include <stdio.h>
#ifndef HELP_H
#define HELP_H

void help_log() {
    printf("\n");
    printf("Welcome to ATP_Shell, the friendly interactive shell !!!\n\n");
    printf("    Commands example:\n\n");
    printf("        ls - List files and directories in the current directory\n");
    printf("        touch <file_name> - Create a new file\n");
    printf("        rm -f <file_name> - Delete a file\n");
    printf("        open <file_name> - Open a file\n");
    printf("        cd <directory> - Change the current directory\n");
    printf("        whereis <file_name> - Search for a file\n");
    printf("        everything <file_name> - Search for files using Everything\n");
    printf("        neofetch - Display system information\n");
    printf("        fetchsoft - List all installed software\n");
    printf("        unsoft <software_name> - Uninstall a software\n");
    printf("        clear - Clear the screen\n");
    printf("        diskpart - Open diskpart\n");
    printf("        chkssd - Check SSD health\n");
    printf("        quit - Exit the shell\n");
    printf("        exit - Exit the shell\n");
    printf("        help - Display this help message\n");
    printf("\n");
}

#endif // HELP_H
