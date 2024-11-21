class Solution {
public:
    int firstUniqChar(string s) {
        int firstUnique = INT_MAX;
        
        for (char c = 'a'; c <= 'z'; c++) {
            size_t firstPos = s.find(c);
            if (firstPos != string::npos) {
                size_t lastPos = s.rfind(c);
                if (firstPos == lastPos) {
                    firstUnique = min(firstUnique, (int)firstPos);
                }
            }
        }
        
        return firstUnique == INT_MAX ? -1 : firstUnique;
    }
};