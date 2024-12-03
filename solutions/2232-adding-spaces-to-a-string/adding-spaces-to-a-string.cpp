class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int totalLength = s.size() + spaces.size(); 
        char result[totalLength]; 
        int sIndex = 0, spacesIndex = 0, resultIndex = 0;

        while (sIndex < s.size()) {
            if (spacesIndex < spaces.size() && sIndex == spaces[spacesIndex]) {
                result[resultIndex++] = ' '; 
                spacesIndex++;
            }
            result[resultIndex++] = s[sIndex++]; 
        }

        return string(result, totalLength); 
    }
};