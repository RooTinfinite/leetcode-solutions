class Solution {
    long[][][] dp;
    int n;

    private long memo(int i, int isStart, int take, int[][] a) {
        if (i >= n) {
            if (take == 1) return (long) -1e18 / 4;
            return 0;
        }

        if (dp[i][isStart][take] != -1) return dp[i][isStart][take];

        long res = memo(i + 1, isStart, take, a);
        if (take == 1 && isStart == 1 && i < n - 1) {
            res += (a[i + 1][0] - a[i][0]);
        }

        int idx = lowerBound(a, a[i][1]);

        if (idx < n) {
            res = Math.max(res, a[i][2] + (a[idx][0] - a[i][1]) + memo(idx, 1, 1, a));
        }

        res = Math.max(res, a[i][2] + memo(idx, 1, 0, a));

        dp[i][isStart][take] = res;
        return res;
    }

    private int lowerBound(int[][] a, int x) {
        int lo = 0, hi = a.length;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (a[mid][0] < x) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    public long maxEarnings(int[][] meetings) {
        n = meetings.length;
        int[][] a = meetings.clone();
        Arrays.sort(a, (x, y) -> x[0] - y[0]);

        dp = new long[n + 1][2][2];
        for (long[][] layer : dp)
            for (long[] row : layer)
                Arrays.fill(row, -1);

        return memo(0, 0, 0, a);
    }
}