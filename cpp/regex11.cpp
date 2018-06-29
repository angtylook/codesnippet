#include <iostream>
#include <regex>

int main()
{
    std::cout << "test regex simple usage:\n";
    std::string email_pattern(R"((\w)+(\.\w+)*@(\w)+((\.\w+)+))");
    try {
        std::regex email_regex(email_pattern);
        std::smatch results;
        std::string test_email_str = "My email is yubo322@126.com";
        if (std::regex_search(test_email_str, results, email_regex)) {
            std::cout << results.str() << std::endl;
        }
    } catch (std::regex_error e) {
        std::cout << e.what() << '\t' << e.code() << std::endl;
    }
    std::cout << "test regex simple usage done.\n" << std::endl;
    return 0;
}

