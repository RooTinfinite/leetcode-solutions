// This function finds all unique combinations of numbers from candidates array that sum up to target
function combinationSum(candidates: number[], target: number): number[][] {
    // Store all valid combinations
    const result: number[][] = [];
    
    // Helper function that uses backtracking to find combinations
    // index: current position in candidates array
    // target: remaining sum to achieve
    // current: current combination being built
    function findCombinations(index: number, target: number, current: number[]): void {
        // Base case: if target becomes 0, we found a valid combination
        if (target === 0) {
            // Create a copy of current combination and add to results
            result.push([...current]);
            return;
        }
        
        // Try each candidate number starting from current index
        for (let i = index; i < candidates.length; i++) {
            // Only proceed if the current candidate doesn't exceed remaining target
            if (candidates[i] <= target) {
                // Include current candidate in combination
                current.push(candidates[i]);
                
                // Recursively find combinations with:
                // - same starting index (i) since numbers can be reused
                // - reduced target by current candidate value
                // - updated current combination
                findCombinations(i, target - candidates[i], current);
                
                // Backtrack: remove the last added number to try other combinations
                current.pop();
            }
        }
    }
    
    // Start the recursive process with initial values
    findCombinations(0, target, []);
    return result;
}