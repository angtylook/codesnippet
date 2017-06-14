#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <string.h>
#include "exit_utils.h"

static const int kExecFailed = 1;
static int mysystem(const char* command) {
    pid_t pid = fork();
    if(pid == 0) {
        char* arguments[] = {"/bin/sh", "-c", (char*) command, NULL};
        execvp(arguments[0], arguments);
        exitIf(true, stderr, kExecFailed, "execvp failed to invoke this: %s.\n", command);
    }

    int status;
    waitpid(pid, &status, 0);
    if(WIFEXITED(status))
        return WEXITSTATUS(status);
    else
        return -WTERMSIG(status);
}

static const size_t kMaxLine = 2048;
int main(int argc, char* argv[])
{
    char buf[kMaxLine];
    while(true) {
        printf("> ");
        fgets(buf, kMaxLine, stdin);
        if(feof(stdin))
            break;
        buf[strlen(buf) -1] = '\0';
        printf("retcode = %d\n", mysystem(buf));
    }
    printf("\n");
    return 0;
}

