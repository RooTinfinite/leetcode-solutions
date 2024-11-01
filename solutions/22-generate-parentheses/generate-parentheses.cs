public class Solution {
    // Helper function that generates valid parentheses combinations recursively
    private void Solve(List<string> ans, StringBuilder s, int open, int close, int n) {
        // Base case: when we have used n opening and n closing brackets
        if (close == n && open == n) {
            ans.Add(s.ToString());
            return;
        }

        // Case 1: We can add an opening bracket if we haven't used all n
        if (open < n) {
            s.Append('(');
            Solve(ans, s, open + 1, close, n);
            s.Length--;
        }

        // Case 2: We can add a closing bracket if we have more opening brackets
        if (close < open) {
            s.Append(')');
            Solve(ans, s, open, close + 1, n);
            s.Length--;
        }
    }

    public IList<string> GenerateParenthesis(int n) {
        var ans = new List<string>();
        var s = new StringBuilder();
        Solve(ans, s, 0, 0, n);
        return ans;
    }
}