public class Solution {
    public bool CanMakeSubsequence(string source, string target) {
        int targetIdx = 0, targetLen = target.Length;
        
        foreach (char currChar in source) {
            if (targetIdx < targetLen && (target[targetIdx] - currChar + 26) % 26 <= 1) {
                targetIdx++;
            }
        }
        return targetIdx == targetLen;
    }
}