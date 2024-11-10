impl Solution {
    pub fn minimum_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        let mut ans = i32::MAX;
        let mut s = 0;
        let mut left = 0;
        let mut cnt = vec![0; 32];
        
        for right in 0..nums.len() {
            let mut num = nums[right];
            s |= num;
            let mut i = 0;
            while num > 0 {
                cnt[i] += num % 2;
                num /= 2;
                i += 1;
            }
            
            while s >= k && left <= right {
                ans = ans.min((right - left + 1) as i32);
                num = nums[left];
                i = 0;
                while num > 0 {
                    if num % 2 == 1 {
                        cnt[i] -= 1;
                        if cnt[i] == 0 {
                            s ^= 1 << i;
                        }
                    }
                    num /= 2;
                    i += 1;
                }
                left += 1;
            }
        }
        if ans == i32::MAX { -1 } else { ans }
    }
}