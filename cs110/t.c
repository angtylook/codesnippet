#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#define DEFAULT_FLAGS (O_WRONLY|O_CREAT|O_TRUNC)
#define DEFAULT_PERMISSIONS 0644

static void writeall(int fd, const char buffer[], size_t len) {
    size_t numBytesRead = 0;
    while(numBytesRead < len) {
        numBytesRead += write(fd, buffer + numBytesRead, len - numBytesRead);
    }
}

int main(int argc, char* argv[])
{
    int fds[argc];
    fds[0] = STDOUT_FILENO;
    for(size_t i = 1; i < argc; i++)
        fds[i] = open(argv[i], DEFAULT_FLAGS, DEFAULT_PERMISSIONS);

    char buffer[2048];
    while(true) {
        ssize_t numRead = read(STDIN_FILENO, buffer, sizeof(buffer));
        if(numRead == 0)
            break;
        for(size_t i = 0; i < argc; i++)
            writeall(fds[i], buffer, numRead);
    }
    for(size_t i = 1; i < argc; i++)
        close(fds[i]);
    return 0;
}
