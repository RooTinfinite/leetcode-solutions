use std::collections::HashSet;

impl Solution {
    pub fn longest_square_streak(nums: Vec<i32>) -> i32 {
        // Convert to HashSet and sort
        let mut unique_nums: Vec<i64> = nums.into_iter()
            .map(|x| x as i64)
            .collect::<HashSet<_>>()
            .into_iter()
            .collect();
        unique_nums.sort_unstable();
        
        // Create HashSet for O(1) lookup
        let num_set: HashSet<i64> = unique_nums.iter().cloned().collect();
        
        // Track maximum streak length
        let mut max_length = 0;
        
        // Check each number
        for &num in &unique_nums {
            let mut length = 0;
            let mut current = num;
            
            // Keep squaring while number exists in set
            while num_set.contains(&current) {
                length += 1;
                // Check if squaring would overflow
                if current > (1i64 << 31) {
                    break;
                }
                current *= current;
            }
            
            // Update max_length if streak length > 1
            if length > 1 {
                max_length = max_length.max(length);
            }
        }
        
        if max_length > 1 {
            max_length
        } else {
            -1
        }
    }
}