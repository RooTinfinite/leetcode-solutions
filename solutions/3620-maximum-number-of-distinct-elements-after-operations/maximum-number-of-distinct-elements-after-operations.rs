impl Solution {
    pub fn max_distinct_elements(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums;
        nums.sort();
        let mut cnt = 0;
        let mut prev = i32::MIN;
        
        for num in nums {
            let curr = (num - k).max(prev + 1).min(num + k);
            if curr > prev {
                cnt += 1;
                prev = curr;
            }
        }
        cnt
    }
}