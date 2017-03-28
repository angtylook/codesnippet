int sum_array(int arr[], int nelems) {
    int sum = 0;
    for(int i = 0; i < nelems; i++) {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    sum_array(arr, 5);
    return 0;
}
