#include <map>
#include <string>
#include <iostream>
#include <tuple>
#include <vector>
#include <string.h>

enum class WealthType {
    Invalid = 0,
    Gold,
    Diamond
};

struct Wealth {
    WealthType type = WealthType::Invalid;
    int id = 0;
};

bool operator< (const Wealth& lhs, const Wealth& rhs) {
    return std::tie(lhs.type, lhs.id) < std::tie(rhs.type, lhs.id);
}

constexpr int pow(int base, int exp) noexcept;

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
    if(WealthType::Invalid < WealthType::Gold)
        std::cout << "comparable" << std::endl;

    std::map<Wealth, std::string> m;
    Wealth gold {WealthType::Gold, 1};
    Wealth diamond {WealthType::Diamond, 1};
    m.insert({gold, "gold"});
    m.insert({diamond, "diamond"});
    for(auto& val : m) {
        std::cout << static_cast<int>(val.first.type) << " " <<  val.first.id << " " << val.second << std::endl;
    }
    std::vector<std::string> vs;
    SplitString("1:2, 4:8, 9:3", ",", vs);
    for(auto& str : vs)
        std::cout << str << std::endl;
    return 0;
}
