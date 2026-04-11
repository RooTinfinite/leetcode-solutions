use std::collections::HashMap;

impl Solution {
    pub fn minimum_distance(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut next = vec![-1_isize; n];
        let mut occur = HashMap::new();
        let mut ans = n + 1;

        for i in (0..n).rev() {
            if let Some(&val) = occur.get(&nums[i]) {
                next[i] = val as isize;
            }
            occur.insert(nums[i], i);
        }

        for i in 0..n {
            let second_pos = next[i];
            if second_pos != -1 {
                let third_pos = next[second_pos as usize];
                if third_pos != -1 {
                    ans = ans.min(third_pos as usize - i);
                }
            }
        }

        if ans == n + 1 {
            -1
        } else {
            (ans * 2) as i32
        }
    }
}