class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        if (n >= 1000LL) count += n - 999LL;
        if (n >= 1000000LL) count += n - 999999LL;
        if (n >= 1000000000LL) count += n - 999999999LL;
        if (n >= 1000000000000LL) count += n - 999999999999LL;
        if (n >= 1000000000000000LL) count += n - 999999999999999LL;
        return count;
    }
};