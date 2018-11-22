#include <stdio.h>
#include <time.h>

int main()
{
    char buffer[1024] = {0};
    auto timeval = time(nullptr);
    auto* timeNow = localtime(&timeval);
    sprintf(buffer, "%.4d-%.2d-%.2d", timeNow->tm_year, timeNow->tm_mon + 1, timeNow->tm_mday);
    printf(buffer);
    return 0;
}

