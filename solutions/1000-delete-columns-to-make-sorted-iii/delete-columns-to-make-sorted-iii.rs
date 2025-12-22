impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let n = strs[0].len();
        let m = strs.len();
        let bytes: Vec<Vec<u8>> = strs.into_iter().map(|s| s.into_bytes()).collect();

        let mut dp = vec![1i32; n];

        for i in 1..n {
            for j in 0..i {
                let mut ok = true;
                for r in 0..m {
                    if bytes[r][j] > bytes[r][i] { ok = false; break; }
                }
                if ok {
                    dp[i] = dp[i].max(dp[j] + 1);
                }
            }
        }

        let mut mx = 0i32;
        for v in dp { mx = mx.max(v); }
        n as i32 - mx
    }
}