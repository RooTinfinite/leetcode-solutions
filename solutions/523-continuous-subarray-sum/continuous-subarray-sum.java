import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        // Map to store <Remainder, Index>
        // Initialize with 0:-1 to handle subarrays starting at index 0
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        
        int currentSum = 0;
        
        for (int i = 0; i < nums.length; i++) {
            currentSum += nums[i];
            
            // Calculate remainder
            int remainder = currentSum % k;
            
            // If we have seen this remainder before
            if (map.containsKey(remainder)) {
                int prevIndex = map.get(remainder);
                // Check if the subarray length is at least 2
                if (i - prevIndex >= 2) {
                    return true;
                }
            } else {
                // Store the first occurrence of this remainder
                map.put(remainder, i);
            }
        }
        
        return false;
    }
}