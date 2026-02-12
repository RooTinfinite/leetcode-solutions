public class Solution {
    public int LongestBalanced(string s) {
        int n = s.Length;
        int res = 0;
        int[] cnt = new int[26];

        for (int i = 0; i < n; i++) {
            Array.Fill(cnt, 0);
            for (int j = i; j < n; j++) {
                bool flag = true;
                int c = s[j] - 'a';
                cnt[c]++;

                foreach (int x in cnt) {
                    if (x > 0 && x != cnt[c]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    res = Math.Max(res, j - i + 1);
                }
            }
        }
        return res;
    }
}