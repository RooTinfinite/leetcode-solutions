var maximumProfit = function (prices, k) {
    const n = prices.length;
    const memo = Array(n)
        .fill()
        .map(() =>
            Array(k + 1)
                .fill()
                .map(() => Array(3).fill(-1)),
        );

    const dfs = (i, j, state) => {
        if (j == 0) {
            return 0;
        }
        if (i == 0) {
            return state == 0 ? 0 : state == 1 ? -prices[0] : prices[0];
        }
        if (memo[i][j][state] !== -1) {
            return memo[i][j][state];
        }
        const p = prices[i];
        let res;
        if (state === 0) {
            res = Math.max(
                dfs(i - 1, j, 0),
                Math.max(dfs(i - 1, j, 1) + p, dfs(i - 1, j, 2) - p),
            );
        } else if (state === 1) {
            res = Math.max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - p);
        } else {
            res = Math.max(dfs(i - 1, j, 2), dfs(i - 1, j - 1, 0) + p);
        }
        memo[i][j][state] = res;
        return res;
    };

    return dfs(n - 1, k, 0);
};