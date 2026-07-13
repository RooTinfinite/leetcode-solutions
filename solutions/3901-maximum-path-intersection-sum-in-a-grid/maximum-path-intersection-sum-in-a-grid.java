class Solution {
    public int maxScore(int[][] g) {
        int m = g.length;
        int n = g[0].length;

        int a = Integer.MIN_VALUE;
        int i = 0;

        while (i < m) {
            int c = g[i][0] + g[i][1];
            a = Math.max(a, c);
            int j = 2;

            while (j < n) {
                c = Math.max(c + g[i][j], g[i][j - 1] + g[i][j]);
                a = Math.max(a, c);
                j++;
            }

            i++;
        }

        int j = 0;
        while (j < n) {
            int c = g[0][j] + g[1][j];
            a = Math.max(a, c);
            int i2 = 2;

            while (i2 < m) {
                c = Math.max(c + g[i2][j], g[i2 - 1][j] + g[i2][j]);
                a = Math.max(a, c);
                i2++;
            }

            j++;
        }

        i = 1;
        while (i < m - 1) {
            j = 1;
            while (j < n - 1) {
                a = Math.max(a, g[i][j]);
                j++;
            }

            i++;
        }

        return a;
    }
}