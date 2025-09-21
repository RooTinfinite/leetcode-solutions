class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) sort(grid[i].begin(), grid[i].end());
        for(int j = 0; j < grid[0].size(); j++){
            int maximum = -1;
            for(int i = 0;i < grid.size(); i++) maximum = max(maximum, grid[i][j]);
            ans += maximum;
        }
        return ans;
    }
};