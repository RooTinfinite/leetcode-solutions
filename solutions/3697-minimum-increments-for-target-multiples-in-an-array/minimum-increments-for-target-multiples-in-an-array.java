class Solution {
    public int minimumIncrements(int[] nums, int[] target) {
        int m = target.length;
        int fullMask = (1 << m) - 1;
        long[] lcmArr = new long[1 << m];
        for (int mask = 1; mask < (1 << m); mask++) {
            long L = 1;
            for (int j = 0; j < m; j++) {
                if ((mask & (1 << j)) != 0) {
                    L = lcm(L, target[j]);
                }
            }
            lcmArr[mask] = L;
        }
        long INF = Long.MAX_VALUE / 2;
        long[] dp = new long[1 << m];
        for (int i = 0; i < (1 << m); i++) {
            dp[i] = INF;
        }
        dp[0] = 0;
        for (int x : nums) {
            long[] newdp = dp.clone();
            for (int mask = 1; mask < (1 << m); mask++) {
                long L = lcmArr[mask];
                long r = x % L;
                long cost = (r == 0 ? 0 : L - r);
                for (int old = 0; old < (1 << m); old++) {
                    int newMask = old | mask;
                    newdp[newMask] = Math.min(newdp[newMask], dp[old] + cost);
                }
            }
            dp = newdp;
        }
        return (int) dp[fullMask];
    }

    private long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }}