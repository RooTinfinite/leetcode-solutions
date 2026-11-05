int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size,
                         int d) {
    int cnt = 0;
    for (int i = 0; i < arr1Size; i++) {
        bool ok = true;
        for (int j = 0; j < arr2Size; j++) {
            ok = ok && (abs(arr1[i] - arr2[j]) > d);
        }
        cnt += ok ? 1 : 0;
    }
    return cnt;
}