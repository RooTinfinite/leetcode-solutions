class Solution {
    long inf = (long) 1e18;

    long div(long x, int k) {
        if (x >= 0) return x / k;
        return -((-x) / k);
    }

    long op(long x, int k, long flag) {
        if (flag != 0) return x * k;
        return div(x, k);
    }

    long f(int[] v, int k, long flag) {
        int n = v.length;
        long[] dp1 = new long[n];
        long[] dp2 = new long[n];
        long[] dp3 = new long[n];

        dp1[0] = v[0];
        dp2[0] = op(v[0] * 1L, k, flag);
        dp3[0] = -inf;

        for (int i = 1; i < n; i++) {
            long val = op(v[i] * 1L, k, flag);
            dp1[i] = Math.max(1L * v[i], dp1[i - 1] + v[i]);
            dp2[i] = Math.max(val, Math.max(dp1[i - 1] + val, dp2[i - 1] + val));
            dp3[i] = Math.max(dp2[i - 1] + v[i], Math.max(dp3[i - 1] + v[i], dp2[i]));
        }

        long ans = -inf;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, Math.max(dp1[i], Math.max(dp2[i], dp3[i])));
        }
        return ans;
    }

    public long maxSubarraySum(int[] v, int k) {
        long ans = Math.max(f(v, k, 0), f(v, k, 1));
        return ans;
    }
}