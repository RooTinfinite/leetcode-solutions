class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result(s.length() + spaces.size(), 0);
        int shift = 1;
        int prev = 0;
        
        memcpy(&result[0], &s[0], spaces[0]);
        result[spaces[0]] = ' ';
        
        for (int i = 1; i < spaces.size(); ++i) {
            int len = spaces[i] - spaces[i-1];
            memcpy(&result[spaces[i-1] + shift], &s[spaces[i-1]], len);
            result[spaces[i] + shift] = ' ';
            shift++;
        }
        
        if (!spaces.empty()) {
            memcpy(&result[spaces.back() + shift], 
                   &s[spaces.back()], 
                   s.length() - spaces.back());
        }
        
        return result;
    }
};