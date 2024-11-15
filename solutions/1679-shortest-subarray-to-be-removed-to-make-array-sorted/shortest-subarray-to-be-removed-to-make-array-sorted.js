// JavaScript

var findLengthOfShortestSubarray = function(arr) {
    const n = arr.length;
    if (n === 1) return 0;
    
    // Find the longest non-decreasing prefix
    let left = 0;
    while (left + 1 < n && arr[left] <= arr[left + 1]) {
        left++;
    }
    
    if (left === n - 1) return 0;
    
    // Find the longest non-decreasing suffix
    let right = n - 1;
    while (right > 0 && arr[right - 1] <= arr[right]) {
        right--;
    }
    
    // Initial result: remove everything between left and right
    let result = Math.min(n - left - 1, right);
    
    // Try to merge prefix and suffix
    let i = 0, j = right;
    while (i <= left && j < n) {
        if (arr[i] <= arr[j]) {
            result = Math.min(result, j - i - 1);
            i++;
        } else {
            j++;
        }
    }
    
    return result;
};