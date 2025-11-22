impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        nums
        .iter()
        .map(|&x| {
            let r = x % 3;
            r.min(3 - r)
        })
        .sum()
    }
}