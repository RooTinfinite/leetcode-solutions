class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans =0;
        function<void(int,int)> dfs = [&] (int i, int j){
            ans = max(ans,j);
            if (ans == n-1){
                return;
            }
            // i-1， i， i + 1
            for (int k = max(i-1,0); k< min(i+2,m);++k) {
                if (grid[k][j+1] > grid[i][j]) {
                    dfs(k,j+1);
                }
            }
            grid[i][j] =0;
        };
        for (int i=0; i< m; ++i) {
            dfs(i,0);
        }
        return ans;
    }
};