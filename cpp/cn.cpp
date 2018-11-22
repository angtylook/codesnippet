#include <string>
#include <locale>
#include <iostream>

using namespace std::literals;

template<typename T>
concept bool EqualityComparable() {
    return requires(T a, T b) {
        { a == b } -> bool;
    };
}

template <EqualityComparable T>
void f(T&&)
{
    std::cout << "comparable";
}

int main() {
    f("abc"s);
    f(std::use_facet<std::ctype<char>>(std::locale{}));
    return 0;
}

