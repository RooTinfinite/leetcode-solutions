impl Solution {
    pub fn first_stable_index(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut min_value = vec![0; n];
        min_value[n - 1] = nums[n - 1];
        for i in (0..n - 1).rev() {
            min_value[i] = min_value[i + 1].min(nums[i]);
        }

        let mut max_value = 0;
        for i in 0..n {
            max_value = max_value.max(nums[i]);
            if max_value - min_value[i] <= k {
                return i as i32;
            }
        }
        -1
    }
}