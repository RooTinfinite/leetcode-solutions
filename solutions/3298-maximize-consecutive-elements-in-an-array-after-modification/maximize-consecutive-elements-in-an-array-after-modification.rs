use std::collections::HashMap;

impl Solution {
    pub fn max_selected_elements(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        let mut dp = HashMap::<i32, i32>::new();
        let mut ans = 0;
        for x in nums {
            let increased = dp.get(&(x + 1)).copied().unwrap_or(0)
                .max(dp.get(&x).copied().unwrap_or(0) + 1);
            dp.insert(x + 1, increased);
            let unchanged = dp.get(&x).copied().unwrap_or(0)
                .max(dp.get(&(x - 1)).copied().unwrap_or(0) + 1);
            dp.insert(x, unchanged);
            ans = ans.max(increased).max(unchanged);
        }
        ans
    }
}