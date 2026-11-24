use std::cmp::max;

impl Solution {
    pub fn max_length(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        
        fn gcd(mut a: i64, mut b: i64) -> i64 {
            while b != 0 {
                let temp = b;
                b = a % b;
                a = temp;
            }
            a
        }
        
        for i in 0..nums.len() {
            let mut prod_val = nums[i] as i64;
            let mut gcd_val = nums[i] as i64;
            let mut lcm_val = nums[i] as i64;
            for j in i + 1..nums.len() {
                prod_val = prod_val * nums[j] as i64;
                gcd_val = gcd(gcd_val, nums[j] as i64);
                lcm_val = lcm_val * nums[j] as i64 / gcd(lcm_val, nums[j] as i64);
                if prod_val > gcd_val * lcm_val {
                    break;
                }
                if prod_val == gcd_val * lcm_val {
                    res = max(res, (j - i + 1) as i32);
                }
            }
        }
        
        res
    }
}