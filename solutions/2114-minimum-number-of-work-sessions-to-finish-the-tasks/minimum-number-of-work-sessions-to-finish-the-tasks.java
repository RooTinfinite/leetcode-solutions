class Solution {
    int n, sessionTime;
    Integer[][] memo = new Integer[1<<14][15];
    public int minSessions(int[] tasks, int sessionTime) {
        n = tasks.length;
        this.sessionTime = sessionTime;
        return dp(tasks, (1 << n) - 1, 0);
    }
    int dp(int[] tasks, int mask, int remainTime) {
        if (mask == 0) return 0;
        if (memo[mask][remainTime] != null) return memo[mask][remainTime];
        int ans = n;  // There is up to N work sessions
        for (int i = 0; i < n; ++i) {
            if (((mask >> i) & 1) == 1) {
                int newMask = ~(1 << i) & mask; // clear i th bit
                if (tasks[i] <= remainTime) {
                    ans = Math.min(ans, dp(tasks, newMask, remainTime - tasks[i])); // Consume current session
                } else {
                    ans = Math.min(ans, dp(tasks, newMask, sessionTime - tasks[i]) + 1); // Create new session
                }
            }
        }
        return memo[mask][remainTime] = ans;
    }
}