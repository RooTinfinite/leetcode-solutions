class Solution {
    // Function to generate all valid combinations of n pairs of parentheses
    func generateParenthesis(_ n: Int) -> [String] {
        // Stack to build current combination
        var stack: [String] = []
        // Array to store all valid combinations
        var res: [String] = []
        
        // Recursive backtracking function
        // open: count of opening brackets used
        // close: count of closing brackets used
        func backtrack(_ open: Int, _ close: Int) {
            // Base case: when we have used n opening and n closing brackets
            // we have a valid combination
            if open == close && close == n {
                // Join all characters in stack and add to result
                res.append(stack.joined())
                return
            }
            
            // Case 1: We can add an opening bracket if we haven't used all n
            if open < n {
                // Add opening bracket
                stack.append("(")
                // Recurse with incremented open count
                backtrack(open + 1, close)
                // Backtrack by removing the last added bracket
                stack.removeLast()
            }
            
            // Case 2: We can add a closing bracket if we have more opening brackets than closing
            if close < open {
                // Add closing bracket
                stack.append(")")
                // Recurse with incremented close count
                backtrack(open, close + 1)
                // Backtrack by removing the last added bracket
                stack.removeLast()
            }
        }
        
        // Start the backtracking with 0 opening and closing brackets
        backtrack(0, 0)
        return res
    }
}