#include <future>
#include <iostream>

int main()
{
    std::async([](){std::cout << "Hello ";});
    std::async([](){std::cout << "World!\n";});
    return 0;
}
