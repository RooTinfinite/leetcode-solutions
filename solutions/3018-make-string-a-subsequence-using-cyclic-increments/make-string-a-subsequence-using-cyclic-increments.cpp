class Solution {
public:
    static bool canMakeSubsequence(string& source, string& target) {
        if (target.size() > source.size()) return false;
        
        int tgtIdx = 0;
        const int tgtLen = target.size();
        
        for (char srcChar : source) {
            char nextChar = srcChar == 'z' ? 'a' : srcChar + 1;
            if (target[tgtIdx] == srcChar || target[tgtIdx] == nextChar) {
                if (++tgtIdx == tgtLen) return true;
            }
        }
        
        return false;
    }
};