#include <iostream>
#include <string>

std::string trimEmail(const std::string& mail)
{
  auto n = mail.find("@");
  if (n == std::string::npos)
  {
    return mail;
  }
  return mail.substr(0, n);
}

int main()
{
    std::cout << "1." << trimEmail("zhangzhiwei@huya.com") << std::endl;
    std::cout << "2." << trimEmail("zhangzhiwei") << std::endl;

    for(int i = 0; i < 10; i++)
    {
      try {
          if (i % 2 == 0) {
              if(i == 6)
              {
                throw std::logic_error("value is 6");
              }
              continue;
          }
          std::cout << "proc " << i << std::endl;
      } catch (const std::exception& e) {
          std::cout << "exception:" << e.what() << std::endl;
      }
    }
    return 0;
}
