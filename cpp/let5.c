#include <stdio.h>
#include <ctype.h>

void lowercase(char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main(int argc, char* argv[]) {
    int x = 4;
    char* str = "hello";
    lowercase(str);
    printf("%s\n", str);
    return 0;
}
