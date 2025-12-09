use std::collections::HashMap;

impl Solution {
    pub fn special_triplets(nums: Vec<i32>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let mut pos: HashMap<i32, Vec<usize>> = HashMap::new();
        
        for (i, &v) in nums.iter().enumerate() {
            pos.entry(v).or_insert_with(Vec::new).push(i);
        }
        
        let upper_bound = |arr: &[usize], i: usize| -> (usize, usize) {
            let (mut l, mut r) = (0, arr.len() - 1);
            while l < r {
                let mid = l + ((r - l + 1) >> 1);
                if i >= arr[mid] {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            (l + 1, arr.len() - 1 - l)
        };
        
        let mut ans: i64 = 0;
        for i in 1..nums.len() - 1 {
            let target = nums[i] * 2;
            if let Some(target_pos) = pos.get(&target) {
                if target_pos.len() > 1 && target_pos[0] < i {
                    let (mut l, r) = upper_bound(target_pos, i);
                    if nums[i] == 0 {
                        l -= 1;
                    }
                    ans = (ans + l as i64 * r as i64) % MOD;
                }
            }
        }
        
        ans as i32
    }
}