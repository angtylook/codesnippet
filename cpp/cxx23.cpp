#include <iostream>
#include <format>
#include <source_location>

int main()
{
    std::cout << std::format("{1} {0}", "hello world", "zhangzhiwei") << std::endl;
    auto cur = std::source_location::current();
    std::cout << "file: " << cur.file_name() << " line: " << cur.line() << " column: " << cur.column() << " func: " << cur.function_name() << std::endl;
    return 0;
}
