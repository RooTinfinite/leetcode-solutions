impl Solution {
    pub fn is_good(nums: Vec<i32>) -> bool {
        let n = nums.len() as i32;
        let mut count = vec![0; n as usize];
        for &a in nums.iter() {
            if a < 1 || a >= n {
                return false;
            }
            if a < n - 1 && count[a as usize] > 0 {
                return false;
            }
            if a == n - 1 && count[a as usize] > 1 {
                return false;
            }
            count[a as usize] += 1;
        }
        true
    }
}