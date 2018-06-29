#include <iostream>
#include <string>

int main()
{
    std::string url("http://abcde.file.lksek.com/lsekgl");
    url.replace(url.find("file"), 4, "gzcos");
    std::cout << url << std::endl;
    return 0;
}
