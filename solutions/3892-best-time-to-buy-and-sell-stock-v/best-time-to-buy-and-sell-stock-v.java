class Solution {
    long[][][] dp;
    int[] prices;
    long mn = (long)-1e14;

    public long f(int i, int k, int state) {
        if (i == prices.length) {
            return (state == 0) ? 0 : mn;
        }
        if (dp[i][k][state] != mn) return dp[i][k][state];

        long p = prices[i];
        long profit = mn;

        // 1) do nothing today
        profit = Math.max(profit, f(i + 1, k, state));

        // 2) take action
        if (state == 0) {
            profit = Math.max(profit, f(i + 1, k, 1) - p); // buy
            profit = Math.max(profit, f(i + 1, k, 2) + p); // sell
        } else if (k > 0) {
            if (state == 1) {
                profit = Math.max(profit, f(i + 1, k - 1, 0) + p); // sell to end a buy-sell
            } else {
                profit = Math.max(profit, f(i + 1, k - 1, 0) - p); // buy to end a sell-buy
            }
        }

        return dp[i][k][state] = profit;
    }

    public long maximumProfit(int[] prices, int k) {
        this.prices = prices;
        int n = prices.length;
        dp = new long[n + 1][k + 1][3];
        for (long[][] twoD : dp)
            for (long[] oneD : twoD)
                Arrays.fill(oneD, mn);

        return f(0, k, 0);
    }
}