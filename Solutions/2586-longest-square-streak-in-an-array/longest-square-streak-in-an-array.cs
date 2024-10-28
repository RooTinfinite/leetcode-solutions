public class Solution {
    public int LongestSquareStreak(int[] nums) {
        // Convert nums to a sorted set to remove duplicates and have ordered numbers
        var numSet = new HashSet<int>(nums);
        var sortedNums = numSet.OrderBy(x => x).ToList();
        
        // Track the maximum streak length found
        int maxLength = 0;
        
        // Iterate through each number in sorted order
        foreach (int num in sortedNums) {
            // Initialize streak length for current number
            int length = 0;
            // Start with current number
            long current = num;
            
            // Keep squaring the number while it exists in our set
            while (current <= int.MaxValue && numSet.Contains((int)current)) {
                length++;
                current = current * current;
            }
            
            // Only update maxLength if we found a streak of length > 1
            if (length > 1) {
                maxLength = Math.Max(maxLength, length);
            }
        }
        
        // Return maxLength if we found a valid streak, otherwise return -1
        return maxLength > 1 ? maxLength : -1;
    }
}