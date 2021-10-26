#include <dirent.h>
#include <stdio.h>

int main() {
    struct DIR *dirp = opendir("./tmp/");
    struct dirent *dp = NULL;

    char *fileNames[255];
    unsigned long inodeNumbers[255];
    int size = 0;

    while ((dp = readdir(dirp)) != NULL) {
        inodeNumbers[size] = dp->d_ino;
        fileNames[size] = dp->d_name;
        for(int i = 0; i < size; ++i)
        {
            if (inodeNumbers[size] == inodeNumbers[i]) {
                printf("Hard links: %s - %s\n", fileNames[size], fileNames[i]);
            }
        }
        ++size;
    }

    (void) closedir(dirp);
    return 0;
}