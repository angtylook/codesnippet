#include <functional>
#include <string>
#include <iostream>

template<typename T>
class WhichType;

void call(std::function<void()>&& func)
{
    func();
}

int main()
{
    std::string obj("hello world");
    auto func = [&obj]() {
        std::cout << obj << std::endl;
    };
    //WhichType<decltype(func)> test;
    std::cout << "before call: " << obj << std::endl;
    call(func);
    auto& f = func;
    f();
    func();
    std::cout << "after call: " << obj << std::endl;
    return 0;
}
