class Solution {
public:
    string addSpaces(string& s, vector<int>& spaces) {
        const size_t spaceCount = spaces.size();
        const size_t strLength = s.size();
        const size_t resultLength = strLength + spaceCount;
        
        string result;
        result.reserve(resultLength);
        
        size_t spaceIdx = 0;
        size_t currentPos = 0;
        
        while (currentPos + 4 <= strLength && spaceIdx < spaceCount) {
            uint32_t chunk = *reinterpret_cast<const uint32_t*>(s.data() + currentPos);
            
            for (size_t i = 0; i < 4; ++i) {
                if (spaceIdx < spaceCount && currentPos + i == static_cast<size_t>(spaces[spaceIdx])) {
                    result.push_back(' ');
                    ++spaceIdx;
                }
                result.push_back(static_cast<char>((chunk >> (i * 8)) & 0xFF));
            }
            currentPos += 4;
        }
        
        while (currentPos < strLength) {
            if (spaceIdx < spaceCount && currentPos == static_cast<size_t>(spaces[spaceIdx])) {
                result.push_back(' ');
                ++spaceIdx;
            }
            result.push_back(s[currentPos]);
            ++currentPos;
        }
        
        while (spaceIdx < spaceCount) {
            result.push_back(' ');
            ++spaceIdx;
        }
        
        return result;
    }
};