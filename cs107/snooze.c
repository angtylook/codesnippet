#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int snooze(unsigned int secs)
{
    unsigned int left = 0;
    left = sleep(secs);
    printf("Slept for %d of %d secs.\n", secs - left, secs);
    return left;
}

void handler(int signal_no)
{
    printf("caught SIGINT!\n");
}

int main(int argc, char* argv[])
{
    signal(SIGINT, handler);
    snooze(atoi(argv[1]));
    return 0;
}