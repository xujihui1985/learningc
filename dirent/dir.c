#include <dirent.h>
#include <limits.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void traverse_directory(char* directory_path, int depth)
{
    DIR *directory;
    if ((directory = opendir(directory_path)) == NULL) {
        perror("failed to open directory");
        exit(1);
    }

    struct dirent *directory_entry;
    while((directory_entry = readdir(directory)) != NULL) {
        if (directory_entry->d_type == DT_DIR) {
            if (strcmp(directory_entry->d_name, ".") == 0)
                continue;
            if (strcmp(directory_entry->d_name, "..") == 0)
                continue;

            printf("directory %s, depth %d\n", directory_entry->d_name,depth);
            char new_directory[PATH_MAX];
            strcpy(new_directory, directory_path);
            strcat(new_directory, "/");
            strcat(new_directory, directory_entry->d_name);
            traverse_directory(new_directory, depth + 1);
        } else {
            printf("filename %s, depth %d\n", directory_entry->d_name,depth);
        }
    }
}

int main() 
{
    int ret;
    struct stat *directory_meta = malloc(sizeof(struct stat));
    char *path = "/Users/sean/code/github.com/xujihui1985/learningc/dirent";
    if((ret = stat(path, directory_meta)) < 0) {
        perror("failed to stat directory");
        exit(1);
    }
    // check directory
    if ((directory_meta->st_mode & S_IFMT) != S_IFDIR)
    {
        printf("not a directory\n");
        exit(1);
    }
    traverse_directory(path, 0);
    exit(0);
}
