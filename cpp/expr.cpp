#include <map>
#include <string>
#include <iostream>
#include <tuple>

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

constexpr int pow(int base, int exp) noexcept
{
    return 0;
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
    return 0;
}
