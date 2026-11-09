use std::cmp::min;

impl Solution {
    pub fn min_merged_integer(nums: Vec<i32>) -> i32 {
        let n = nums.len();

        let mut mn = i32::MAX;
        for i in (0..n).step_by(2) {
            let a = nums[i];
            let b = nums[i + 1];
            println!("{a};{b}");
            let x: i32 = format!("{a}{b}").parse().expect("merged number");
            mn = min(mn, x);
        }

        mn
    }
}