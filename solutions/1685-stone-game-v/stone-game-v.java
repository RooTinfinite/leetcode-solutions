class Solution {

    int[][] f;
    int[][] maxl;
    int[][] maxr;

    public int stoneGameV(int[] stoneValue) {
        int n = stoneValue.length;
        f = new int[n][n];
        maxl = new int[n][n];
        maxr = new int[n][n];
        for (int left = n - 1; left >= 0; --left) {
            maxl[left][left] = maxr[left][left] = stoneValue[left];
            int sum = stoneValue[left],
                suml = 0;
            for (int right = left + 1, i = left - 1; right < n; ++right) {
                sum += stoneValue[right];
                while (i + 1 < right && (suml + stoneValue[i + 1]) * 2 <= sum) {
                    suml += stoneValue[i + 1];
                    ++i;
                }
                if (left <= i) {
                    f[left][right] = Math.max(f[left][right], maxl[left][i]);
                }
                if (i + 1 < right) {
                    f[left][right] = Math.max(
                        f[left][right],
                        maxr[i + 2][right]
                    );
                }
                if (suml * 2 == sum) {
                    f[left][right] = Math.max(
                        f[left][right],
                        maxr[i + 1][right]
                    );
                }
                maxl[left][right] = Math.max(
                    maxl[left][right - 1],
                    sum + f[left][right]
                );
                maxr[left][right] = Math.max(
                    maxr[left + 1][right],
                    sum + f[left][right]
                );
            }
        }
        return f[0][n - 1];
    }
}