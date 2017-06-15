#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "exit_utils.h"

static const char* const kCommandPrompt = "simplesh>";
static const unsigned short kMaxCommandLength = 2048;
static const unsigned short kMaxArgumentCount = 128;

static const int kForkFailed = 1;
static const int kWaitFailed = 2;

static void pullRest() {
    while(getchar() != '\n');
}

static char* skipSpaces(const char* str) {
    while(*str == ' ')
        str++;
    return (char*)str;
}

static void readCommand(char command[], size_t len) {
    char control[64] = {'\0'};
    command[0] = '\0';
    sprintf(control, "%%%zu[^\n]%%c",len);
    while(true) {
        printf("%s ", kCommandPrompt);
        char termch;
        if(scanf(control, command, &termch) < 2)
        {
            pullRest();
            return;
        }
        if(termch == '\n')
            return;
        fprintf(stderr, "Command shouldn't exceed %hu characters."
                "Ignoring.\n", kMaxCommandLength);
        pullRest();
    }
}

static int parseCommandLine(char* command, char* arguments[], int len) {
    command = skipSpaces(command);
    int count = 0;
    while(count < len - 1 && *command != '\0') {
        arguments[count++] = command;
        char* found = strchr(command, ' ');
        if(found == NULL)
            break;
        *found = '\0';
        command = found + 1;
        command = skipSpaces(command);
    }
    arguments[count] = NULL;
    return count;
}

void printCommandLineArguments(char* arguments[]) {
    int count = 0;
    while(*arguments != NULL) {
        count++;
        printf("%2d: \"%s\"\n", count, *arguments);
        arguments++;
    }
}

static bool handleBuiltin(char* arguments[]) {
    if(strcasecmp(arguments[0], "quit") == 0) {
        exit(0);
    }
    return strcmp(arguments[0], "&") == 0;
}

static pid_t forkProcess() {
    pid_t pid = fork();
    exitIf(pid == -1, stderr, kForkFailed, "fork function failed.\n");
    return pid;
}

static void waitForChildProcess(pid_t pid) {
    exitUnless(waitpid(pid, NULL, 0) == pid, stderr, kWaitFailed,
            "Error waiting in foreground for process %d to exit", pid);
}

int main(int argc, char* argv[]) {
    while(true) {
        char command[kMaxCommandLength + 1];
        readCommand(command, sizeof(command) - 1);
        if(feof(stdin))
            break;
        char* arguments[kMaxArgumentCount + 1];
        int count = parseCommandLine(command, arguments, sizeof(arguments)/sizeof(arguments[0]));
        if(count == 0)
            continue;
        bool builtin = handleBuiltin(arguments);
        if(builtin)
            continue;
        bool isBackgroundProcess = strcmp(arguments[count - 1], "&") == 0;
        if(isBackgroundProcess)
            arguments[--count] = NULL;
        pid_t pid = forkProcess();
        if(pid == 0) {
            if(execvp(arguments[0], arguments) < 0) {
                printf("%s: Coomand not found\n", arguments[0]);
                exit(0);
            }
        }
        if(!isBackgroundProcess) {
            waitForChildProcess(pid);
        } else {
            printf("%d %s\n", pid, command);
        }
    }
    printf("\n");
    return 0;
}


