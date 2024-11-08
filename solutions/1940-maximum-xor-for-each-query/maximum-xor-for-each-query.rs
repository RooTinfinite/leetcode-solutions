impl Solution {
    pub fn get_maximum_xor(nums: Vec<i32>, maximum_bit: i32) -> Vec<i32> {
        let mask = (1 << maximum_bit) - 1;
        let n = nums.len();
        let mut res = vec![0; n];
        let mut curr = 0;
        
        for i in 0..n {
            curr ^= nums[i];
            res[n-i-1] = !curr & mask;
        }
        
        res
    }
}