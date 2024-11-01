// combinations stores all valid parentheses combinations
var combinations []string
// number stores the input value n - number of pairs of parentheses to generate
var number int

// generateParenthesis generates all valid combinations of n pairs of parentheses
func generateParenthesis(n int) []string {
    // Initialize empty slice to store results
    combinations = []string{}
    // Store input n as global variable
    number = n
    
    // Start backtracking with empty string and zero open/close counts
    backtrack("", 0, 0)
    
    return combinations
}

// backtrack builds valid combinations recursively
// current: the current combination being built
// open: count of opening parentheses used
// close: count of closing parentheses used
func backtrack(current string, open, close int) {
    // Base case: if current string length equals 2*n, we have a valid combination
    if len(current) == number*2 {
        combinations = append(combinations, current)
        return
    }
    
    // Add opening parenthesis if we haven't used all n opening parentheses
    if open < number {
        backtrack(current+"(", open+1, close)
    }
    
    // Add closing parenthesis if we have more open than closed
    if close < open {
        backtrack(current+")", open, close+1)
    }
}