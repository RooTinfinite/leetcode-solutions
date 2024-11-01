class Solution:
    def solve(self, ans: list[str], s: str, open: int, close: int, n: int) -> None:
        # Base case: when we have used n opening and n closing brackets
        # we have a valid combination
        if close == n and open == n:
            ans.append(s)
            return
        
        # Case 1: We can add an opening bracket if we haven't used all n
        # opening brackets yet
        if open < n:
            self.solve(ans, s + "(", open + 1, close, n)
        
        # Case 2: We can add a closing bracket if we have more opening brackets
        # than closing brackets so far
        if close < open:
            self.solve(ans, s + ")", open, close + 1, n)
    
    def generateParenthesis(self, n: int) -> list[str]:
        ans = []                    # Store all valid combinations
        self.solve(ans, "", 0, 0, n)  # Start with empty string and 0 counts
        return ans