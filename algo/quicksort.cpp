#include <vector>
#include <iostream>

// assert r - p > 1
size_t Partiition(std::vector<int>& arr, size_t p, size_t r)
{
    int pivot = arr[p];
    size_t i = p;
    size_t j = p + 1;
    // (p, i] < x, (i, j) > x
    // asset (e,e] or (e, e+1) contains no elements.
    int temp;
    while(j < r) {
        if(arr[j] <= pivot) {
            ++i;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        ++j;
    }
    arr[p] = arr[i];
    arr[i] = pivot;
    return i;
}

/*
 * must: p less or equal r.
 * range in arr as [p,r)
 * include p but not r.
 */
void QuickSortHelper(std::vector<int>& arr, size_t p, size_t r)
{
    // p == r: no elemnts
    // r - p == 1: 1 elements
    // in the two case above arr is sorted.
    if(r - p > 1)
    {
        size_t q = Partiition(arr, p, r);
        // sub problem one, range [p, q)
        QuickSortHelper(arr, p, q);
        // sub problem two, range [q+1, r)
        QuickSortHelper(arr, q+1, r);
    }
}

void QuickSort(std::vector<int>& arr)
{
    QuickSortHelper(arr, 0, arr.size());
}

void printvec(const std::vector<int>& arr, const std::string& msg)
{
    std::cout << msg << std::endl;
    for(auto& e: arr) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr0;
    QuickSort(arr0);
    printvec(arr0, "arr0");

    std::vector<int> arr1{1};
    QuickSort(arr1);
    printvec(arr1, "arr1");

    std::vector<int> arr2{3,2};
    QuickSort(arr2);
    printvec(arr2, "arr2");

    std::vector<int> arrn{13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
    QuickSort(arrn);
    printvec(arrn, "arrn");
    return 0;
}
