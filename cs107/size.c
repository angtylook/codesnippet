#include <stdio.h>

int main(int argc, char* argv[])
{
  printf("char: %lu bytes, %lu bits\n", sizeof(char), sizeof(char)*8);
  printf("char*: %lu bytes, %lu bits\n", sizeof(char*), sizeof(char*)*8);
  printf("short:: %lu bytes, %lu bits\n", sizeof(short), sizeof(short)*8);
  printf("int: %lu bytes, %lu bits\n", sizeof(int), sizeof(int)*8);
  printf("long: %lu bytes, %lu bits\n", sizeof(long), sizeof(long) * 8);
  printf("float: %lu bytes, %lu bits\n", sizeof(float), sizeof(float)*8);
  printf("double: %lu bytes, %lu bits\n", sizeof(double), sizeof(double)*8);
  return 0;
}

