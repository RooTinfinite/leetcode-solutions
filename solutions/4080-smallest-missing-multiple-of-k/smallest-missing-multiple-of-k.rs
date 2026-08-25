use std::collections::HashSet;

impl Solution {
    pub fn missing_multiple(nums: Vec<i32>, k: i32) -> i32 {
        let seen: HashSet<i32> = nums.into_iter().collect();
        let mut ans = k;
        while seen.contains(&ans) {
            ans += k;
        }
        ans
    }
}