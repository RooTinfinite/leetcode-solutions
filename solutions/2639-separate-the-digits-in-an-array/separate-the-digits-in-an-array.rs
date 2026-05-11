impl Solution {
    pub fn separate_digits(nums: Vec<i32>) -> Vec<i32> {
        let mut res = Vec::new();
        for i in (0..nums.len()).rev() {
            let mut x = nums[i];
            while x > 0 {
                res.push(x % 10);
                x /= 10;
            }
        }
        res.reverse();
        res
    }
}