class Solution {
    void helpIslands(vector<vector<int>>& grid, int i, int j, int m, int n, long long& sum) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }

        sum += grid[i][j];
        grid[i][j] = 0;
        
        helpIslands(grid, i - 1, j, m, n, sum);
        helpIslands(grid, i + 1, j, m, n, sum);
        helpIslands(grid, i, j - 1, m, n, sum);
        helpIslands(grid, i, j + 1, m, n, sum);
    }
    
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int divI = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = 0;
                    helpIslands(grid, i, j, m, n, sum);
                    if(sum % k == 0){
                        divI++;
                    }
                }
            }
        }
        return divI;
    }
};