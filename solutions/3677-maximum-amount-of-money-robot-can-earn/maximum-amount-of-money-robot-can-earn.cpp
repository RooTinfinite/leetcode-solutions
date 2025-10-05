class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size(); 
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, -1'000'000'000))); 
        dp[0][0][2] = coins[0][0]; 
        if (coins[0][0] < 0) dp[0][0][1] = 0; 
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k <= 2; ++k) {
                    if (i) dp[i][j][k] = max({dp[i][j][k], dp[i-1][j][k] + coins[i][j], dp[i-1][j][k+1]}); 
                    if (j) dp[i][j][k] = max({dp[i][j][k], dp[i][j-1][k] + coins[i][j], dp[i][j-1][k+1]}); 
                }
        return *max_element(dp[m-1][n-1].begin(), dp[m-1][n-1].end()); 
    }
};