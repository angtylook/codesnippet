#include <map>
#include <set>
#include <utility>
#include <functional>
#include <iostream>

int main()
{
    //std::multimap<int, char, std::greater<int>> sorted;
    std::set<std::pair<int, char>, std::greater<std::pair<int, char>>> sorted;
    sorted.insert({1, 'a'});
    sorted.insert({1, 'a'});
    sorted.insert({2, 'B'});
    sorted.insert({3, 'C'});
    sorted.insert({3, 'C'});
    sorted.insert({1, 'c'});

    for(auto v: sorted)
    {
        std::cout << v.first << ':' << v.second << std::endl;
    }
    for(auto up = sorted.upper_bound({2, 'B'}); up != sorted.end(); ++up)
    {
        std::cout << up->first << ':' << up->second << std::endl;
    }
    return 0;
}
