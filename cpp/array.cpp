#include <string>
#include <array>
#include <iostream>
#include <stdio.h>
#include <boost/noncopyable.hpp>
#include "boost/stacktrace.hpp"
#include "boost/beast.hpp"

class Demo : public boost::noncopyable
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
    boost::beast::http::request req;
    return 0;
}
