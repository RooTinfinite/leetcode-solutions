impl Solution {
    pub fn max_sum_trionic(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut res = i64::MIN;
        let mut i = 1;
        while i < n - 2 {
            let (mut a, mut b) = (i, i);
            let mut net = nums[a] as i64;
            while b + 1 < n && nums[b + 1] < nums[b] {
                b += 1;
                net += nums[b] as i64;
            }
            if b == a { i += 1; continue; }
            let c = b;
            let (mut left, mut right) = (0i64, 0i64);
            let (mut lx, mut rx) = (i64::MIN, i64::MIN);
            while a >= 1 && nums[a - 1] < nums[a] {
                a -= 1;
                left += nums[a] as i64;
                lx = lx.max(left);
            }
            if a == i { i += 1; continue; }
            while b + 1 < n && nums[b + 1] > nums[b] {
                b += 1;
                right += nums[b] as i64;
                rx = rx.max(right);
            }
            if b == c { i += 1; continue; }
            res = res.max(lx + rx + net);
            i = b;
        }
        res
    }
}