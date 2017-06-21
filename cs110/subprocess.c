#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "exit_utils.h"

typedef struct subprocess_t {
    pid_t pid;
    int infd;
} subprocess_t;

subprocess_t subprocess(const char* command) {
    int fds[2];
    pipe(fds);
    subprocess_t process = { fork(), fds[1] };
    if(process.pid == 0) {
        dup2(fds[0], STDIN_FILENO);
        close(fds[0]);
        close(fds[1]);
        char* argv[] = {"/bin/sh", "-c", (char*)command, NULL };
        execvp(argv[0], argv);
        // what if execvp failed???
    }
    close(fds[0]);
    return process;
}

int main(int argc, char* argv[])
{
    subprocess_t sp = subprocess("/usr/bin/sort");
    const char* words[] = {
        "felicity", "umbrage", "subsurration", "halcyon",
        "pulchritude", "ablution", "somnolent", "indefatigable"
    };

    for(size_t i = 0; i < sizeof(words)/sizeof(words[0]); i++) {
        dprintf(sp.infd, "%s\n", words[i]);
    }
    close(sp.infd);
    int status;
    pid_t pid = waitpid(sp.pid, &status, 0);
    return pid == sp.pid && WIFEXITED(status) ? WEXITSTATUS(status): -1;
}


