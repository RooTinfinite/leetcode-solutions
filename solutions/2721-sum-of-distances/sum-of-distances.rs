use std::collections::HashMap;

impl Solution {
    pub fn distance(nums: Vec<i32>) -> Vec<i64> {
        let n = nums.len();
        let mut groups: HashMap<i32, Vec<usize>> = HashMap::new();
        for (i, &v) in nums.iter().enumerate() {
            groups.entry(v).or_default().push(i);
        }
        let mut res = vec![0i64; n];
        for group in groups.values() {
            let total: i64 = group.iter().map(|&x| x as i64).sum();
            let mut prefix_total: i64 = 0;
            let sz = group.len() as i64;
            for (i, &idx) in group.iter().enumerate() {
                res[idx] = total - prefix_total * 2 + idx as i64 * (2 * i as i64 - sz);
                prefix_total += idx as i64;
            }
        }
        res
    }
}