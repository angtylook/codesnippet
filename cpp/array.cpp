#include <string>
#include <array>
#include <iostream>
#include <stdio.h>

class Demo
{
public:
    Demo()
    {
        // arr_.fill(nullptr);
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
    std::array<char*, kArraySize> arr_{};  // fill with nullptr
};

class CArray {
public:
    CArray();
    char name[10];  // will copy
};

CArray::CArray()
{
    name[0] = 'h';
    name[1] = 'e';
    name[2] = 'l';
    name[3] = 'l';
    name[4] = 'o';
    name[5] = '\0';
}

int main()
{
    Demo demo;
    demo.showArray();

    CArray arr1;
    CArray arr2(arr1);
    arr2.name[0] = 'f';
    CArray arr3;
    arr3 = arr2;
    std::cout << "arr1:" << arr1.name << std::endl;
    std::cout << "arr2:" << arr2.name << std::endl;
    std::cout << "arr3:" << arr3.name << std::endl;
    return 0;
}


