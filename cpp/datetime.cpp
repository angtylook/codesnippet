//
// Created by jxunhappy on 2017/7/30.
//

#include <chrono>
#include <iostream>

int main()
{
    std::ratio<2, 10> r;
    std::cout << r.num << '/' << r.den << std::endl;

    std::cout << std::chrono::system_clock::period::num
              << '/' << std::chrono::system_clock::period::den
              << std::endl;

    return 0;
}