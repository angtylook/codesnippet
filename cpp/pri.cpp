#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

struct S
{
    std::map<int, std::string> m;
    int i;
    std::string s;
};

void func(const std::vector<std::string>& s)
{
    for(auto& e : s)
        std::cout << e << std::endl;
}

int main()
{
    S s;
    const S& rs = s;
    const_cast<S&>(rs).m[1] = std::string("hello");
    func({"abc", "def", "g", "hij"});
    return 0;
}

