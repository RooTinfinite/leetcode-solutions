class Solution {
public:
    long long dp[100001][2][2];
    int n;
    long long memo(int i,int is_start,int take,vector<vector<int>>& a){
        if(i>= n) {
            if(take) return -1e18/4;
            return 0;
        }

        if(dp[i][is_start][take] != -1) return dp[i][is_start][take];
        long long res = memo(i+1,is_start,take,a);
        if(take && is_start && i<n-1) res += (a[i+1][0] - a[i][0]);
        auto idx = lower_bound(a.begin(),a.end(),a[i][1],[](const vector<int> &v, int x){
            return v[0] < x;
        }) - a.begin();

        if(idx < n)
            res = max(res,a[i][2] + (a[idx][0] - a[i][1]) + memo(idx,1,1,a));

        res = max(res,a[i][2] + memo(idx,1,0,a));

        return dp[i][is_start][take] = res;
    }
    long long maxEarnings(vector<vector<int>>& a) {
        memset(dp,-1,sizeof(dp));
        n = a.size();
        sort(a.begin(),a.end());
        return memo(0,0,0,a);
    }
};