class Solution {
    vector<int> dp;
    int p = 1e9 + 7;
    int dfs(int n) {
        if (n <= 2) return 1;
        if (dp[n] != 0) return dp[n];
        long ans = 0;
        for (int i = 2; i <= n; i += 2) {
            ans = (ans + (long)dfs(n - i) * dfs(i - 2)) % p;
        }
        dp[n] = ans;
        return ans;
    }
public:
    int numberOfWays(int n) {
        dp.resize(1001, 0);
        return dfs(n);
    }
};