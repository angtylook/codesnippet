#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include "exit_utils.h"

static const int kSignalFailed = 1;
static const int kForkFailed = 2;
static const int kWaitFailed = 3;
static const int kExecFailed = 8;

static void reapChild(int sig) {
    pid_t pid;
    while(true) {
        pid = waitpid(-1, NULL, WNOHANG);
        if(pid <= 0)
            break;
        printf("Job %d removed from job list\n", pid);
    }
    // WNOHANG: pid == 0 means no stopped, continued or exited children
    // errno = ECHILD no children
    exitUnless(pid == 0 || errno == ECHILD, stderr, kWaitFailed,
            "waitpid failed within reapChild sighandler.%d\n", errno);
}

int main(int argc, char* argv[]) {
    exitIf(signal(SIGCHLD, reapChild) == SIG_ERR, stderr, kSignalFailed,
            "Failed to install SIGCHLD handler.\n");
    for(size_t i = 0; i < 3; i++) {
        pid_t pid = fork();
        exitIf(pid == -1, stderr, kForkFailed, "fork function failed\n");
        if(pid == 0) {
            char* listArguments[] = {"date", NULL};
            exitIf(execvp(listArguments[0], listArguments) == -1, stderr,
                    kExecFailed, "execvp function failed.\n");
            return 0;
        }
        sleep(1);
        printf("Job %d added to job list!\n", pid);
    }
    return 0;
}
