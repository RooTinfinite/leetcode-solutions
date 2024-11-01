/**
 * Function to generate all valid combinations of n pairs of parentheses
 * @param n The number of pairs of parentheses to generate
 * @returns Array of strings containing all valid combinations
 */
function generateParenthesis(n: number): string[] {
    // Initialize array to store all valid combinations
    const ans: string[] = [];
    
    /**
     * Recursive helper function to build valid combinations
     * @param s Current string being constructed
     * @param open Number of opening brackets used so far
     * @param close Number of closing brackets used so far
     */
    function solve(s: string, open: number, close: number): void {
        // Base case: when we've used all n pairs of brackets
        // we've found a valid combination
        if (close === n && open === n) {
            ans.push(s);
            return;
        }
        
        // Case 1: Add opening bracket if we haven't used all n
        // We can always add an opening bracket if we have remaining ones
        if (open < n) {
            solve(s + "(", open + 1, close);
        }
        
        // Case 2: Add closing bracket if it's valid
        // We can only add a closing bracket if we have more opening than closing
        if (close < open) {
            solve(s + ")", open, close + 1);
        }
    }
    
    // Start the recursion with empty string and zero counters
    solve("", 0, 0);
    return ans;
}