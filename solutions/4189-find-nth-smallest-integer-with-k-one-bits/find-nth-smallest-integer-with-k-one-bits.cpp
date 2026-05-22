class Solution {
public:
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n / 2) r = n - r;
        
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            long long temp = (long long)res * (n - i + 1);
            res = (long long)(temp / i);
        }
        return res;
    }
    long long nthSmallest(long long n, int k) {
        long long ans = 0;
        for (int i = 50; i >= 0; --i) {
            long long count = nCr(i, k);
            
            if (n > count) {
                n -= count;
                k--;
                ans |= (1LL << i);
            }
        }
        return ans;
    }
};