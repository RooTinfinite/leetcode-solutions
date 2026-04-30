class Solution {
public:
    int maxPathScore(vector<vector<int>>& A, int k) {
        int n = A.size(), m = A[0].size(), cost0 = (A[0][0] == 0 ? 0 : 1);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));

        if(cost0 <= k)
            dp[0][0][cost0] = A[0][0];

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int cost = (A[i][j] == 0 ? 0 : 1);

                for(int c = cost; c <= k; ++c) {
                    if(i > 0 && dp[i - 1][j][c - cost] != -1)
                        dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j][c - cost] + A[i][j]);

                    if(j > 0 && dp[i][j - 1][c - cost] != -1)
                        dp[i][j][c] = max(dp[i][j][c], dp[i][j - 1][c - cost] + A[i][j]);
                }
            }
        }

        int res = -1;

        for(int c = 0; c <= k; ++c)
            res = max(res, dp[n - 1][m - 1][c]);

        return res;
    }
};