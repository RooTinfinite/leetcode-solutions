public class Solution {
    public int FindLengthOfShortestSubarray(int[] arr) {
        int n = arr.Length;
        if (n == 1) return 0;
        
        // Find the longest non-decreasing prefix
        int left = 0;
        while (left + 1 < n && arr[left] <= arr[left + 1]) {
            left++;
        }
        
        if (left == n - 1) return 0;
        
        // Find the longest non-decreasing suffix
        int right = n - 1;
        while (right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }
        
        // Initial result: remove everything between left and right
        int result = Math.Min(n - left - 1, right);
        
        // Try to merge prefix and suffix
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                result = Math.Min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        
        return result;
    }
}