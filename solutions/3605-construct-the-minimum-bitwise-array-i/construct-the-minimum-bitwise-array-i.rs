impl Solution {
    pub fn min_bitwise_array(nums: Vec<i32>) -> Vec<i32> {
        let mut result = vec![-1; nums.len()];
        
        for (i, &original) in nums.iter().enumerate() {
            for j in 1..original {
                if (j | (j + 1)) == original {
                    result[i] = j;
                    break;
                }
            }
        }
        
        result
    }
}