// This function generates all possible permutations of an array of numbers
function permute(nums: number[]): number[][] {
    // Store all permutations we find
    const permuations: number[][] = [];
    
    // Temporary array to build each permutation
    const chunks: number[] = [];

    // Backtracking function that uses bit manipulation to track used numbers
    // flags: binary number where each bit represents if a number is used (1) or not (0)
    function backtrack(flags: number) {
        // Base case: if our current permutation is same length as input array
        // we've found a valid permutation
        if (chunks.length === nums.length) {
            // Add a copy of current permutation to results
            permuations.push([...chunks]);
            return;
        }

        // Try each number in the input array
        for (let i = 0; i < nums.length; i++) {
            // Check if number at index i is already used using bit manipulation
            // (flags >> i) shifts bits right by i positions
            // & 1 checks if rightmost bit is 1 (used) or 0 (unused)
            if ((flags >> i) & 1) continue;

            // Add current number to our permutation
            chunks.push(nums[i]);

            // Recursive call with updated flags
            // flags | (1 << i) sets the bit at position i to 1
            // marking this number as used
            backtrack(flags | (1 << i));

            // Backtrack by removing the number we just tried
            chunks.pop();
        }
    }

    // Start backtracking with no numbers used (flags = 0)
    backtrack(0);
    
    // Return all found permutations
    return permuations;
}