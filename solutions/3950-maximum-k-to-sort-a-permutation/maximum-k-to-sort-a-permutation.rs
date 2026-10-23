impl Solution {
    pub fn sort_permutation(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut res = i32::MAX;
        for i in 0..n {
            if nums[i] == i as i32 {
                continue;
            }
            res &= nums[i];
        }
        if res == i32::MAX { 0 } else { res }
    }
}