impl Solution {
    pub fn result_array(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut arr = vec![0; n];
        arr[0] = nums[0];
        arr[n - 1] = nums[1];
        let mut idx = 0;
        let mut rev_idx = n - 1;
        for i in 2..n {
            if arr[idx] > arr[rev_idx] {
                idx += 1;
                arr[idx] = nums[i];
            } else {
                rev_idx -= 1;
                arr[rev_idx] = nums[i];
            }
        }
        arr[rev_idx..].reverse();
        arr
    }
}