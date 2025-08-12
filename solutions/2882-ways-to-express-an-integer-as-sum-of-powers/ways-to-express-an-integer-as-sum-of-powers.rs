impl Solution {
    pub fn number_of_ways(n: i32, x: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let n = n as usize;
        let mut dp = vec![0i64; n + 1];
        dp[0] = 1;
        for i in 1..= n {
            let val = (i as i64).pow(x as u32) as usize;
            if val > n {
                break;
            }
            for j in (val..= n).rev() {
                dp[j] = (dp[j] + dp[j - val]) % MOD;
            }
        }
        dp[n] as i32
    }
}