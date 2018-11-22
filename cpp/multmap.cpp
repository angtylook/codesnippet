#include <map>
#include <functional>
#include <iostream>

int main()
{
    std::multimap<int, char, std::greater<int>> sorted;
    sorted.insert(1, 'a');
    sorted.insert(1, 'a');
    sorted.insert(2, 'B');
    sorted.insert(3, 'C');
    sorted.insert(3, 'C');
    sorted.insert(1, 'c');

    for(auto& v : sorted)
    {
        std::cout << v.first << ':' << v.second << std::endl;
    }
    return 0;
}
