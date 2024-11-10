impl Solution {
    pub fn minimum_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        if k == 0 {
            return 1;
        }
        let mut shortest = nums.len() + 1;
        let mut count = [0; 32];
        let mut val = 0;
        let mut start = 0;
        
        for i in 0..nums.len() {
            let mut num = nums[i];
            val |= num;
            let mut ibit = 0;
            while num != 0 {
                count[ibit] += num & 1;
                num >>= 1;
                ibit += 1;
            }
            while val >= k && start < nums.len() {
                shortest = shortest.min(i - start + 1);
                num = nums[start];
                start += 1;
                ibit = 0;
                while num != 0 {
                    count[ibit] -= num & 1;
                    if count[ibit] == 0 {
                        val &= !(1 << ibit);
                    }
                    num >>= 1;
                    ibit += 1;
                }
            }
        }
        if shortest == nums.len() + 1 { -1 } else { shortest as i32 }
    }
}