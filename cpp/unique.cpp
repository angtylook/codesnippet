#include <map>
#include <functional>
#include <iostream>
#include <string>
#include <format>
#include <chrono>
#include <thread>

long genMsgId(long lUid, long lTaskId)
{
  std::string id = std::format("{}-{}-{}-{}", std::chrono::system_clock::now().time_since_epoch().count()/1000000, lTaskId,lUid,std::rand()%100000);
  std::cout << id << std::endl;
  
  unsigned int seed = 131;
  unsigned int hash = 0;
  const char * str = id.c_str();
  while (*str)
  {
    hash = hash * seed + (*str++);
  }

  return (hash & 0x7FFFFFFF);
}

using namespace std::chrono_literals;

int main()
{
    long uid = 1199513165423;
    long taskid = 18279;
    for(int i = 0; i < 20; i++)
    {
        std::cout << genMsgId(uid, taskid) << std::endl;
        std::this_thread::sleep_for(30ms);
    }
    return 0;
}
