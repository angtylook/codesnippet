#include <stdio.h>

int main()
{
    int test = 0x12345678;
    char* p = (char*)&test;
    for(int i = 0; i < sizeof(int); i++)
    {
        char c = *p;
        printf("%x ", c);
        p++;
    }
    return 0;
}
