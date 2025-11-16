#include <iostream>
#include <array>
#include <limits>

int recursive(std::array<int, 5>& arr, int start, int end)
{
    if(start == end)
    {
        return arr[start];
    }
    
}



int main()
{
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    int max_sum = arr[0];
    int partal_sum = arr[0];
    for(int i = 1; i < arr.size(); ++i)
    {
        if(arr[i] > partal_sum + arr[i])
        {
            partal_sum = arr[i];
        }
        else
        {
            partal_sum += arr[i];
        }
        if(partal_sum > max_sum)
        {
            max_sum = partal_sum;
        }
        std::cout << "max_sum: " << max_sum << std::endl;
    }
    return 0;
}
