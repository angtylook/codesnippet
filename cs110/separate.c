#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "exit_utils.h"

static const int kForkFailed = 1;
static const int kWaitFailed = 2;

int main(int argc, char* argv[])
{
    printf("Before.\n");
    pid_t pid = fork();
    exitIf(pid == -1, stderr, kForkFailed, "Fork function failed.\n");
    printf("After.\n");
    if(pid == 0) {
        printf("I'm the child, and the parent will wait up for me.\n");
        return 110;
    } else {
        int status;
        exitUnless(waitpid(pid, &status, 0) == pid, stderr, kWaitFailed,
                "Parent's wait for child process with pid %d failed.\n", pid);
        if(WIFEXITED(status)) {
            printf("Child exited with status %d.\n", WEXITSTATUS(status));
        } else {
            printf("Child terminated abnormally.\n");
        }
    }
}

