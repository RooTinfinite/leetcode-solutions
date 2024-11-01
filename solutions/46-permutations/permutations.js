/**
 * Function to generate all possible permutations of an array of numbers
 * @param {number[]} nums - Input array of numbers to permute
 * @return {number[][]} - Array containing all possible permutations
 */
var permute = function (nums) {
    // Store all permutations
    let result = [];

    /**
     * Backtracking function to generate permutations
     * @param {number} start - Starting index for current permutation
     * @param {number} end - Ending index (length of array - 1)
     */
    function backtrack(start, end) {
        // Base case: when start reaches end, we've completed one permutation
        if (start === end) {
            // Create a copy of current permutation and add to result
            result.push([...nums]);
        } else {
            // Try all possible numbers at each position
            for (let i = start; i <= end; i++) {
                // Swap elements at start and i positions
                [nums[start], nums[i]] = [nums[i], nums[start]];

                // Recursively generate permutations for remaining elements
                backtrack(start + 1, end);

                // Backtrack: restore the original array by swapping back
                [nums[start], nums[i]] = [nums[i], nums[start]];
            }
        }
    }

    // Start the backtracking process from index 0
    backtrack(0, nums.length - 1);
    return result;
};