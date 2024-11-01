class Solution {
public:
    // Helper function that generates valid parentheses combinations recursively
    // ans: stores all valid combinations
    // s: current combination being built
    // open: count of opening brackets used
    // close: count of closing brackets used
    // n: total number of pairs needed
    void solve(vector<string>& ans, string& s, int open, int close, int n) {
        // Base case: when we have used n opening and n closing brackets
        // we have a valid combination
        if (close == n && open == n) {
            ans.push_back(s);
            return;
        }

        // Case 1: We can add an opening bracket if we haven't used all n
        // opening brackets yet
        if (open < n) {
            s += "(";                                  // Add opening bracket
            solve(ans, s, open + 1, close, n);        // Recurse with updated count
            s.pop_back();                             // Backtrack by removing the bracket
        }

        // Case 2: We can add a closing bracket if we have more opening brackets
        // than closing brackets so far
        if (close < open) {
            s += ")";                                 // Add closing bracket
            solve(ans, s, open, close + 1, n);        // Recurse with updated count
            s.pop_back();                             // Backtrack by removing the bracket
        }
    }

    // Main function that returns all valid parentheses combinations
    vector<string> generateParenthesis(int n) {
        vector<string> ans;                           // Store all valid combinations
        string s;                                     // Current combination being built
        solve(ans, s, 0, 0, n);                      // Start with empty string and 0 counts
        return ans;
    }
};