#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

int main()
{
    std::vector<int> ints(30);
    std::iota(ints.begin(), ints.end(), 1);
    std::copy(ints.end() -10, ints.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::copy(ints.begin(), ints.end() - 10, std::ostream_iterator<int>(std::cout, " "));

    std::vector<int> last(10);
    std::copy_backward(ints.end() - 10, ints.end(), last.end());
    std::cout << std::endl;
    std::copy(last.begin(), last.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
