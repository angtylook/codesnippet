#include <iostream>

class A
{
    public:
        void func(int i);
};

void A::func(const int i)
{
    std::cout << "func const" << std::endl;
}

int main()
{
    A a;
    a.func(1);
    return 0;
}

