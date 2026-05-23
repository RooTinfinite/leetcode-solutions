impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut breaks = 0;

        for i in 0..n {
            if nums[i] > nums[(i + 1) % n] {
                breaks += 1;
            }
        }

        breaks <= 1
    }
}