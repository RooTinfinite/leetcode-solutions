import java.util.*;

class Solution {
    public int longestSquareStreak(int[] nums) {
        // Convert array to TreeSet to remove duplicates and have ordered numbers
        TreeSet<Integer> sortedSet = new TreeSet<>();
        for (int num : nums) {
            sortedSet.add(num);
        }
        
        // Create HashSet for O(1) lookup time
        HashSet<Integer> numSet = new HashSet<>(sortedSet);
        
        // Track the maximum streak length found
        int maxLength = 0;
        
        // Iterate through each number in sorted order
        for (int num : sortedSet) {
            // Initialize streak length for current number
            int length = 0;
            // Start with current number
            long current = num;
            
            // Keep squaring the number while it exists in our set
            while (current <= Integer.MAX_VALUE && numSet.contains((int)current)) {
                length++;
                current = current * current;
            }
            
            // Only update maxLength if we found a streak of length > 1
            if (length > 1) {
                maxLength = Math.max(maxLength, length);
            }
        }
        
        // Return maxLength if we found a valid streak, otherwise return -1
        return maxLength > 1 ? maxLength : -1;
    }
}