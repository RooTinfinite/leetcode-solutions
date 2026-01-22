impl Solution {
    pub fn minimum_pair_removal(nums: Vec<i32>) -> i32 {
        let mut count = 0;
        let mut nums = nums.clone();
        
        while nums.len() > 1 {
            let mut is_ascending = true;
            let mut min_sum = i32::MAX;
            let mut target_index = -1;
            
            for i in 0..nums.len() - 1 {
                let sum = nums[i] + nums[i + 1];
                if nums[i] > nums[i + 1] {
                    is_ascending = false;
                }
                if sum < min_sum {
                    min_sum = sum;
                    target_index = i as i32;
                }
            }
            
            if is_ascending {
                break;
            }
            
            count += 1;
            let ti = target_index as usize;
            nums[ti] = min_sum;
            nums.remove(ti + 1);
        }
        
        count
    }
}