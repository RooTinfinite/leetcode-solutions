class Solution {
public:
    string addSpaces(string& s, vector<int>& spaces) {
        const int m = spaces.size();
        const int n = s.size();
        const int finalSize = n + m;
        
        string result;
        result.reserve(finalSize);
        
        int spaceIdx = 0;
        int currentPos = 0;
        
        while (spaceIdx < m && currentPos < n) {
            if (currentPos == spaces[spaceIdx]) {
                result.push_back(' ');
                spaceIdx++;
            }
            result.push_back(s[currentPos++]);
        }
        while (currentPos < n) {
            result.push_back(s[currentPos++]);
        }
        return result;
    }
};