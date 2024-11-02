class Solution {
public:
    bool isCircularSentence(string s) {
        // Check first and last character match
        if (s[0] != s[s.length() - 1])
            return false;

        // Find first space
        size_t k = s.find(" ");
        
        // Single word case
        if (k == string::npos)
            return true;

        // Check each word boundary
        while (k != string::npos) {
            if (s[k - 1] != s[k + 1]) {
                return false;
            }
            k = s.find(" ", k + 1);
        }
        
        return true;
    }
};