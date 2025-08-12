var numberOfWays = function (n, x) {
    const mod = 1e9 + 7;
    const dp = Array(n + 1).fill(0);
    dp[0] = 1;
    for (let i = 1; i <= n; i++) {
        let val = Math.pow(i, x);
        if (val > n) {
            break;
        }
        for (let j = n; j >= val; j--) {
            dp[j] = (dp[j] + dp[j - val]) % mod;
        }
    }
    return dp[n];
};