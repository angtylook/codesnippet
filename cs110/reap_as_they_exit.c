#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>  // for exit
#include <sys/wait.h>
#include <errno.h>
#include "exit_utils.h"

static const int kNumChildren = 8;
static const int kForkFail = 1;
static const int kWaitFail = 2;

int main(int argc, char* argv[])
{
    for(size_t i = 0; i < kNumChildren; i++) {
        pid_t pid = fork();
        exitIf(pid == -1, stderr, kForkFail, "Fork function failed.\n");
        if(pid == 0)
            exit(110 + i);
    }

    while(true) {
        int status;
        pid_t pid = waitpid(-1, &status, 0);
        if(pid == -1)
            break;
        if(WIFEXITED(status)) {
            printf("Child %d exited: status %d\n", pid, WEXITSTATUS(status));
        } else {
            printf("Child %d exited abnormally.\n", pid);
        }
    }
    exitUnless(errno == ECHILD, stderr, kWaitFail, "waitpid failed.\n");
    return 0;
}
