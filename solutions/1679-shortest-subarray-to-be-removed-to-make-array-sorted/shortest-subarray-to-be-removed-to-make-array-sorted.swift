class Solution {
    func findLengthOfShortestSubarray(_ arr: [Int]) -> Int {
        let n = arr.count
        if n == 1 { return 0 }
        
        // Find the longest non-decreasing prefix
        var left = 0
        while left + 1 < n && arr[left] <= arr[left + 1] {
            left += 1
        }
        
        if left == n - 1 { return 0 }
        
        // Find the longest non-decreasing suffix
        var right = n - 1
        while right > 0 && arr[right - 1] <= arr[right] {
            right -= 1
        }
        
        // Initial result: remove everything between left and right
        var result = min(n - left - 1, right)
        
        // Try to merge prefix and suffix
        var i = 0, j = right
        while i <= left && j < n {
            if arr[i] <= arr[j] {
                result = min(result, j - i - 1)
                i += 1
            } else {
                j += 1
            }
        }
        
        return result
    }
}