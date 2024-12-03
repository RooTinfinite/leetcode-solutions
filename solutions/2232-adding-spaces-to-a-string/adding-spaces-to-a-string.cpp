class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        result.reserve(s.length() + spaces.size());
        
        int currentPos = 0;
        for (int spacePos : spaces) {
            result.append(s.substr(currentPos, spacePos - currentPos));
            result.push_back(' ');
            currentPos = spacePos;
        }
        
        result.append(s.substr(currentPos));
        return result;
    }
};