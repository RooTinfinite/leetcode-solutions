public class Solution {
    public int FindLengthOfShortestSubarray(int[] arr) {
        int n = arr.Length;
        
        // 1. Find the rightmost point where array becomes non-ascending
        int right = n - 1;
        while (right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }
        
        // 2. If array is already sorted in ascending order
        if (right == 0) {
            return 0;
        }
        
        // 3. Initial minimum length is from start to right pointer
        int minLength = right;
        
        // Check each element from left side
        for (int left = 0; left < n; left++) {
            // Break if left sequence becomes non-ascending
            if (left > 0 && arr[left - 1] > arr[left]) {
                break;
            }
            
            // Find the first element from right that's >= arr[left]
            while (right < n && arr[left] > arr[right]) {
                right++;
            }
            
            // Update minimum length of subarray to be removed
            int currentLength = right - left - 1;
            minLength = Math.Min(minLength, currentLength);
        }
        
        return minLength;
    }
}