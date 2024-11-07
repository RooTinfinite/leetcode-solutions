const BIT_MAX: i32 = 24;

impl Solution {
    pub fn largest_combination(candidates: Vec<i32>) -> i32 {
        let mut max_set = 1;
        let mut mask = 1;
        
        for _shift in 0..BIT_MAX {
            let mut count = 0;
            for &num in candidates.iter() {
                if num & mask != 0 {
                    count += 1;
                }
            }
            if max_set < count {
                max_set = count;
            }
            mask <<= 1;
        }
        max_set
    }
}