impl Solution {
    pub fn find_length_of_shortest_subarray(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        
        // 1. Find the rightmost point where array becomes non-ascending
        let mut right = n - 1;
        while right > 0 && arr[right - 1] <= arr[right] {
            right -= 1;
        }
        
        // 2. If array is already sorted in ascending order
        if right == 0 {
            return 0;
        }
        
        // 3. Initial minimum length is from start to right pointer
        let mut min_length = right;
        
        // Check each element from left side
        for left in 0..n {
            // Break if left sequence becomes non-ascending
            if left > 0 && arr[left - 1] > arr[left] {
                break;
            }
            
            // Find the first element from right that's >= arr[left]
            while right < n && arr[left] > arr[right] {
                right += 1;
            }
            
            // Update minimum length of subarray to be removed
            let current_length = right - left - 1;
            min_length = min_length.min(current_length);
        }
        
        min_length as i32
    }
}