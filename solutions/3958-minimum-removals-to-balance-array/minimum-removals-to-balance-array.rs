impl Solution {
    pub fn min_removal(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut nums = nums;
        nums.sort();
        
        let mut ans = n as i32;
        let mut right = 0;
        
        for left in 0..n {
            while right < n && (nums[right] as i64) <= (nums[left] as i64) * (k as i64) {
                right += 1;
            }
            ans = ans.min(n as i32 - (right - left) as i32);
        }
        
        ans
    }
}