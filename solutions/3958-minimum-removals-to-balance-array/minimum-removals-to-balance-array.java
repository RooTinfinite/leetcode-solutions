import java.util.Arrays;

class Solution {
    public int minRemoval(int[] nums, int k) {
        Arrays.sort(nums); // Sort array to maintain order
        int n = nums.length;
        int maxSize = 0;
        int left = 0;

        // Use sliding window to find longest valid subarray
        for (int right = 0; right < n; right++) {
            // While condition is violated, shrink window from left
            while (nums[right] > (long) k * nums[left]) left++;
            maxSize = Math.max(maxSize, right - left + 1);
        }
        // Return number of elements to remove
        return n - maxSize;
    }
}