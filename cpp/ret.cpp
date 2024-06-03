#include <string>
#include <iostream>
#include <regex>

int main()
{
    std::string html =
        "<p style=\"font-size: 15;color: blue;\">公元<span style=\"color: "
        "red;font-weight: "
        "bold;\">2024年5月29日</span>，神创建了本邮件，<br><span "
        "style=\"font-style: italic; "
        "font-weight: "
        "bold;\">宣告摸鱼邮件系统诞生</"
        "span>。从此，世界有了光和热，人类由此繁衍生息。</p>";

    std::vector<std::string> tags;
    std::vector<std::string> contents;

    std::regex contentRegex(R"(<(\S+)(.*)>(.*)</(\1)>)");
    std::smatch match;

    if (std::regex_search(html, match, contentRegex)) {
        for (auto& sm : match)
        {
            std::cout << sm.str() << std::endl;
        }
    }
    return 0;
}