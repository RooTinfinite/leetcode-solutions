public class Solution {
    public long FindKthSmallest(int[] coins, int k) {
        Array.Sort(coins);
        List<int> newCoins = new List<int>();
        foreach (int x in coins) {
            bool flag = true;
            foreach (int y in newCoins) {
                if (x % y == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                newCoins.Add(x);
            }
        }
        coins = newCoins.ToArray();

        int n = coins.Length;
        int m = 1 << n;
        int[] bitCount = new int[m];
        long[] lcm = new long[m];
        long l = k;
        long r = (long)coins[0] * k + 1;

        for (int mask = 1; mask < m; mask++) {
            bitCount[mask] = bitCount[mask >> 1] + (mask & 1);
        }

        lcm[0] = 1;
        for (int mask = 1; mask < m; mask++) {
            int preMask = mask & (mask - 1);
            int i = GetTrailingZeroCount(mask);

            long tmp = lcm[preMask] / Gcd(lcm[preMask], coins[i]);
            if (tmp <= r / coins[i]) {
                lcm[mask] = tmp * coins[i];
            } else {
                lcm[mask] = r + 1;
            }
        }

        while (l < r) {
            long x = l + (r - l) / 2;
            if (Count(x, m, lcm, bitCount) >= k) {
                r = x;
            } else {
                l = x + 1;
            }
        }
        return l;
    }

    private int GetTrailingZeroCount(int mask) {
        int count = 0;
        while ((mask & 1) == 0) {
            count++;
            mask >>= 1;
        }
        return count;
    }

    private long Count(long x, int m, long[] lcm, int[] bitCount) {
        long res = 0;
        for (int mask = 1; mask < m; mask++) {
            if (lcm[mask] > x)
                continue;

            if ((bitCount[mask] & 1) == 1) {
                res += x / lcm[mask];
            } else {
                res -= x / lcm[mask];
            }
        }
        return res;
    }

    private long Gcd(long a, long b) {
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
}