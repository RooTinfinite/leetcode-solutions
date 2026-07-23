int uniqueXorTriplets(int* nums, int numsSize) {
    int n = numsSize;
    if (n <= 2) {
        return n;
    }
    int ans = 1;
    while (ans <= n) {
        ans <<= 1;
    }
    return ans;
}