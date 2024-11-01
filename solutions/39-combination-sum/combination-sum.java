class Solution {
    // Recursive helper function to find all combinations
    private void findCombinations(int index, int target, int[] candidates, 
                                List<Integer> current, List<List<Integer>> result) {
        // Base case: if target becomes 0, we found a valid combination
        if (target == 0) {
            result.add(new ArrayList<>(current)); // Add current combination to result
            return;
        }

        // Try all possible numbers from current index
        for (int i = index; i < candidates.length; i++) {
            // Only proceed if current number doesn't exceed target
            if (candidates[i] <= target) {
                // Include current number in combination
                current.add(candidates[i]);

                // Recursive call with:
                // - same index i (allowing reuse of same number)
                // - reduced target by current number
                findCombinations(i, target - candidates[i], candidates, current, result);

                // Backtrack: remove the last added number to try other combinations
                current.remove(current.size() - 1);
            }
        }
    }

    // Main function that initiates the combination finding process
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();    // Stores all valid combinations
        List<Integer> current = new ArrayList<>();         // Temporary list to build combinations
        findCombinations(0, target, candidates, current, result);
        return result;
    }
}
