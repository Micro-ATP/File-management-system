#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

char *convert_size(off_t size) {
    static char buffer[20];
    if (size < 1024) {
        sprintf(buffer, "%lld B", (long long)size);
    } else if (size < 1024 * 1024) {
        sprintf(buffer, "%.2f KB", (double)size / 1024);
    } else if (size < 1024 * 1024 * 1024) {
        sprintf(buffer, "%.2f MB", (double)size / (1024 * 1024));
    } else {
        sprintf(buffer, "%.2f GB", (double)size / (1024 * 1024 * 1024));
    }
    return buffer;
}

char *get_permissions(const char *file_path) {
    struct stat stat_info;
    if (stat(file_path, &stat_info) == -1) {
        return NULL;
    }
    static char permissions[11];
    snprintf(permissions, sizeof(permissions), "%o", stat_info.st_mode & 0777);
    return permissions;
}

void list_files(const char *directory) {
    DIR *dir = opendir(directory);
    if (!dir) {
        perror("Error opening directory");
        return;
    }

    printf("%-30s %-15s %-10s %-30s\n", "Name", "Size", "Permissions", "Modification Time");
    printf("%s\n", "================================================================================");
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG || entry->d_type == DT_DIR) {
            char item_path[PATH_MAX];
            snprintf(item_path, sizeof(item_path), "%s/%s", directory, entry->d_name);
            
            struct stat stat_info;
            if (stat(item_path, &stat_info) == -1) {
                perror("Error getting file information");
                continue;
            }

            char *size = convert_size(stat_info.st_size);
            char *permissions = get_permissions(item_path);
            struct tm *modification_time = localtime(&stat_info.st_mtime);

            char time_str[30];
            strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", modification_time);

            printf("%-30s %-15s %-10s %-30s\n", entry->d_name, size, permissions, time_str);
        }
    }
    closedir(dir);
}

int main() {
    const char *directory = "C:\\";
    list_files(directory);
    return 0;
}
