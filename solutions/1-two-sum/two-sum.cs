public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        // Hash table to store number->index mapping
        Dictionary<int, int> ht = new Dictionary<int, int>();
        
        // Iterate through the array
        for (int i = 0; i < nums.Length; i++) {
            int tmp = nums[i];
            
            // Check if complement (target - current number) exists in hash table
            if (ht.ContainsKey(target - tmp)) {
                // If found, return indices of both numbers
                return new int[] {ht[target - tmp], i};
            }
            
            // Store current number and its index in hash table
            ht[tmp] = i;
        }
        
        // Return empty array if no solution found
        return new int[0];
    }
}