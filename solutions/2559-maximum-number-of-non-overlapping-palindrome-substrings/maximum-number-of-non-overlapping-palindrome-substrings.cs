public class Solution {
    public int MaxPalindromes(string s, int k) {
        int n = s.Length;
        bool[,] isPalindrome = new bool[n, n];

        for (int len = 1; len <= n; ++len) {
            for (int left = 0; left + len <= n; ++left) {
                int right = left + len - 1;
                isPalindrome[left, right] =
                    s[left] == s[right] &&
                    (len <= 2 || isPalindrome[left + 1, right - 1]);
            }
        }

        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            for (int j = 0; j + k <= i; ++j) {
                if (isPalindrome[j, i - 1]) {
                    dp[i] = Math.Max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
}