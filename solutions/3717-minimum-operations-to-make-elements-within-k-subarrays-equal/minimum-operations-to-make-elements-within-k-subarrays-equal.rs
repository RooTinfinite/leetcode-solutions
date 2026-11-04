impl Solution {
    fn get_costs(nums: &[i32], x: usize) -> Vec<i64> {
        let n = nums.len();
        let mut ops = vec![0_i64; n];
        let mut left = std::collections::BTreeSet::<(i32, usize)>::new();
        let mut right = std::collections::BTreeSet::<(i32, usize)>::new();
        let mut sum_l = 0_i64;
        let mut sum_r = 0_i64;

        for i in 0..n {
            let item = (nums[i], i);
            if left.is_empty() || item.0 <= left.last().unwrap().0 {
                left.insert(item);
                sum_l += i64::from(item.0);
            } else {
                right.insert(item);
                sum_r += i64::from(item.0);
            }
            if i >= x {
                let old = (nums[i - x], i - x);
                if left.remove(&old) {
                    sum_l -= i64::from(old.0);
                } else {
                    right.remove(&old);
                    sum_r -= i64::from(old.0);
                }
            }
            if left.len() > right.len() + 1 {
                let item = left.pop_last().unwrap();
                right.insert(item);
                sum_l -= i64::from(item.0);
                sum_r += i64::from(item.0);
            } else if left.len() < right.len() {
                let item = right.pop_first().unwrap();
                left.insert(item);
                sum_l += i64::from(item.0);
                sum_r -= i64::from(item.0);
            }
            if i >= x - 1 {
                let mid = i64::from(left.last().unwrap().0);
                ops[i] = mid * left.len() as i64 - sum_l + sum_r - mid * right.len() as i64;
            }
        }
        ops
    }

    pub fn min_operations(nums: Vec<i32>, x: i32, k: i32) -> i64 {
        let n = nums.len();
        let x = x as usize;
        let k = k as usize;
        let ops = Self::get_costs(&nums, x);
        let mut pre = vec![0_i64; n + 1];
        let mut cur = vec![i64::MAX; n + 1];

        for j in 1..=k {
            cur.fill(i64::MAX);
            for i in j * x..=n {
                cur[i] = cur[i - 1].min(pre[i - x] + ops[i - 1]);
            }
            std::mem::swap(&mut pre, &mut cur);
        }
        pre[n]
    }
}