use std::collections::HashMap;

impl Solution {
    pub fn max_equal_rows_after_flips(matrix: Vec<Vec<i32>>) -> i32 {
        let mut count: HashMap<String, i32> = HashMap::new();
        
        for row in matrix.iter() {
            let key: String = row.iter()
                .map(|&n| if row[0] == 1 { 1 - n } else { n })
                .map(|n| n.to_string())
                .collect();
                
            *count.entry(key).or_insert(0) += 1;
        }
        
        *count.values().max().unwrap()
    }
}