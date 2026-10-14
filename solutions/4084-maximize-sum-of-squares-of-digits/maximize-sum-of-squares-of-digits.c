char* maxSumOfSquares(int num, int sum) {
    if (sum > 9 * num) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }
    int r = sum % 9;
    char* ans = (char*)malloc(num + 1);
    int idx = 0;
    int nines = sum / 9;
    for (int i = 0; i < nines; i++) {
        ans[idx++] = '9';
    }
    if (r > 0) {
        ans[idx++] = '0' + r;
    }
    while (idx < num) {
        ans[idx++] = '0';
    }
    ans[idx] = '\0';
    return ans;
}