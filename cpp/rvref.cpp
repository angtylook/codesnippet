#include <functional>
#include <string>
#include <iostream>

template<typename T>
class WhichType;

void call(std::function<void()>&& func)
{
    func();
}

class Widget {
    public:
        std::string val_;
};

void funcsl(std::string& s)
{
}

void funcrl(std::string&& s)
{
}

void rw(Widget&& w)
{
    funcsl(w.val_);
    funcrl(w.val_);
    WhichType<decltype(w)> wtype;
    WhichType<decltype(w.val_)> mtype;
    WhichType<decltype(std::move(w.val_))> vtype;
    WhichType<decltype(std::forward<std::string>(w.val_))> ftype;
    std::string lval;
    WhichType<decltype(lval)> ltype;
}

int main()
{
    Widget w;
    rw(std::move(w));
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
