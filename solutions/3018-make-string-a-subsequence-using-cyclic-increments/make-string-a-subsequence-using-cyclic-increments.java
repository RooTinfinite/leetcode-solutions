class Solution {
    public static boolean canMakeSubsequence(String source, String target) {
        int srcLen = source.length(), tgtLen = target.length();
        char targetChar = target.charAt(0);
        
        int srcIdx = 0, tgtIdx = 0;
        while (srcIdx < srcLen && tgtIdx < tgtLen) {
            char srcChar = source.charAt(srcIdx);
            
            if (srcChar == targetChar || 
                (char)(srcChar + 1) == targetChar || 
                (srcChar == 'z' && targetChar == 'a')) {
                tgtIdx++;
                if (tgtIdx < tgtLen) {
                    targetChar = target.charAt(tgtIdx);
                }
            }
            
            srcIdx++;
        }
        
        return tgtIdx == tgtLen;
    }
}