class Solution {
public:
    string makeFancyString(string s) {
        string ret;
        int cnt = 1;
        char prev = '\0';
        
        for (char c : s) {
            if (c == prev) {
                cnt++;
            } else {
                cnt = 1;
            }
            
            prev = c;
            
            if (cnt < 3) {
                ret += c;
            }
        }
        
        return ret;
    }
};