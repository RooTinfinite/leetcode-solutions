int sumOfSquares(int* nums, int numsSize) {
    int n = numsSize;
    int ans = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans += nums[i - 1] * nums[i - 1];
            if (i * i != n) {
                ans += nums[n / i - 1] * nums[n / i - 1];
            }
        }
    }
    return ans;
}