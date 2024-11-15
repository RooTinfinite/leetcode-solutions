// TypeScript

function findLengthOfShortestSubarray(arr: number[]): number {
    const n: number = arr.length;
    if (n === 1) return 0;
    
    // Find the longest non-decreasing prefix
    let left: number = 0;
    while (left + 1 < n && arr[left] <= arr[left + 1]) {
        left++;
    }
    
    if (left === n - 1) return 0;
    
    // Find the longest non-decreasing suffix
    let right: number = n - 1;
    while (right > 0 && arr[right - 1] <= arr[right]) {
        right--;
    }
    
    // Initial result: remove everything between left and right
    let result: number = Math.min(n - left - 1, right);
    
    // Try to merge prefix and suffix
    let i: number = 0, j: number = right;
    while (i <= left && j < n) {
        if (arr[i] <= arr[j]) {
            result = Math.min(result, j - i - 1);
            i++;
        } else {
            j++;
        }
    }
    
    return result;
}