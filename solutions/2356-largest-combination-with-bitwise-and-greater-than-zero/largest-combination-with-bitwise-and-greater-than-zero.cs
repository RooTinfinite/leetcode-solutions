public class Solution {
    // This method finds the largest combination of numbers from the candidates array
    // that have at least one common set bit (1) in their binary representation
    public int LargestCombination(int[] candidates) {
        // Create array to store count of 1's at each bit position (32 bits for integers)
        int[] ans = new int[32];
        
        // Iterate through each number in candidates array
        foreach(int x in candidates) {
            // Count the number of 1's at each bit position for current number
            Find(x, ans);
        }
        
        // Find the maximum count of 1's across all bit positions
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res = Math.Max(res, ans[i]);
        }
        
        // Return the largest possible combination
        return res;
    }
    
    // Helper method to count number of 1's at each bit position
    private void Find(int n, int[] ans) {
        // Start from rightmost bit (31st position)
        int j = 31;
        
        // Continue until all bits are processed
        while(n > 0) {
            // Get the rightmost bit using bitwise AND with 1
            int a = (n & 1);
            
            // Add the bit count to corresponding position in ans array
            ans[j] += a;
            
            // Right shift n by 1 to process next bit
            n >>= 1;
            
            // Move to next bit position from right to left
            j--;
        }
    }
}