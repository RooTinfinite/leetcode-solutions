impl Solution {
    // Helper function that generates valid parentheses combinations recursively
    fn solve(ans: &mut Vec<String>, s: &mut String, open: i32, close: i32, n: i32) {
        // Base case: when we have used n opening and n closing brackets
        if close == n && open == n {
            ans.push(s.clone());
            return;
        }

        // Case 1: We can add an opening bracket if we haven't used all n
        if open < n {
            s.push('(');
            Self::solve(ans, s, open + 1, close, n);
            s.pop();
        }

        // Case 2: We can add a closing bracket if we have more opening brackets
        if close < open {
            s.push(')');
            Self::solve(ans, s, open, close + 1, n);
            s.pop();
        }
    }

    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut ans = Vec::new();
        let mut s = String::new();
        Self::solve(&mut ans, &mut s, 0, 0, n);
        ans
    }
}