class Solution {
    func findLengthOfShortestSubarray(_ arr: [Int]) -> Int {
        let n = arr.count
        
        // 1. Find the rightmost point where array becomes non-ascending
        var right = n - 1
        while right > 0 && arr[right - 1] <= arr[right] {
            right -= 1
        }
        
        // 2. If array is already sorted in ascending order
        if right == 0 {
            return 0
        }
        
        // 3. Initial minimum length is from start to right pointer
        var minLength = right
        
        // Check each element from left side
        for left in 0..<n {
            // Break if left sequence becomes non-ascending
            if left > 0 && arr[left - 1] > arr[left] {
                break
            }
            
            // Find the first element from right that's >= arr[left]
            while right < n && arr[left] > arr[right] {
                right += 1
            }
            
            // Update minimum length of subarray to be removed
            let currentLength = right - left - 1
            minLength = min(minLength, currentLength)
        }
        
        return minLength
    }
}