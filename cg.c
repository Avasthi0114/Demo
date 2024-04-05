#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    
    char *dir_path;
    if (argc == 2) {
        dir_path = argv[1];
    } else {
        dir_path = ".";
    }

    
    DIR *directory = opendir(dir_path);
    if (directory == NULL) {
        printf("Failed to open directory: %s\n", dir_path);
        return 1;
    }

    
    struct dirent *entry;
    while ((entry = readdir(directory)) != NULL) {
        printf("%s\n", entry->d_name);
    }

   
    closedir(directory);

    return 0;
}
