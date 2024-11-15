func findLengthOfShortestSubarray(arr []int) int {
    n := len(arr)
    
    // 1. Find the rightmost point where array becomes non-ascending
    right := n - 1
    for right > 0 && arr[right-1] <= arr[right] {
        right--
    }
    
    // 2. If array is already sorted in ascending order
    if right == 0 {
        return 0
    }
    
    // 3. Initial minimum length is from start to right pointer
    minLength := right
    
    // Check each element from left side
    for left := 0; left < n; left++ {
        // Break if left sequence becomes non-ascending
        if left > 0 && arr[left-1] > arr[left] {
            break
        }
        
        // Find the first element from right that's >= arr[left]
        for right < n && arr[left] > arr[right] {
            right++
        }
        
        // Update minimum length of subarray to be removed
        currentLength := right - left - 1
        minLength = min(minLength, currentLength)
    }
    
    return minLength
}