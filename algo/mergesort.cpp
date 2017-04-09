#include <vector>
#include <iostream>

// merge arr[p, q) and arr[q, r) into arr[p, r)
// total(r - p) elements.
void Merge(std::vector<int>& arr, size_t p, size_t q, size_t r)
{
    size_t i = p;        // array start index
    size_t n1 = q - p;   // left size
    size_t n2 = r - q;   // right size

    std::vector<int> left;
    std::vector<int> right;
    while(p < q) {
        left.push_back(arr[p]);
        ++p;
    }
    while(q < r) {
        right.push_back(arr[q]);
        ++q;
    }

    p = 0;
    q = 0;
    while(i < r) {
        if(p >= n1 || q >= n2)
            break;
        if(left[p] < right[q]) {
            arr[i] = left[p];
            ++p;
        } else {
            arr[i] = right[q];
            ++q;
        }
        ++i;
    }

    while(p < n1) {
        arr[i] = left[p];
        ++i;
        ++p;
    }

    while(q < n2) {
        arr[i] = right[q];
        ++i;
        ++q;
    };
}

/*
 * must: p less or equal r.
 * range in arr as [p,r)
 * include p but not r.
 */
void MergeSortHelper(std::vector<int>& arr, size_t p, size_t r)
{
    // p == r: no elemnts
    // r - p == 1: 1 elements
    // in the two case above arr is sorted.
    if(r - p > 1)
    {
        // because: p <= r -> p + r < r + r < 2r
        // so: q = (p + r)/2 < 2r/2 = r
        size_t q = (p + r)/2;
        // sub problem one, range [p, q)
        MergeSortHelper(arr, p, q);
        // sub problem two, range [q, r)
        MergeSortHelper(arr, q, r);
        // merge p <= q < r
        Merge(arr, p, q, r);
    }
}

void MergeSort(std::vector<int>& arr)
{
    MergeSortHelper(arr, 0, arr.size());
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
    MergeSort(arr0);
    printvec(arr0, "arr0");

    std::vector<int> arr1{1};
    MergeSort(arr1);
    printvec(arr1, "arr1");

    std::vector<int> arr2{3,2};
    MergeSort(arr2);
    printvec(arr2, "arr2");

    std::vector<int> arrn{2, 4, 5, 7, 1, 2, 3, 6};
    MergeSort(arrn);
    printvec(arrn, "arrn");
    return 0;
}
