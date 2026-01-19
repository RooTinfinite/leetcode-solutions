class Solution {

    private int getRect(int[][] P, int x1, int y1, int x2, int y2) {
        return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
    }

    public int maxSideLength(int[][] mat, int threshold) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] P = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                P[i][j] =
                    P[i - 1][j] +
                    P[i][j - 1] -
                    P[i - 1][j - 1] +
                    mat[i - 1][j - 1];
            }
        }

        int r = Math.min(m, n);
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int c = ans + 1; c <= r; ++c) {
                    if (
                        i + c - 1 <= m &&
                        j + c - 1 <= n &&
                        getRect(P, i, j, i + c - 1, j + c - 1) <= threshold
                    ) {
                        ++ans;
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
}