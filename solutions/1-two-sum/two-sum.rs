use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut ht = HashMap::new();
        
        for (i, &num) in nums.iter().enumerate() {
            if let Some(&j) = ht.get(&(target - num)) {
                return vec![j as i32, i as i32];
            }
            
            ht.insert(num, i);
        }
        
        vec![]
    }
}