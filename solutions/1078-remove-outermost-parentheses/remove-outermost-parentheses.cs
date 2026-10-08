public class Solution {
    public string RemoveOuterParentheses(string s) {
        int level = 0;
        StringBuilder res = new StringBuilder();
        foreach (char c in s) {
            if (c == ')') {
                level--;
            }
            if (level > 0) {
                res.Append(c);
            }
            if (c == '(') {
                level++;
            }
        }
        return res.ToString();
    }
}