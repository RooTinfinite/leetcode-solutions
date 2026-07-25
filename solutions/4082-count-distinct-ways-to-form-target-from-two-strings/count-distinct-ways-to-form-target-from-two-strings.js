var interleaveCharacters = function (a, b, target) {
    const MOD = 1000000007;
    const n = a.length, n2 = b.length, m = target.length;
    const newTable = () =>
        Array.from({ length: n + 1 }, () =>
            Array.from({ length: n2 + 1 }, () => [[0, 0], [0, 0]]));
    let dp = newTable();
    dp[0][0][0][0] = 1;

    for (let i = 1; i <= m; i++) {
        const dpnxt = newTable();
        const x = target[i - 1];

        for (let prevb = 0; prevb <= n2; prevb++) {
            for (let t = 0; t < 2; t++) {
                const pref0 = new Array(n + 1).fill(0);
                const pref1 = new Array(n + 1).fill(0);
                pref0[0] = dp[0][prevb][0][t];
                pref1[0] = dp[0][prevb][1][t];
                for (let preva = 1; preva <= n; preva++) {
                    pref0[preva] = (pref0[preva - 1] + dp[preva][prevb][0][t]) % MOD;
                    pref1[preva] = (pref1[preva - 1] + dp[preva][prevb][1][t]) % MOD;
                }
                for (let preva = 1; preva <= n; preva++) {
                    if (a[preva - 1] !== x) continue;
                    dpnxt[preva][prevb][1][t] =
                        (dpnxt[preva][prevb][1][t] + pref0[preva - 1] + pref1[preva - 1]) % MOD;
                }
            }
        }

        for (let preva = 0; preva <= n; preva++) {
            for (let k = 0; k < 2; k++) {
                const pref0 = new Array(n2 + 1).fill(0);
                const pref1 = new Array(n2 + 1).fill(0);
                pref0[0] = dp[preva][0][k][0];
                pref1[0] = dp[preva][0][k][1];
                for (let prevb = 1; prevb <= n2; prevb++) {
                    pref0[prevb] = (pref0[prevb - 1] + dp[preva][prevb][k][0]) % MOD;
                    pref1[prevb] = (pref1[prevb - 1] + dp[preva][prevb][k][1]) % MOD;
                }
                for (let prevb = 1; prevb <= n2; prevb++) {
                    if (b[prevb - 1] !== x) continue;
                    dpnxt[preva][prevb][k][1] =
                        (dpnxt[preva][prevb][k][1] + pref0[prevb - 1] + pref1[prevb - 1]) % MOD;
                }
            }
        }

        dp = dpnxt;
    }

    let ans = 0;
    for (let preva = 0; preva <= n; preva++)
        for (let prevb = 0; prevb <= n2; prevb++)
            ans = (ans + dp[preva][prevb][1][1]) % MOD;
    return ans;
};