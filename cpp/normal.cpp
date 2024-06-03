#include <iostream>
#include <random>

int main()
{
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<double> d{36.5, 0.5};
    for(int i = 0; i < 7; i++)
    {
        std::cout << d(gen) << " ";
    }
    return 0;
}
