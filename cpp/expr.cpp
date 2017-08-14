#include <string>
#include <vector>
#include <string.h>
#include <iostream>

void SplitString(const std::string& source,
                 const std::string& splitBy,
                 std::vector<std::string>& retStrings)
{
    const char* searchStart = source.c_str();
    const char* searchEnd = searchStart + source.size();
    while (searchStart < searchEnd)
    {
        const char* find = strstr(searchStart, splitBy.c_str());
        if (!find)
        {
            retStrings.emplace_back(searchStart);
            return;
        }

        retStrings.emplace_back(std::string(searchStart, find - searchStart));
        searchStart = find + splitBy.size();
    }
}

int main(int argc, char* argv[])
{
    std::vector<std::string> vs;
    SplitString("1:2, 4:8, 9:3", ",", vs);
    for(auto& str : vs)
        std::cout << str << std::endl;
    return 0;
}
