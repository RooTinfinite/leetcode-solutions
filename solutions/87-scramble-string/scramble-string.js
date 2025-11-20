var isScramble = function (s1, s2) {
    const n = s1.length;
    let dp = new Array(n + 1)
        .fill(0)
        .map(() => new Array(n).fill(0).map(() => new Array(n).fill(false)));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            dp[1][i][j] = s1.charAt(i) == s2.charAt(j);
        }
    }
    for (let length = 2; length <= n; length++) {
        for (let i = 0; i < n + 1 - length; i++) {
            for (let j = 0; j < n + 1 - length; j++) {
                for (let newLength = 1; newLength < length; newLength++) {
                    const dp1 = dp[newLength][i];
                    const dp2 = dp[length - newLength][i + newLength];
                    dp[length][i][j] |= dp1[j] && dp2[j + newLength];
                    dp[length][i][j] |= dp1[j + length - newLength] && dp2[j];
                }
            }
        }
    }
    return dp[n][0][0];
};