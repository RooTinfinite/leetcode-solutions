class Solution {
    public int minDays(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);

        dp[0] = 0;

        for (int score = 1; score <= n; score++) {

            for (int len = 1; ; len++) {

                int streakScore = len * (len + 1) / 2;

                if (streakScore > score) {
                    break;
                }

                int remaining = score - streakScore;

                if (dp[remaining] == Integer.MAX_VALUE) {
                    continue;
                }

                int skip = remaining == 0 ? 0 : 1;

                dp[score] = Math.min(
                    dp[score],
                    dp[remaining] + len + skip
                );
            }
        }

        return dp[n];
    }
}