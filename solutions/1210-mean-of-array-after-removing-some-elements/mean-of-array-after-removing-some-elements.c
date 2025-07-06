//C Code
int comparator(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}
double trimMean(int* arr, int arrSize) {
    int sum = 0, cnt = 0, len = arrSize;
    qsort(arr, arrSize, sizeof(int), comparator);
    int percent5 = len / 20;
    for (int i = percent5; i < len - percent5; ++i){
        sum += arr[i];
        cnt++;
    }
    return (double)sum / cnt;
}