#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "exit_utils.h"

static const char* kTrail = "abcd";
static const int kForkFail = 1;

int main(int argc, char* argv[])
{
    printf("Let the forking begin.\n");
    size_t trailLength = strlen(kTrail);
    for(size_t i = 0; i < trailLength; i++) {
        printf("%c\n", kTrail[i]);
        pid_t pid = fork();
        exitIf(pid == -1, stderr, kForkFail, "Call to fork failed.");
    }
    return 0;
}

