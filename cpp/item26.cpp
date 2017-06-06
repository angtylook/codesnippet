#include <iostream>
#include <string>


template<typename T>
class WhichType;

template<typename T>
void func(T&& args)
{
   WhichType<T> type; 
}

int main()
{
    func("hello");
    return 0;
}
