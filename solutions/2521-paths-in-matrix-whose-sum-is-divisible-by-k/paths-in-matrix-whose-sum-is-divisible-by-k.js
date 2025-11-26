const MOD = 1e9 + 7;

var numberOfPaths = function (grid, k) {
    const m = grid.length;
    const n = grid[0].length;

    const dp = [];

    for (let i = 0; i <= m; i++) {
        dp[i] = [];
        for (let j = 0; j <= n; j++) {
            dp[i][j] = new Array(k).fill(0);

            if (i === 1 && j === 1) {
                dp[i][j][grid[0][0] % k] = 1;
                continue;
            }

            if (i >= 1 && j >= 1) {
                const value = grid[i - 1][j - 1] % k;

                for (let r = 0; r < k; r++) {
                    const prevMod = (r - value + k) % k;

                    dp[i][j][r] = dp[i - 1][j][prevMod] + dp[i][j - 1][prevMod];
                    dp[i][j][r] %= MOD;
                }
            }
        }
    }

    return dp[m][n][0];
};