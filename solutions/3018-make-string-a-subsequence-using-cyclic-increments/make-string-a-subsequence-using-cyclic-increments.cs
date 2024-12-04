public class Solution {
    public bool CanMakeSubsequence(string source, string target) {
        int srcLen = source.Length, tgtLen = target.Length;
        char targetChar = target[0];
        
        int srcIdx = 0, tgtIdx = 0;
        while (srcIdx < srcLen && tgtIdx < tgtLen) {
            char srcChar = source[srcIdx];
            
            if (srcChar == targetChar || 
                srcChar + 1 == targetChar || 
                (srcChar == 'z' && targetChar == 'a')) {
                tgtIdx++;
                if (tgtIdx < tgtLen) {
                    targetChar = target[tgtIdx];
                }
            }
            srcIdx++;
        }
        
        return tgtIdx == tgtLen;
    }
}