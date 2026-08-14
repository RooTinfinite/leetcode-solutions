public class Solution {
    public int MaximumLengthSubstring(string s) {
        int n = s.Length;
        int res = 0;
        for (int left = 0; left < n; left++) {
            int[] count = new int[26];
            for (int right = left; right < n; right++) {
                int ch = s[right] - 'a';
                count[ch]++;
                if (count[ch] > 2) {
                    break;
                }
                res = Math.Max(res, right - left + 1);
            }
        }
        return res;
    }
}