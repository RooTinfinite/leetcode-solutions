class Solution {
    long MOD = 1000000007;

    public int sumOfNumbers(int l, int r, int k) {

        long n = r - l + 1;
        long digitSum = (long)(l + r) * n / 2 % MOD;

        long powN = modPow(n, k - 1);
        long pow10 = modPow(10, k);

        long geom = (pow10 - 1 + MOD) % MOD * modInverse(9) % MOD;

        long ans = digitSum;
        ans = ans * powN % MOD;
        ans = ans * geom % MOD;

        return (int) ans;
    }

    long modPow(long a, long b) {
        long res = 1;
        a %= MOD;

        while (b > 0) {
            if ((b & 1) == 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    long modInverse(long x) {
        return modPow(x, MOD - 2);
    }
}