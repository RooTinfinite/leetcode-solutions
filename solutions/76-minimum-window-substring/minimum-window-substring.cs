public class Solution {
    public string MinWindow(string s, string t) {
        if (s.Length == 0 || t.Length == 0) {
            return "";
        }

        Dictionary<char, int> dictT = new Dictionary<char, int>();
        for (int i = 0; i < t.Length; i++) {
            int count = dictT.ContainsKey(t[i]) ? dictT[t[i]] : 0;
            dictT[t[i]] = count + 1;
        }

        int required = dictT.Count;
        List<KeyValuePair<int, char>> filteredS =
            new List<KeyValuePair<int, char>>();
        for (int i = 0; i < s.Length; i++) {
            char c = s[i];
            if (dictT.ContainsKey(c)) {
                filteredS.Add(new KeyValuePair<int, char>(i, c));
            }
        }

        int l = 0, r = 0, formed = 0;
        Dictionary<char, int> windowCounts = new Dictionary<char, int>();
        int[] ans = { -1, 0, 0 };
        while (r < filteredS.Count) {
            char c = filteredS[r].Value;
            int count = windowCounts.ContainsKey(c) ? windowCounts[c] : 0;
            windowCounts[c] = count + 1;
            if (dictT.ContainsKey(c) && windowCounts[c] == dictT[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                c = filteredS[l].Value;
                int end = filteredS[r].Key;
                int start = filteredS[l].Key;
                if (ans[0] == -1 || end - start + 1 < ans[0]) {
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;
                }

                windowCounts[c] = windowCounts[c] - 1;
                if (dictT.ContainsKey(c) && windowCounts[c] < dictT[c]) {
                    formed--;
                }

                l++;
            }

            r++;
        }

        return ans[0] == -1 ? "" : s.Substring(ans[1], ans[2] - ans[1] + 1);
    }
}