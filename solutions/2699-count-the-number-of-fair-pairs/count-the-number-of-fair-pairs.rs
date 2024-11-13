impl Solution {
    pub fn count_fair_pairs(nums: Vec<i32>, lower: i32, upper: i32) -> i64 {
        let mut sorted_nums = nums.clone();
        sorted_nums.sort();
        Self::count_pairs(&sorted_nums, upper) - Self::count_pairs(&sorted_nums, lower - 1)
    }
    
    fn count_pairs(nums: &Vec<i32>, target: i32) -> i64 {
        let mut count: i64 = 0;
        let mut left = 0;
        let mut right = nums.len() - 1;
        
        while left < right {
            if nums[left] + nums[right] > target {
                right -= 1;
            } else {
                count += (right - left) as i64;
                left += 1;
            }
        }
        count
    }
}