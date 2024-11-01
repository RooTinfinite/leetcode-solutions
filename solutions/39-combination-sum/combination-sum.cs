public class Solution {
    // Main function that initiates the combination finding process
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        var result = new List<IList<int>>();    // Stores all valid combinations
        var current = new List<int>();          // Temporary list to build combinations
        FindCombinations(0, target, candidates, current, result);
        return result;
    }
    
    // Recursive helper function to find all combinations
    private void FindCombinations(int index, int target, int[] candidates, 
                                List<int> current, List<IList<int>> result) {
        // Base case: if target becomes 0, we found a valid combination
        if (target == 0) {
            result.Add(new List<int>(current)); // Add current combination to result
            return;
        }

        // Try all possible numbers from current index
        for (int i = index; i < candidates.Length; i++) {
            // Only proceed if current number doesn't exceed target
            if (candidates[i] <= target) {
                // Include current number in combination
                current.Add(candidates[i]);

                // Recursive call with:
                // - same index i (allowing reuse of same number)
                // - reduced target by current number
                FindCombinations(i, target - candidates[i], candidates, current, result);

                // Backtrack: remove the last added number to try other combinations
                current.RemoveAt(current.Count - 1);
            }
        }
    }
}