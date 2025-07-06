
use std::collections::HashMap;
impl Solution {
    pub fn num_identical_pairs(a: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut cnt = HashMap::new();
        
        for x in a.iter() {
            ans += cnt.get(x).unwrap_or(&0);
            *cnt.entry(*x).or_insert(0) += 1;
        }
        
        ans
    }
}