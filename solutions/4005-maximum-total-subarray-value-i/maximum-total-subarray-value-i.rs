impl Solution {
    pub fn max_total_value(nums: Vec<i32>, k: i32) -> i64 {
        let m1 = *nums.iter().min().unwrap() as i64;
        let m2 = *nums.iter().max().unwrap() as i64;
        (m2 - m1) * k as i64
    }
}