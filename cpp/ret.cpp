#include <iostream>
#include <regex>
#include <stack>
#include <string>

std::regex contentRegex(R"(<(\S+)(.*?)>(.*?)</(\1)>)");

struct Elem {
    std::string text;
    std::string style;
};

std::vector<Elem> elems;
std::stack<std::string> styles;

void handle(const std::string& html) {
    std::cout << "handle->|" << html << "|" << std::endl;
    std::smatch match;
    if (std::regex_search(html, match, contentRegex)) {
        std::string prefix = match.prefix().str();
        std::cout << "prefix->|" << prefix << "|" << std::endl;
        if (!prefix.empty()) {
            Elem e;
            e.text = prefix;
            e.style = styles.top();
            elems.push_back(e);
        }
        styles.push(match[2].str());
        std::cout << "style->|" << match[2].str() << "|" << std::endl;
        handle(match[3].str());
        //std::cout << "content->|" << match[3].str() << "|" << std::endl;
        handle(match.suffix().str());
    } else if (!html.empty()) {
        Elem e;
        e.text = html;
        e.style = styles.top();
        styles.pop();
        elems.push_back(e);
    }
}

int main() {
    std::string html =
        R"(<p style="font-size:15; color:blue;">公元<span style="color:red; font-weight:bold;">2024年5月29日</span>，神创建了本邮件，<br><span style="font-style:italic; font-weight:bold">宣告摸鱼邮件系统诞生</span>。从此，世界有了光和热，人类由此繁衍生息。</p>)";

    std::smatch match;
    if (std::regex_search(html, match, contentRegex)) {
        styles.push(match[2].str());
        handle(match[3].str());
    }

    std::cout << "--------elems---------" << std::endl;
    for (auto& e : elems)
    {
        std::cout << "text: " << e.text << "|style: " << e.style << std::endl;
    }
    return 0;
}