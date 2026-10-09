class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;
        string res;
        for (auto c : s) {
            if (c == ')') {
                level--;
            }
            if (level) {
                res.push_back(c);
            }
            if (c == '(') {
                level++;
            }
        }
        return res;
    }
};