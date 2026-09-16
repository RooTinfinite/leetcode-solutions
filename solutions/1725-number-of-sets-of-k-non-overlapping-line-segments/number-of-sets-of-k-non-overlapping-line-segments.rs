impl Solution {
    pub fn number_of_sets(n: i32, k: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let n = n as usize;
        let mut dp = vec![1i64; n];
        let mut prefix_sums = vec![0i64; n + 1];
        for j in 0..n {
            prefix_sums[j + 1] = (prefix_sums[j] + dp[j]) % MOD;
        }
        for _ in 0..k {
            dp[0] = 0;
            for j in 1..n {
                dp[j] = (dp[j - 1] + prefix_sums[j]) % MOD;
            }
            for j in 0..n {
                prefix_sums[j + 1] = (prefix_sums[j] + dp[j]) % MOD;
            }
        }
        dp[n - 1] as i32
    }
}