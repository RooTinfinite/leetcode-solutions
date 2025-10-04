class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int operations = 0;  

        for (int col = 0; col < n; col++) {
            for (int row = 1; row < m; row++) {
                if (grid[row][col] <= grid[row - 1][col]) {
                    operations += (grid[row - 1][col] - grid[row][col] + 1);
                    grid[row][col] = grid[row - 1][col] + 1; 
                }
            }
        }
        return operations; 
    }
};