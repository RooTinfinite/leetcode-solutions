impl Solution {
    fn bin_search(nums: &Vec<i32>, mut l: i32, mut r: i32, target: i32) -> i64 {
        while l <= r {
            let m = l + (r - l) / 2;
            if nums[m as usize] >= target {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        r as i64
    }
    
    pub fn count_fair_pairs(mut nums: Vec<i32>, lower: i32, upper: i32) -> i64 {
        nums.sort();
        let mut res = 0i64;
        for i in 0..nums.len() {
            let low = lower - nums[i];
            let up = upper - nums[i];
            res += Self::bin_search(&nums, (i + 1) as i32, (nums.len() - 1) as i32, up + 1) -
                   Self::bin_search(&nums, (i + 1) as i32, (nums.len() - 1) as i32, low);
        }
        res
    }
}