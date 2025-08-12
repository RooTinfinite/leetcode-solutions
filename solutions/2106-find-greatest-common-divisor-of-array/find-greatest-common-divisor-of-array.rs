impl Solution {
    pub fn find_gcd(nums: Vec<i32>) -> i32 {
        let mut mn = nums[0];
        let mut mx = nums[0];
        for &x in &nums {
            if x < mn { mn = x; }
            if x > mx { mx = x; }
        }
        let mut a = mn;
        let mut b = mx;
        while b != 0 {
            let t = a % b;
            a = b;
            b = t;
        }
        a
    }
}