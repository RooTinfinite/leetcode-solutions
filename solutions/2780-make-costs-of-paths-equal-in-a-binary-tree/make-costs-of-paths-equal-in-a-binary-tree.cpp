class Solution {
public:
    int ans = 0;
    int dfs(int root, vector<int>& cost, int n){
        if(root > n ) return 0;
        int t1 = dfs(root*2, cost, n);
        int t2 = dfs(root*2+1, cost, n);
        ans += abs(t1 - t2);
        return cost[root-1] + max(t1, t2);
    }
    
    int minIncrements(int n, vector<int>& cost) {
        dfs(1, cost, n);
        return ans;
    }
};