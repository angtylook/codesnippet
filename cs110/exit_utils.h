#ifndef EXIT_UTILS_H_
#define EXIT_UTILS_H_

#include <stdio.h>
#include <stdarg.h>

void exitUnless(
    bool test,
    FILE* stream,
    int code,
    const char* control,
    ...);

void exitIf(
    bool test,
    FILE* stream,
    int code,
    const char* control,
    ...);

#endif

