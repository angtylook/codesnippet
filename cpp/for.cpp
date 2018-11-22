#include <vector>
#include <iostream>
#include <algorithm>


int main()
{
    std::vector<int> v {1,3,2,9,5,4,8,6,7,0};
    std::sort(v.begin(), v.end());
    for(auto item : v)
        std::cout << item << " ";
    std::cout << std::endl;
}
