class Solution {
    public int countMatchingSubarrays(int[] nums, int[] pattern) {
        int n = nums.length;  // Size of the input array nums
        int m = pattern.length;  // Size of the pattern array
        int count = 0;  // Initialize the count of matching subarrays

        // Iterate through all possible starting indices of the subarray
        for (int i = 0; i < n; i++) {
            // Iterate through all possible ending indices of the subarray
            for (int j = i; j < n; j++) {
                // Check if the size of the current subarray is equal to m + 1
                if (j - i + 1 == m + 1) {
                    int l = i;  // Initialize a variable for tracking the current index in the subarray
                    int flag = 0;  // Initialize a flag to track if the subarray matches the pattern

                    // Iterate through the pattern and compare it with the subarray elements
                    for (int k = 0; k < m; k++, l++) {
                        // Check for the matching conditions based on the pattern values
                        if (pattern[k] == 1 && nums[l + 1] > nums[l]) {
                            // If pattern[k] is 1, check for strictly increasing condition
                            continue;
                        } else if (pattern[k] == 0 && nums[l + 1] == nums[l]) {
                            // If pattern[k] is 0, check for equal condition
                            continue;
                        } else if (pattern[k] == -1 && nums[l + 1] < nums[l]) {
                            // If pattern[k] is -1, check for strictly decreasing condition
                            continue;
                        } else {
                            // If any condition fails, set the flag and break out of the loop
                            flag = 1;
                            break;
                        }
                    }

                    // If the flag is still 0, the subarray matches the pattern, so increment the count
                    if (flag == 0) {
                        count++;
                    }
                }
            }
        }

        // Return the final count of matching subarrays
        return count;
    }
}