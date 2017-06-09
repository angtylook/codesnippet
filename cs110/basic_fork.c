#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "exit_utils.h"

static const int kForkFailed = 1;
int main(int argc, char* argv[])
{
    printf("Greetings from process %d! (parent %d)\n",
            getpid(),
            getppid());
    pid_t pid = fork();
    exitIf(pid == -1, stderr, kForkFailed, "fork function failed.\n");
    printf("Bye-bye from process %d! (parent %d)\n", getpid(), getppid());
    return 0;
}
