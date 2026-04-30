function maxPathScore(grid: number[][], k: number): number {
    const m = grid.length,
        n = grid[0].length;

    const INF = -Infinity;
    const dp: number[][][] = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => Array(k + 1).fill(INF)),
    );

    dp[0][0][0] = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (let c = 0; c <= k; c++) {
                if (dp[i][j][c] === INF) continue;

                if (i + 1 < m) {
                    const val = grid[i + 1][j];
                    const cost = val === 0 ? 0 : 1;
                    if (c + cost <= k) {
                        dp[i + 1][j][c + cost] = Math.max(
                            dp[i + 1][j][c + cost],
                            dp[i][j][c] + val,
                        );
                    }
                }

                if (j + 1 < n) {
                    const val = grid[i][j + 1];
                    const cost = val === 0 ? 0 : 1;
                    if (c + cost <= k) {
                        dp[i][j + 1][c + cost] = Math.max(
                            dp[i][j + 1][c + cost],
                            dp[i][j][c] + val,
                        );
                    }
                }
            }
        }
    }

    const ans = Math.max(...dp[m - 1][n - 1]);
    return ans < 0 ? -1 : ans;
}