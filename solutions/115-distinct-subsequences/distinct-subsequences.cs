public class Solution {
    public int NumDistinct(string s, string t) {
        int M = s.Length;
        int N = t.Length;
        int[] dp = new int[N];
        int prev = 1;
        for (int i = M - 1; i >= 0; i--) {
            prev = 1;
            for (int j = N - 1; j >= 0; j--) {
                int old_dpj = dp[j];
                if (s[i] == t[j]) {
                    dp[j] += prev;
                }

                prev = old_dpj;
            }
        }

        return dp[0];
    }
}