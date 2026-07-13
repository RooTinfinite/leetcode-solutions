class Solution {
public:
    int dp[1000][1501];
    vector<int> free;
    int mini, n;
    
    int solve(int i, int tot, vector<vector<int>>& items) {
        if(i>=items.size()) return tot/mini;
        if(dp[i][tot]!=-1) return dp[i][tot];

        int take=0;
        if(tot>=items[i][1]) {
            take=free[i]+solve(i+1, tot-items[i][1], items);
        }

        int skip=solve(i+1, tot, items);
        return dp[i][tot]=max(take, skip);
    }
    
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        mini=INT_MAX, n=items.size();
        free.resize(n, 0);

        for(int i=0; i<n; i++) {
            mini=min(mini, items[i][1]);
            for(int j=0; j<n; j++) {
                if(items[j][0]%items[i][0] == 0) free[i]++;
            }
        }

        memset(dp, -1, sizeof(dp));
        return solve(0, budget, items);
    }
};