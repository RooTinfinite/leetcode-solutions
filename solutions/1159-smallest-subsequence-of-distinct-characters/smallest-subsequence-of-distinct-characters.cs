public class Solution {
    public string SmallestSubsequence(string s) {
        int[] vis = new int[26];
        int[] num = new int[26];

        foreach (char ch in s) {
            num[ch - 'a']++;
        }
        var stk = new System.Text.StringBuilder();

        foreach (char ch in s) {
            if (vis[ch - 'a'] == 0) {
                while (stk.Length > 0 && stk[stk.Length - 1] > ch) {
                    if (num[stk[stk.Length - 1] - 'a'] > 0) {
                        vis[stk[stk.Length - 1] - 'a'] = 0;
                        stk.Length--;
                    } else {
                        break;
                    }
                }
                vis[ch - 'a'] = 1;
                stk.Append(ch);
            }
            num[ch - 'a']--;
        }

        return stk.ToString();
    }
}