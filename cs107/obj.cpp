#include <string>

std::string func()
{
    std::string ret("return from func for test.");
    return ret;
}

int main()
{
    size_t sz = sizeof(std::string);
    std::string obj;
    obj = func();
    return 0;
}