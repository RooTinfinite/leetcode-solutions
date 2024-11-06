class Solution {
    // Determines if an array can be sorted by swapping adjacent elements with same number of set bits

    public boolean canSortArray(int[] nums) {
        int n = nums.length;
        
        // Create a copy of input array to work with
        int[] values = Arrays.copyOf(nums, n);

        // Forward pass - check and swap from left to right
        for (int i = 0; i < n - 1; i++) {
            // Skip if elements are already in order
            if (values[i] <= values[i + 1]) continue;
            else {
                // Check if adjacent elements have same number of set bits
                if (Integer.bitCount(values[i]) == Integer.bitCount(values[i + 1])) {
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
                if (Integer.bitCount(values[i]) == Integer.bitCount(values[i - 1])) {
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
}