#include <future>
#include <iostream>
#include "boost/algorithm/string.hpp"

int main()
{
    std::async([](){std::cout << "Hello ";});
    std::async([](){std::cout << "World!\n";});

    std::string str1("  hello world!  ");
    boost::to_upper(str1);
    std::cout << str1 << std::endl;

    boost::trim(str1);
    std::cout << str1 << std::endl;

    std::string str2 = boost::to_lower_copy(boost::ireplace_first_copy(str1, "hello", "goodbye"));

    std::cout << str2 << std::endl;

    return 0;
}


