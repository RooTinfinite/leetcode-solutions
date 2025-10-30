int minNumberOperations(int* target, int targetSize) {
    int ans = target[0];
    for (int i = 1; i < targetSize; ++i) {
        ans += fmax(target[i] - target[i - 1], 0);
    }
    return ans;
}