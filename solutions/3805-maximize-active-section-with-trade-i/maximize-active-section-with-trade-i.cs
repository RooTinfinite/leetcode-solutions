public class Solution {
    public int MaxActiveSectionsAfterTrade(string s) {
        int n = s.Length;
        int cnt1 = 0;
        foreach (char c in s) {
            if (c == '1')
                cnt1++;
        }

        int i = 0;
        int bestGain = 0;
        int prev = int.MinValue;
        int cur = 0;
        while (i < n) {
            int start = i;
            while (i < n && s[i] == s[start]) {
                i++;
            }
            if (s[start] == '0') {
                cur = i - start;
                if (prev != int.MinValue) {
                    bestGain = Math.Max(bestGain, prev + cur);
                }
                prev = cur;
            }
        }

        return cnt1 + bestGain;
    }
}