#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  // for waitpid
#include <time.h>
#include "exit_utils.h"

static const int kForkFailure = 1;

int main(int argc, char* argv[])
{
    srandom(time(NULL));
    printf("I'm unique and just get printed once.\n");
    pid_t pid = fork();
    exitIf(pid == -1, stderr, kForkFailure, "Call to fork failed...aborting.\n");
    bool parent = pid != 0;
    if((rand() % 2 == 0) == parent)
        sleep(1);
    if(parent)
        waitpid(pid, NULL, 0);
    printf("I get printed twice (this one is being printed from the %s).\n",parent ? "parent" : "child");
    return 0;
}


