class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        
        // Create a copy of input array to work with
        vector<int> values = nums;

        // Forward pass - check and swap from left to right
        for (int i = 0; i < n - 1; i++) {
            // Skip if elements are already in order
            if (values[i] <= values[i + 1]) continue;
            else {
                // Check if adjacent elements have same number of set bits
                if (__builtin_popcount(values[i]) == __builtin_popcount(values[i + 1])) {
                    // Swap elements if they have same number of set bits
                    swap(values[i], values[i + 1]);
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
                if (__builtin_popcount(values[i]) == __builtin_popcount(values[i - 1])) {
                    // Swap elements if they have same number of set bits
                    swap(values[i], values[i - 1]);
                } 
                else return false; // Cannot swap elements with different number of set bits
            }
        }

        // Array can be sorted if we reach here
        return true;
    }
};