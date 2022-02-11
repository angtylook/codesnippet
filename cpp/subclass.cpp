#include <iostream>
#include <string>

class Base {
    public:
    Base(std::string name):name_(name){}
    void call() { std::cout << "call" << std::endl;}
    virtual void vir_call() {std::cout << "vir call" << std::endl;}
private:
    std::string name_;
};

class Derived: public Base {
public:
    Derived():Base("d"){}
    void func() {std::cout << "func" << std::endl;}
};

int main() {
    Derived* d = (Derived*)(new Base("base"));
    d->func();
    d->call();
    d->vir_call();
    return 0;
}
