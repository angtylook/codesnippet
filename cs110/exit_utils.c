#include <stdlib.h>
#include <stdbool.h>
#include "exit_utils.h"

void exitUnless(
        bool test,
        FILE* stream,
        int code,
        const char* control,
        ...) {
    if(test)
        return;
    va_list arglist;
    va_start(arglist, control);
    vfprintf(stream, control, arglist);
    va_end(arglist);
    exit(code);
}

void exitIf(
        bool test,
        FILE* stream,
        int code,
        const char* control,
        ...) {
    if(!test)
        return;
    va_list arglist;
    va_start(arglist, control);
    vfprintf(stream, control, arglist);
    va_end(arglist);
    exit(code);
}

