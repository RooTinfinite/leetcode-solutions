class Solution {
public:
    // Helper function that generates all permutations using backtracking
    // nums: input array to permute
    // l: left index of current subarray being processed
    // r: right index of current subarray being processed
    // result: stores all generated permutations
    void solve(vector<int>& nums, int l, int r, vector<vector<int>>& result) {
        // Base case: when left index equals right index
        // meaning we've processed all positions in current permutation
        if (l == r) {
            result.push_back(nums);  // Add current permutation to result
            return;
        }
        
        // Try all possible elements at position 'l'
        for (int i = l; i <= r; i++) {
            // 1. Swap current element with element at position 'l'
            swap(nums[l], nums[i]);
            
            // 2. Recursively generate permutations for remaining elements
            solve(nums, l + 1, r, result);
            
            // 3. Backtrack: restore array to original state by swapping back
            swap(nums[l], nums[i]);
        }
    }

    // Main function that initializes the permutation generation
    // nums: input array to find permutations for
    // returns: vector containing all possible permutations
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;  // Stores all permutations
        solve(nums, 0, nums.size() - 1, result);  // Start with full array range
        return result;
    }
};