class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k)
            return 0;
        if (n <= k)
            return (long long)(m - k) * k;
        if (m <= k)
            return (long long)(n - k) * k;
        return (long long)(n - k) * k + (long long)(m - k) * k;
    }
};