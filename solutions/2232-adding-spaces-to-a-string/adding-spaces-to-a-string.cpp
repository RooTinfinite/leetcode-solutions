class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0, j = 0;
        string res;
        res.reserve(s.length() + spaces.size());
        
        while (i < s.length() && j < spaces.size()) {
            if (i < spaces[j]) {
                res += s[i];
                i++;
            } else {
                res += ' ';
                j++;
            }
        }
        
        if (i < s.length()) {
            res += s.substr(i);
        }
        
        return res;
    }
};