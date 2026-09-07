const MOD = 1e9 + 7;

const distinctSubseqII = s => {
    let dp = new Int32Array(26), tot = 0;

    for (let i = 0; i < s.length; i++) {
        const c = s.charCodeAt(i) - 97;
        const add = (tot - dp[c] + MOD) % MOD;

        dp[c] = 1 + tot;
        tot = (dp[c] + add) % MOD;
    }

    return tot;
};