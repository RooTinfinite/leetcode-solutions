impl Solution {
    pub fn max_palindromes(s: String, k: i32) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let k = k as usize;
        let mut is_palindrome = vec![vec![false; n]; n];

        for len in 1..=n {
            for left in 0..=n - len {
                let right = left + len - 1;
                is_palindrome[left][right] = s[left] == s[right]
                    && (len <= 2 || is_palindrome[left + 1][right - 1]);
            }
        }

        let mut dp = vec![0; n + 1];
        for i in 1..=n {
            dp[i] = dp[i - 1];
            if i >= k {
                for j in 0..=i - k {
                    if is_palindrome[j][i - 1] {
                        dp[i] = dp[i].max(dp[j] + 1);
                    }
                }
            }
        }

        dp[n]
    }
}