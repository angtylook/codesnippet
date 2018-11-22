#include <map>
#include <string>
#include <iostream>

int main()
{
    std::string empty;
    std::map<std::string, int> m;
    m.emplace(empty, 1);
    m.emplace(empty, 1);
    return 0;
}

