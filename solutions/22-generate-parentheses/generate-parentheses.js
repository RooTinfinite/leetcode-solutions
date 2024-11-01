/**
 * @param {number} n - Number of pairs of parentheses to generate
 * @return {string[]} - Array containing all valid combinations
 */
var generateParenthesis = function(n) {
    // Store all valid combinations
    const ans = [];
    
    /**
     * Helper function that generates valid parentheses combinations recursively
     * @param {string} s - Current combination being built
     * @param {number} open - Count of opening brackets used
     * @param {number} close - Count of closing brackets used
     */
    function solve(s, open, close) {
        // Base case: when we have used n opening and n closing brackets
        // we have a valid combination
        if (close === n && open === n) {
            ans.push(s);
            return;
        }
        
        // Case 1: We can add an opening bracket if we haven't used all n
        // opening brackets yet
        if (open < n) {
            solve(s + "(", open + 1, close);
        }
        
        // Case 2: We can add a closing bracket if we have more opening brackets
        // than closing brackets so far
        if (close < open) {
            solve(s + ")", open, close + 1);
        }
    }
    
    // Start recursion with empty string and 0 counts
    solve("", 0, 0);
    return ans;
};