const int N = 1000;
// 0: alice first, 1: Bob first
int dp[N][2];

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
            dp[i][1] = stones[i];
        }
        for (int l = 1; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int a = max(dp[i + 1][1], dp[i][1]);
                int b = min(stones[i] + dp[i + 1][0], dp[i][0] + stones[i + l]);
                dp[i][0] = a;
                dp[i][1] = b;
            }
        }
        return dp[0][0];
    }
};