# Method that generates all valid combinations of n pairs of parentheses
def generate_parenthesis(n)
    @result = []  # Initialize array to store all valid combinations
    solve("", 0, 0, n)  # Start recursive process with empty string
    @result  # Return the final result array
end

# Recursive helper method that builds valid combinations
# Parameters:
# s - current string being built
# open - count of opening brackets used so far
# close - count of closing brackets used so far
# n - total number of pairs needed
def solve(s, open, close, n)
    # Base case: if we've used n opening AND n closing brackets
    # we have a complete valid combination
    if close == n && open == n
        @result.push(s)  # Add the valid combination to results
        return
    end
    
    # If we haven't used all opening brackets yet (open < n)
    # we can add an opening bracket
    if open < n
        solve(s + "(", open + 1, close, n)
    end
    
    # If we have more opening brackets than closing brackets
    # we can add a closing bracket
    if close < open
        solve(s + ")", open, close + 1, n)
    end
end