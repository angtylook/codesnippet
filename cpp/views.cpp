#include <ranges>
#include <iostream>

int main() {
    for (int i : std::views::iota(1, 10))
        std::cout << i << ' ';
    std::cout << '\n';
    
    for (int i : std::views::iota(1, 10) | std::views::take(5))
        std::cout << i << ' ';
    std::cout << '\n';

    for (int i : std::views::iota(1, 10) | std::views::take_while([](int i){return i < 7;}))
        std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}