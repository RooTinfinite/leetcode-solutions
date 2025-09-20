class Solution {
public:
    static const int MOD = 1e9 + 7;
    int dp[4001][3001];  
    int offset = 1000;   

    int solve(int curr, int end, int k) {
        if (k == 0) return curr == end ? 1 : 0;

        if (dp[curr + offset][k] != -1) return dp[curr + offset][k];

        long long left = solve(curr - 1, end, k - 1);
        long long right = solve(curr + 1, end, k - 1);
        
        return dp[curr + offset][k] = (left + right) % MOD;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(startPos, endPos, k);
    }
};