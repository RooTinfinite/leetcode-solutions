class Solution {
public:
    static bool canMakeSubsequence(string& source, string& target) {
        const int srcLen = source.size(), tgtLen = target.size();
        if (srcLen < tgtLen) return false;
        
        int tgtIdx = 0;
        uint32_t targetMask = 1u << (target[0] - 'a');
        
        for(int srcIdx = 0; srcIdx < srcLen && tgtIdx < tgtLen; srcIdx++) {
            uint32_t srcMask = 1u << (source[srcIdx] - 'a');
            uint32_t nextMask = 1u << ((source[srcIdx] - 'a' + 1) % 26);
            
            if ((targetMask & (srcMask | nextMask)) != 0) {
                tgtIdx++;
                if (tgtIdx < tgtLen) {
                    targetMask = 1u << (target[tgtIdx] - 'a');
                }
            }
        }
        
        return tgtIdx == tgtLen;
    }
};