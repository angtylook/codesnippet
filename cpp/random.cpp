#include <iostream>
#include <random>
#include <vector>

int main()
{
  std::default_random_engine eng;
  std::cout << "Min: " << eng.min() << std::endl;
  std::cout << "Max: " << eng.max() << std::endl;

  std::cout << eng() << std::endl;
  std::cout << eng() << std::endl;

  std::cout << eng << std::endl;

  std::normal_distribution<double> distr(10.0, 3.0);
    std::uniform_int_distribution uni(0,100);
  std::vector<int> v(101);
  for(int i = 0; i < 800; i++) {
    //int num = distr(eng);
    int num = uni(eng);
    if(num >= 0 && num < 100) {
      v[num]++;
    }
  }
  for(auto num: v) {
    for(int i = 0; i < num; ++i) {
      std::cout << '*';
    }
    std::cout << std::endl;
  }

  return 0;
}
