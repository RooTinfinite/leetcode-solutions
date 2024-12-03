class Solution {
public:
    string addSpaces(string& s, vector<int>& spaces) {
        const size_t finalSize = s.size() + spaces.size();
        string result;
        result.reserve(finalSize);
        
        size_t spaceIdx = 0;
        size_t currentPos = 0;
        
        string_view sv(s);
        
        while (spaceIdx < spaces.size()) {
            size_t nextSpace = spaces[spaceIdx];
            result.append(sv.substr(currentPos, nextSpace - currentPos));
            result += ' ';
            currentPos = nextSpace;
            ++spaceIdx;
        }
        
        if (currentPos < s.size()) {
            result.append(sv.substr(currentPos));
        }
        
        return result;
    }
};