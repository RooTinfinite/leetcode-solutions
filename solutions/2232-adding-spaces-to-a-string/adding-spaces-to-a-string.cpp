class Solution {
public:
    string addSpaces(string& s, vector<int>& spaces) {
        string result(s.length() + spaces.size(), ' ');
        int writePos = 0;
        const int spacesSize = spaces.size();
        for (int i = 0; i < spaces[0]; i++) {
            result[writePos++] = s[i];
        }
        
        for (int i = 0; i < spacesSize - 1; i++) {
            writePos++;
            for (int j = spaces[i]; j < spaces[i + 1]; j++) {
                result[writePos++] = s[j];
            }
        }
        
        if (spacesSize > 0) {
            writePos++; 
            for (int i = spaces[spacesSize - 1]; i < s.length(); i++) {
                result[writePos++] = s[i];
            }
        }
        
        return result;
    }
};