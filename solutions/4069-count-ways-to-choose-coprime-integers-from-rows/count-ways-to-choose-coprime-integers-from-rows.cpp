class Solution {
    int n, m;
    const int MOD = 1e9 + 7;

public:
    int fn(vector<vector<int>>& mat, int row, int Gcd, vector<vector<int>>& dp) {
        if (row >= n)return (Gcd == 1);
        if (dp[row][Gcd] != -1) return dp[row][Gcd];

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            int newgcd = gcd(mat[row][i], Gcd);
            ans = (ans + fn(mat, row + 1, newgcd, dp)) % MOD;
        }
        return dp[row][Gcd] = ans;
    }

    int countCoprime(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(151, -1));
        return fn(mat, 0, 0, dp) % MOD;
    }
};