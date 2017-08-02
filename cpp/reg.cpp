#include <regex>
#include <iostream>
#include <string>

int main() {
    std::string str;
    while(true) {
        std::cin >> str;
        //std::regex e("abc");  // match exactly
        //std::regex e("^abc");  // begin with
        //std::regex e("abc$");  // end with
        //std::regex e("abc.", std::regex_constants::icase);  // . Any character except newline.
        //std::regex e("abc?", std::regex_constants::icase);  // ? zero or one preceding character
        //std::regex e("abc*", std::regex_constants::icase);  // * zero or more preceding character
        //std::regex e("abc+", std::regex_constants::icase);  // + one or more preceding character
        //std::regex e("ab[cd]*", std::regex_constants::icase);  // [...] Any character inside the square brackets
        //std::regex e("ab[^cd]*", std::regex_constants::icase);  // [^...] Any character not inside the square brackets
        //std::regex e("ab[cd]{3}", std::regex_constants::icase);  // [...]{n} exactly n character not inside the square brackets
        //std::regex e("ab[cd]{3,}", std::regex_constants::icase);  // [...]{n,} n or more character not inside the square brackets
        //std::regex e("ab[cd]{3,5}", std::regex_constants::icase);  // [...]{n,m} n to m character not inside the square brackets
        //std::regex e("ab|de[fg]", std::regex_constants::icase);  // S | V  S or V
        std::regex e("(abc)|de+\\1", std::regex_constants::icase);  // \1 stand for (abc) the firs group, (abc) as a group

        bool match = std::regex_match(str, e);
        std::cout << (match ? "Matched": "Not matched") << std::endl << std::endl;
    }
    return 0;
}
