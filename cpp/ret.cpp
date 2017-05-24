#include <string>
#include <iostream>

struct Obj
{
    std::string str;
    Obj() {
        std::cout << str << " construct" << std::endl;
    };

    Obj(const Obj& o) {
        str = o.str;
        std::cout << str << " copy construct" << std::endl;
    }
    Obj& operator=(const Obj& o) {
        //str = o.str;
        std::cout << str << " assign operator" << std::endl;
        return *this;
    }
    ~Obj() {
        std::cout << str << " destruct" << std::endl;
    };
};

Obj func()
{
    Obj o;
    o.str = "in func";
    return o;
}

int main()
{
    int sz = sizeof(Obj);
    Obj obj;
    obj.str = "main";
    obj = func();
    return 0;
}