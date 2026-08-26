public class Solution {
    public string ShortestBeautifulSubstring(string s, int k) {
        for (int m = k; m <= s.Length; m++) {
            string ans = "";
            for (int i = m; i <= s.Length; i++) {
                string t = s.Substring(i - m, m);
                if ((ans.Length == 0 || string.CompareOrdinal(t, ans) < 0) &&
                    t.Count(c => c == '1') == k) {
                    ans = t;
                }
            }
            if (ans.Length > 0) {
                return ans;
            }
        }
        return "";
    }
}