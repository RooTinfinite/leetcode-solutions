class Solution {
public:
    static bool canMakeSubsequence(string& source, string& target) {
        const int srcLen = source.size(), tgtLen = target.size();
        if (srcLen < tgtLen) return false;
        
        int tgtIdx = 0;
        char targetChar = target[0];
        
        for(int srcIdx = 0; srcIdx < srcLen && tgtIdx < tgtLen; srcIdx++) {
            int diff = ((target[tgtIdx] - source[srcIdx]) + 26) % 26;
            if (diff == 0 || diff == 1) {
                tgtIdx++;
                if (tgtIdx < tgtLen) targetChar = target[tgtIdx];
            }
        }
        
        return tgtIdx == tgtLen;
    }
};