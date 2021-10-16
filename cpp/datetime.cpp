//
// Created by jxunhappy on 2017/7/30.
//

#include <chrono>
#include <iostream>
#include <ctime>

int main()
{
    std::ratio<2, 10> r;
    std::cout << r.num << '/' << r.den << std::endl;

    std::cout << std::chrono::system_clock::period::num
              << '/' << std::chrono::system_clock::period::den
              << std::endl;

    std::time_t startTime = 1634036907;
    char buffer[100] = {};
    auto n = std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&startTime));
    buffer[n] = '\0';
    std::string out = buffer;
    std::cout << out << std::endl;
    return 0;
}