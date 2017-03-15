#include <iostream>

int main()
{
    long l = 222;
    short const &s = l;

    l = 0;
    std::cout << "l = " << l << std::endl;
    std::cout << "s = " << s << std::endl;
    return 0;
}

