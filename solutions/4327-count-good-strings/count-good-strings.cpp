class Solution {
public:
    static const long long MOD = 1e9 + 7;

    // Returns {F(n), F(n+1)} using fast doubling
    pair<long long, long long> fib(long long n) {
        if (n == 0) {
            return {0, 1};
        }

        auto [x, y] = fib(n / 2);   // x = F(k), y = F(k+1)

        long long a = x * ((2 * y % MOD - x + MOD) % MOD) % MOD;  // F(2k)
        long long b = (x * x % MOD + y * y % MOD) % MOD;          // F(2k+1)

        if (n % 2 == 0) {
            return {a, b};
        }

        return {b, (a + b) % MOD};
    }

    int countGoodStrings(long long n) {
        return 2LL * fib(n).first % MOD;
    }
};