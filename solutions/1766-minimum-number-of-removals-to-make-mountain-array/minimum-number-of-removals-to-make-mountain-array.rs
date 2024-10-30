impl Solution {
    // Helper function to calculate LIS lengths for each position
    fn lis_length(v: &Vec<i32>) -> Vec<i32> {
        let mut lis = vec![v[0]];
        let mut lis_len = vec![1; v.len()];
        
        for i in 1..v.len() {
            if v[i] > *lis.last().unwrap() {
                lis.push(v[i]);
            } else {
                let index = lis.partition_point(|&x| x < v[i]);
                lis[index] = v[i];
            }
            lis_len[i] = lis.len() as i32;
        }
        lis_len
    }
    
    pub fn minimum_mountain_removals(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        
        // Get LIS lengths from left to right
        let lis = Self::lis_length(&nums);
        
        // Get LIS lengths from right to left
        let mut reversed_nums = nums.clone();
        reversed_nums.reverse();
        let mut lds = Self::lis_length(&reversed_nums);
        lds.reverse();
        
        let mut removals = i32::MAX;
        
        // Check each potential peak position
        for i in 0..n {
            if lis[i] > 1 && lds[i] > 1 {
                removals = removals.min(n as i32 + 1 - lis[i] - lds[i]);
            }
        }
        
        removals
    }
}