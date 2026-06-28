use std::collections::HashMap;

impl Solution {
    pub fn maximum_length(nums: Vec<i32>) -> i32 {
        let mut cnt: HashMap<i64, i32> = HashMap::new();

        for num in nums {
            *cnt.entry(num as i64).or_insert(0) += 1;
        }

        // ans is at least the number of occurrences of 1, rounded down to an odd number
        let one_cnt = *cnt.get(&1).unwrap_or(&0);
        let mut ans = if one_cnt % 2 == 1 {
            one_cnt
        } else {
            one_cnt - 1
        };

        cnt.remove(&1);

        for &num in cnt.keys() {
            let mut res = 0;
            let mut x = num;

            while matches!(cnt.get(&x), Some(&c) if c > 1) {
                res += 2;
                x *= x;
            }

            ans = ans.max(res + if cnt.contains_key(&x) { 1 } else { -1 });
        }

        ans
    }
}