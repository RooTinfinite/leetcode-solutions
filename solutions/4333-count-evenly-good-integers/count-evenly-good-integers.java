class Solution {
    // time = O(logr), space = O(logr)
    public long countEvenlyGoodIntegers(long l, long r) {
        char[] lowS = String.valueOf(l).toCharArray();
        char[] highS = String.valueOf(r).toCharArray();
        int n = highS.length;
        long[][] memo = new long[n][2];
        for (long[] row : memo) Arrays.fill(row, -1);
        return dfs(0, 0, true, true, lowS, highS, memo);
    }

    private long dfs(int i, int parity, boolean limitLow, boolean limitHigh, char[] lowS, char[] highS, long[][] memo) {
        if (i == highS.length) return parity == 0 ? 1 : 0;
        if (!limitLow && !limitHigh && memo[i][parity] >= 0) return memo[i][parity];

        int diff = highS.length - lowS.length;
        int lo = limitLow && i >= diff ? lowS[i - diff] - '0' : 0;
        int hi = limitHigh ? highS[i] - '0' : 9;

        long res = 0;
        int d = lo;

        if (limitLow && i < diff) {
            res = dfs(i + 1, 0, true, false, lowS, highS, memo);
            d = 1;
        }

        for (; d <= hi; d++) {
            res += dfs(i + 1,
                    parity ^ (d % 2 == 0 ? 1 : 0),
                    limitLow && d == lo,
                    limitHigh && d == hi,
                    lowS, highS, memo);
        }

        if (!limitLow && !limitHigh) memo[i][parity] = res;
        return res;
    }
}