use std::collections::HashMap;

impl Solution {
    pub fn max_equal_rows_after_flips(mat: Vec<Vec<i32>>) -> i32 {
        let mut pat_freq = HashMap::new();
        
        for row in mat {
            let pattern = if row[0] == 0 {
                row.iter().map(|&x| x.to_string()).collect::<String>()
            } else {
                row.iter().map(|&x| (x ^ 1).to_string()).collect::<String>()
            };
            
            *pat_freq.entry(pattern).or_insert(0) += 1;
        }
        
        *pat_freq.values().max().unwrap()
    }
}