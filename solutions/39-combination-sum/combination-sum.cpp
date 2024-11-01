class Solution {
public:
    // Recursive helper function to find all combinations
    // index: current position in candidates array
    // target: remaining sum to achieve
    // candidates: input array of numbers
    // current: current combination being built
    // result: stores all valid combinations
    void findCombinations(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if target becomes 0, we found a valid combination
        if (target == 0) {
            result.push_back(current); // Add current combination to result
            return;
        }

        // Try all possible numbers from current index
        for (int i = index; i < candidates.size(); i++) {
            // Only proceed if current number doesn't exceed target
            if (candidates[i] <= target) {
                // Include current number in combination
                current.push_back(candidates[i]); 

                // Recursive call with:
                // - same index i (allowing reuse of same number)
                // - reduced target by current number
                findCombinations(i, target - candidates[i], candidates, current, result); 

                // Backtrack: remove the last added number to try other combinations
                current.pop_back(); 
            }
        }
    }

    // Main function that initiates the combination finding process
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;    // Stores all valid combinations
        vector<int> current;           // Temporary vector to build combinations
        findCombinations(0, target, candidates, current, result);
        return result;
    }
};