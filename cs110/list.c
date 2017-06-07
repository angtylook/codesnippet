#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>

static inline void updatePermissionsBit(bool flag,
        char permissions[],
        size_t column,
        char ch) {
    if (flag)
        permissions[column] = ch;
}

static const size_t kNumPermissionColumns = 10;
static const char kPermissionChars[] = {'r', 'w', 'x'};
static const size_t kNumPermissionChars = sizeof(kPermissionChars);
static const mode_t kPermissionFlags[] = {
    S_IRUSR, S_IWUSR, S_IXUSR,
    S_IRGRP, S_IWGRP, S_IXGRP,
    S_IROTH, S_IWOTH, S_IXOTH
};

static const size_t kNumPermissionFlags = sizeof(kPermissionFlags)/sizeof(kPermissionFlags[0]);
static void listPermissions(mode_t mode) {
    char permissions[kNumPermissionColumns + 1];
    memset(permissions, '-', sizeof(permissions));
    permissions[kNumPermissionColumns] = '\0';
    updatePermissionsBit(S_ISDIR(mode), permissions, 0, 'd');
    updatePermissionsBit(S_ISLNK(mode), permissions, 0, 'l');
    for(size_t i = 0; i < kNumPermissionFlags; i++) {
        updatePermissionsBit(mode & kPermissionFlags[i],
                permissions,
                i + 1,
                kPermissionChars[i % kNumPermissionChars]);
    }
    printf("%s ", permissions);
}

static void listHardlinkCount(nlink_t count) {
    if(count < 10)
        printf(" %zu ", count);
    else
        printf(">9 ");
}

static void listUser(uid_t uid) {
    struct passwd* pw = getpwuid(uid);
    if(pw == NULL)
        printf("%8u", uid);
    else
        printf("%-8s", pw->pw_name);
}

static void listGroup(gid_t gid) {
     struct group* gr = getgrgid(gid);
     const char* group = gr == NULL? "unknown" : gr->gr_name;
     printf("%-8s", group);
 }

static void listSize(off_t size) {
    printf("%6zu ", size);
}

static void listModifiedTime(time_t mtime) {
    time_t now;
    time(&now);
    struct tm* currentTime = localtime(&now);
    char currentYearString[8];
    strftime(currentYearString, sizeof(currentYearString), "%Y", currentTime);
    struct tm* modifiedTime = localtime(&mtime);
    char modifiedTimeString[32];
    strftime(modifiedTimeString, sizeof(modifiedTimeString), "%Y", modifiedTime);
    bool sameYear = strcmp(currentYearString, modifiedTimeString) == 0;
    const char* format = sameYear ? "%b %d %H:%M" : "%b %d %Y";
    strftime(modifiedTimeString, sizeof(modifiedTimeString), format, modifiedTime);
    printf("%s ", modifiedTimeString);
}

static void listName(const char* name,
    const struct stat* st,
    bool link,
    const char* path) {
    printf("%s", name);
    if(!link)
        return;
    char target[st->st_size + 1];
    readlink(path, target, sizeof(target));
    target[st->st_size] = '\0';
    printf(" -> %s", target);
}

static void listEntry(const char* name,
    const struct stat* st,
    bool link,
    const char* path) {
    listPermissions(st->st_mode);
    listHardlinkCount(st->st_nlink);
    listUser(st->st_uid);
    listGroup(st->st_gid);
    listSize(st->st_size);
    listModifiedTime(st->st_mtime);
    listName(name, st, link, path);
    printf("\n");
}

static const size_t kMaxPath = 1024;
static void listDirectory(const char* name,
    size_t length,
    const struct stat* st,
    bool multiple) {
    char path[kMaxPath + 1];
    strcpy(path, name);
    if(multiple)
        printf("%s: \n", name);
    DIR* dir = opendir(path);
    strcpy(path + length, "/");
    while(true) {
        struct dirent* de = readdir(dir);
        if(de == NULL)
            break;
        strcpy(path + length + 1, de->d_name);
        struct stat st;
        lstat(path, &st);
        listEntry(de->d_name, &st, S_ISLNK(st.st_mode), path);
    }
    closedir(dir);
}

static void list(const char* name, size_t length, bool multiple) {
    if(strlen(name) == 0)
        return;
    struct stat st;
    if(lstat(name, &st) == -1)
        return;
    if(S_ISREG(st.st_mode) || S_ISLNK(st.st_mode))
        listEntry(name, &st, S_ISLNK(st.st_mode), name);
    else if (S_ISDIR(st.st_mode)) {
        listDirectory(name, length, &st, multiple);
    }
}

static void listEntries(const char* entries[], size_t numEntries) {
    bool multiple = numEntries > 1;
    for(size_t i = 0; i < numEntries; i++) {
        size_t length = strlen(entries[i]);
        if(length <= kMaxPath) {
            list(entries[i], length, multiple);
        }
    }
}

static const char* kDefaultEntries[] = {".", NULL};
int main(int argc, char* argv[])
{
    const char** entries = argc == 1 ? kDefaultEntries : (const char**)(argv+1);
    size_t numEntries = argc == 1 ? 1 : argc - 1;
    listEntries(entries, numEntries);
    return 0;
}