class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result(s.length() + spaces.size(), 0);
        int writePos = 0;
        int readPos = 0;
        
        for (int spacePos : spaces) {
            while (readPos < spacePos) {
                result[writePos++] = s[readPos++];
            }
            result[writePos++] = ' ';
        }
        
        while (readPos < s.length()) {
            result[writePos++] = s[readPos++];
        }
        
        return result;
    }
};