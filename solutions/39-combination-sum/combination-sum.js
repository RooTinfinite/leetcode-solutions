/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    const result = [];
    
    function findCombinations(index, target, current) {
        // Base case: if target becomes 0, we found a valid combination
        if (target === 0) {
            result.push([...current]); // Create a new array copy
            return;
        }
        
        // Try all possible numbers from current index
        for (let i = index; i < candidates.length; i++) {
            // Only proceed if current number doesn't exceed target
            if (candidates[i] <= target) {
                // Include current number in combination
                current.push(candidates[i]);
                
                // Recursive call with:
                // - same index i (allowing reuse of same number)
                // - reduced target by current number
                findCombinations(i, target - candidates[i], current);
                
                // Backtrack: remove the last added number to try other combinations
                current.pop();
            }
        }
    }
    
    findCombinations(0, target, []);
    return result;
};