//
// Created by jxunhappy on 2017/7/30.
//

#include <chrono>
#include <iostream>
#include <ctime>
#include <string>

long TimestampToSeconds(const std::string& timestr)
{
  struct tm time;
  memset(&time, 0, sizeof(struct tm));
  strptime(timestr.c_str(), "%Y-%m-%d %H:%M:%S", &time); //2021-08-22 00:00:00
  time_t t = mktime(&time);
  return t;
}

time_t ToTimestamp(const std::string& timestr)
{
  struct tm time;
  std::memset(&time, 0, sizeof(struct tm));
  strptime(timestr.c_str(), "%Y-%m-%d %H:%M:%S", &time); //2021-08-22 00:00:00
  time.tm_isdst = 0;
  time_t t = mktime(&time);
  struct tm ltm = *std::localtime(&t);
  return mktime(&ltm);
}

int main()
{
    std::ratio<2, 10> r;
    std::cout << r.num << '/' << r.den << std::endl;

    std::cout << std::chrono::system_clock::period::num
              << '/' << std::chrono::system_clock::period::den
              << std::endl;

    std::time_t startTime = 1634036907;
    char buffer[100] = {};
    auto n = std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&startTime));
    buffer[n] = '\0';
    std::string out = buffer;
    std::cout << out << std::endl;
    return 0;
}