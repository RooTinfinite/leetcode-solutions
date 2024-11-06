public class Solution {
    public bool CanSortArray(int[] nums) {
        int n = nums.Length;
        
        // Create a copy of input array to work with
        int[] values = new int[n];
        Array.Copy(nums, values, n);

        // Forward pass - check and swap from left to right
        for (int i = 0; i < n - 1; i++) {
            // Skip if elements are already in order
            if (values[i] <= values[i + 1]) continue;
            else {
                // Check if adjacent elements have same number of set bits
                if (BitCount(values[i]) == BitCount(values[i + 1])) {
                    // Swap elements if they have same number of set bits
                    int temp = values[i];
                    values[i] = values[i + 1];
                    values[i + 1] = temp;
                } 
                else return false; // Cannot swap elements with different number of set bits
            }
        }

        // Backward pass - check and swap from right to left
        for (int i = n - 1; i >= 1; i--) {
            // Skip if elements are already in order
            if (values[i] >= values[i - 1]) continue;
            else {
                // Check if adjacent elements have same number of set bits
                if (BitCount(values[i]) == BitCount(values[i - 1])) {
                    // Swap elements if they have same number of set bits
                    int temp = values[i];
                    values[i] = values[i - 1];
                    values[i - 1] = temp;
                } 
                else return false; // Cannot swap elements with different number of set bits
            }
        }

        // Array can be sorted if we reach here
        return true;
    }
    
    private int BitCount(int n) {
        int count = 0;
        while (n != 0) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
}