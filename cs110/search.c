#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

static const size_t kMaxPath = 1024;
static const int kWrongArgumentCount = 1;
static const int kDirectoryNeeded = 2;

static void exitUnless(
        bool test,
        FILE* stream,
        int code,
        const char* control,
        ...) {
    if(test)
        return;
    va_list arglist;
    va_start(arglist, control);
    vfprintf(stream, control, arglist);
    va_end(arglist);
    exit(code);
}

static void listMatches(
        char path[],
        size_t length,
        const char* pattern) {
    DIR* dir = opendir(path);
    if(dir == NULL)
        return;
    strcpy(path + length, "/");
    while(true) {
        struct dirent* de = readdir(dir);
        if(de == NULL)
            break;
        if(strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0)
            continue;
        if(length + strlen(de->d_name) + 1 > kMaxPath)
            continue;
        strcpy(path + length + 1, de->d_name);
        struct stat st;
        lstat(path, &st);
        if(S_ISREG(st.st_mode)) {
            if(strstr(de->d_name, pattern) != NULL) {
                printf("%s\n", path);
            }
        } else if (S_ISDIR(st.st_mode)) {
            listMatches(path, length+1+strlen(de->d_name), pattern);
        }
    }
    closedir(dir);
}

int main(int argc, char* argv[])
{
    exitUnless(argc == 3, stderr, kWrongArgumentCount,
            "Usage: %s <directory> <pattern>\n", argv[0]);
    struct stat st;
    const char* directory = argv[1];
    stat(directory, &st);
    exitUnless(S_ISDIR(st.st_mode), stderr, kDirectoryNeeded,
            "<directory> must be an actual directory, %s is not",
            directory);
    size_t length = strlen(directory);
    if(length > kMaxPath)
        return 0;
    
    const char* pattern = argv[2];
    char path[kMaxPath + 1];
    strcpy(path, directory);
    listMatches(path, length, pattern);
    return 0;
}
