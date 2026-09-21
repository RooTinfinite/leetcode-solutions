impl Solution {
    pub fn result_array(nums: Vec<i32>, k: i32) -> Vec<i64> {
        let n = nums.len();
        let k_usize = k as usize;
        let mut result = vec![0i64; k_usize];
        let mut dp = vec![0i64; k_usize];  // Initial state: no elements have been processed, so no non-empty subarray exists.

        for i in 0..n {
            let mut ndp = vec![0i64; k_usize];  // Current-layer state (rolling array).
            ndp[(nums[i] as usize) % k_usize] += 1;
            for r in 0..k_usize {
                ndp[((r as i64 * nums[i] as i64) % k as i64) as usize] += dp[r];
            }

            dp = ndp;  // Update the state.
            // Accumulate the answer.
            for r in 0..k_usize {
                result[r] += dp[r];
            }
        }

        result
    }
}