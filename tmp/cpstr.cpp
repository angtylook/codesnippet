#include <cstdio>
#include <string>

using namespace std;

int main(int argc,char** argv)
{
    string str1 = "hello world";
    string str2 = str1;

    printf("Sharing the memory:\n");
    printf("\tstr1 address: %x\n",str1.c_str());
    printf("\tstr2 address: %x\n",str2.c_str());

    str1[1] = 'q';
    str2[1] = 'w';

    printf("After Copy On Write:\n");
    printf("\tstr1 address: %x\n",str1.c_str());
    printf("\tstr2 address: %x\n",str2.c_str());

    return 0;
}
