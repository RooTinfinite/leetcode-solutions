var isInterleave = function (s1, s2, s3) {
    if (s3.length !== s1.length + s2.length) {
        return false;
    }
    let dp = new Array(s2.length + 1).fill(false);
    for (let i = 0; i <= s1.length; i++) {
        for (let j = 0; j <= s2.length; j++) {
            if (i === 0 && j === 0) {
                dp[j] = true;
            } else if (i === 0) {
                dp[j] = dp[j - 1] && s2[j - 1] === s3[i + j - 1];
            } else if (j === 0) {
                dp[j] = dp[j] && s1[i - 1] === s3[i + j - 1];
            } else {
                dp[j] =
                    (dp[j] && s1[i - 1] === s3[i + j - 1]) ||
                    (dp[j - 1] && s2[j - 1] === s3[i + j - 1]);
            }
        }
    }
    return dp[s2.length];
};