public class Solution {
    // Helper function that generates all permutations using backtracking
    private void Solve(int[] nums, int l, int r, IList<IList<int>> result) {
        // Base case: when left index equals right index
        if (l == r) {
            result.Add(new List<int>(nums));  // Add current permutation to result
            return;
        }
        
        // Try all possible elements at position 'l'
        for (int i = l; i <= r; i++) {
            // 1. Swap current element with element at position 'l'
            Swap(nums, l, i);
            
            // 2. Recursively generate permutations for remaining elements
            Solve(nums, l + 1, r, result);
            
            // 3. Backtrack: restore array to original state by swapping back
            Swap(nums, l, i);
        }
    }

    // Helper method to swap elements in array
    private void Swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Main function that initializes the permutation generation
    public IList<IList<int>> Permute(int[] nums) {
        IList<IList<int>> result = new List<IList<int>>();  // Stores all permutations
        Solve(nums, 0, nums.Length - 1, result);  // Start with full array range
        return result;
    }
}