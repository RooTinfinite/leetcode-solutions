use std::collections::HashMap;

impl Solution {
    pub fn first_unique_freq(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return -1;
        }
        
        let mut counter = HashMap::new();
        
        for &num in &nums {
            *counter.entry(num).or_insert(0) += 1;
        }
        
        let mut freq = HashMap::new();
        
        for &count in counter.values() {
            *freq.entry(count).or_insert(0) += 1;
        }
        
        for &num in &nums {
            if let Some(count) = counter.get(&num) {
                if let Some(freq_count) = freq.get(count) {
                    if *freq_count == 1 {
                        return num;
                    }
                }
            }
        }
        
        -1
    }
}