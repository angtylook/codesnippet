#include <iostream>
#include <string>


template<typename T>
class WhichType;

template<typename T>
void func(T&& args)
{
   WhichType<T> type; 
}

template<typename T>
struct Index
{
    //static_assert(false, "Not Support");
    //constexpr static int protocol = -1;
};

template<>
struct Index<char>
{
    constexpr static int protocol = sizeof(char);
};

template<>
struct Index<int>
{
    constexpr static int protocol = sizeof(int);
};

template<>
struct Index<double>
{
    constexpr static int protocol = sizeof(double);
};

int main()
{
    //func("hello");
    std::cout << "char: " << Index<char>::protocol << std::endl;
    std::cout << "int: " << Index<int>::protocol << std::endl;
    std::cout << "double: " << Index<double>::protocol << std::endl;
    //std::cout << "float: " << Index<float>::protocol << std::endl;
    return 0;
}
