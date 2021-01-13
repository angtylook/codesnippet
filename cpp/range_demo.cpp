#include <concepts>
#include <ranges>
#include <iostream>
#include <vector>

namespace vs = std::ranges::views;

int main() {
    std::vector v1 {"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"};
    std::vector v2 {"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"};

    auto a = v1 | vs::cycle;
    auto b = v2 | vs::cycle;
    auto c = vs::zip(a, b) | vs::take(60);
    
    //输出甲子 乙丑 丙寅 丁卯 戊辰 己巳 庚午 辛未 壬申 癸酉 甲戌 乙亥 丙子 丁丑 戊寅…………
    for(auto&& [x, y]: c)
        std::cout<<x<<y<<" ";
    std::cout<<"\n";
    return 0;
}