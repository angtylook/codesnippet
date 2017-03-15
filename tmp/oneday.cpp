#include <iostream>

int main(int argc,char** argv)
{
    char mylife[] = "... I always love you ...";
    mylife[4] = '\0';
    std::cout << mylife << std::endl;
    return 0;
}

