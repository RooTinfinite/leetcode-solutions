class Solution {
    // Helper function that generates valid parentheses combinations recursively
    private void solve(List<String> ans, StringBuilder s, int open, int close, int n) {
        // Base case: when we have used n opening and n closing brackets
        if (close == n && open == n) {
            ans.add(s.toString());
            return;
        }

        // Case 1: We can add an opening bracket if we haven't used all n
        if (open < n) {
            s.append("(");
            solve(ans, s, open + 1, close, n);
            s.setLength(s.length() - 1);
        }

        // Case 2: We can add a closing bracket if we have more opening brackets
        if (close < open) {
            s.append(")");
            solve(ans, s, open, close + 1, n);
            s.setLength(s.length() - 1);
        }
    }

    // Main function that returns all valid parentheses combinations
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        StringBuilder s = new StringBuilder();
        solve(ans, s, 0, 0, n);
        return ans;
    }
}