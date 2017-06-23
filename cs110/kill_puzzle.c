#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

static pid_t pid;
static int counter = 0;

static void parentHandler(int unused) {
    counter++;
    printf("counter = %d\n", counter);
    kill(pid, SIGUSR1);
}

static void childHandler(int unused) {
    counter += 3;
    printf("counter = %d\n", counter);
}

int main(int argc, char* argv[]) {
    signal(SIGUSR1, parentHandler);
    if((pid = fork())  == 0 ) {
        signal(SIGUSR1, childHandler);
        kill(getppid(), SIGUSR1);
        return 0;
    }

    waitpid(pid, NULL, 0);
    counter += 7;
    printf("counter = %d \n", counter);
    return 0;
}
