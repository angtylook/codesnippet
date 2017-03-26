int sum_array(int arr[], int nelems) {
    int sum = 0;
    for(int i = 0; i < nelems; i++) {
        sum += arr[i];
    }
    return sum;
}
