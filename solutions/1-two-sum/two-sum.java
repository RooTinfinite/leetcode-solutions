class Solution {
    public int[] twoSum(int[] nums, int target) {
        // Hash table to store number->index mapping
        Map<Integer, Integer> ht = new HashMap<>();
        
        // Iterate through the array
        for (int i = 0; i < nums.length; i++) {
            int tmp = nums[i];
            
            // Check if complement (target - current number) exists in hash table
            if (ht.containsKey(target - tmp)) {
                // If found, return indices of both numbers
                return new int[] {ht.get(target - tmp), i};
            }
            
            // Store current number and its index in hash table
            ht.put(tmp, i);
        }
        
        // Return empty array if no solution found
        return new int[0];
    }
}