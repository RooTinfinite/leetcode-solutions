impl Solution {
    fn can_divide(nums: &Vec<i32>, max_balls: i32, max_operations: i32) -> bool {
        let mut ops = 0;
        for &n in nums {
            ops += (n + max_balls - 1) / max_balls - 1;
            if ops > max_operations {
                return false;
            }
        }
        true
    }
    
    pub fn minimum_size(nums: Vec<i32>, max_operations: i32) -> i32 {
        let mut left = 1;
        let mut right = *nums.iter().max().unwrap();
        let mut res = right;
        
        while left < right {
            let mid = left + (right - left) / 2;
            if Self::can_divide(&nums, mid, max_operations) {
                right = mid;
                res = right;
            } else {
                left = mid + 1;
            }
        }
        res
    }
}