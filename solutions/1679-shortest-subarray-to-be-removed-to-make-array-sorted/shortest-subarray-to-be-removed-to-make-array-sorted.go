func findLengthOfShortestSubarray(arr []int) int {
    n := len(arr)
    if n == 1 {
        return 0
    }
    
    // Find the longest non-decreasing prefix
    left := 0
    for left+1 < n && arr[left] <= arr[left+1] {
        left++
    }
    
    if left == n-1 {
        return 0
    }
    
    // Find the longest non-decreasing suffix
    right := n - 1
    for right > 0 && arr[right-1] <= arr[right] {
        right--
    }
    
    // Initial result: remove everything between left and right
    result := min(n-left-1, right)
    
    // Try to merge prefix and suffix
    i, j := 0, right
    for i <= left && j < n {
        if arr[i] <= arr[j] {
            result = min(result, j-i-1)
            i++
        } else {
            j++
        }
    }
    
    return result
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}