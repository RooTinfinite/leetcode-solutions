class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3) return s;
        
        string result;
        result.reserve(s.length()); // Pre-allocate memory
        
        // Add first two characters
        result.push_back(s[0]);
        result.push_back(s[1]);
        
        // Check for three consecutive characters
        for (int i = 2; i < s.length(); i++) {
            if (s[i] != s[i-1] || s[i] != s[i-2]) {
                result.push_back(s[i]);
            }
        }
        
        return result;
    }
};