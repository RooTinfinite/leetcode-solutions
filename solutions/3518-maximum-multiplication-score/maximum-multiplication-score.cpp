class Solution {
public:
    long long dp[5][100001];
    long long solve(int i,int j,vector<int>& a, vector<int>& b,int n) {
        if(i==4)
            return 0;
        if(j>=n)
            return -1e11;
        if(dp[i][j]!=-1e11)
            return dp[i][j];
        long long x = (long long)a[i]*b[j]+solve(i+1,j+1,a,b,n);
        long long y = solve(i,j+1,a,b,n);
        if(x>y)
            return dp[i][j]=x;
        return dp[i][j]=y;
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 100001; j++) {
                dp[i][j] = -1e11;
            }
        }
        int n = b.size();
        long long ans = solve(0,0,a,b,n);
        return ans;
    }
};