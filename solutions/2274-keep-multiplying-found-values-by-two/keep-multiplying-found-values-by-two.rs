use std::collections::HashSet;

impl Solution {
    pub fn find_final_value(nums: Vec<i32>, original: i32) -> i32 {
        let set: HashSet<_> = nums.into_iter().collect();
        let mut original = original;
        while set.contains(&original) {
            original *= 2;
        }
        original
    }
}