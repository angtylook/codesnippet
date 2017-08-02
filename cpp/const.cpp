#include <iostream>

constexpr int cube(int x) { return x*x*x; }

int main() {
  //std::cout << cube(3) << std::endl;
  static_assert(cube(3) == 27, "compile time cacul.");
  int a = 5;
  cube(a);
  //std::cout << cube(a) << std::endl;
  return 0;
}

