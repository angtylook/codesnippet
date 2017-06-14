#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>  // for exit
#include <sys/wait.h>
#include <errno.h>
#include "exit_utils.h"

static const int kNumChildren = 8;
static const int kForkFail = 1;
static const int kWaitFail = 2;
static const int kExitFail = 4;

int main(int argc, char* argv[])
{
    pid_t children[kNumChildren];
    for(size_t i = 0; i < kNumChildren; i++) {
        children[i] = fork();
        exitIf(children[i] == -1, stderr, kForkFail, "Fork function failed.\n");
        if(children[i] == 0)
            exit(110 + i);
    }
    
    for (size_t i = 0; i < kNumChildren; ++i) {
        int status;
        exitUnless(waitpid(children[i], &status, 0) == children[i],
                stderr, kWaitFail, "Intentional wait on child %d failed.\n",
                children[i]);
        exitUnless(WIFEXITED(status) && (WEXITSTATUS(status) == (110 + i)),
                stderr, kExitFail, "Corrent child %d exited abnormally.\n",
                children[i]);
    }
    return 0;
}
