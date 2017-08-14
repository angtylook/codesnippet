#include <string>
#include <array>
#include <iostream>
#include <stdio.h>

class Demo
{
public:
    Demo()
    {
        arr_.fill(nullptr);
    }
    void showArray()
    {
        for(auto p : arr_)
        {
            printf("%p\n", p);
        }
    }
private:
    static constexpr int kArraySize = 10;
    std::array<char*, kArraySize> arr_;
};

int main()
{
    Demo demo;
    demo.showArray();
    return 0;
}
