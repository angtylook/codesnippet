#include <functional>
#include <string>
#include <iostream>

template<typename T>
class WhichType;

void call(std::function<void()>&& func)
{
    func();
}

void funcsl(std::string& s)
{
    //WhichType<decltype(s)> t;
}

void func(std::string&& s)
{

    //WhichType<decltype(s)> t;
}

void funcrl(std::string&& s)
{
    std::string cp("cp");
    std::cout << s << std::endl;
    cp = s;
    std::cout << s << std::endl;
    //WhichType<decltype(s)> t;
    func(std::move(s));
}

int main()
{
    auto&& l = [](){ std::cout << "lambda" << std::endl;};
    l();
    auto r = std::move(l);
    r();
    l();
    //WhichType<decltype(l)> type;
    //WhichType<decltype(l)> type;
    std::string s("ss");
    funcsl(s);
    funcrl(std::move(s));
    return 0;
}
