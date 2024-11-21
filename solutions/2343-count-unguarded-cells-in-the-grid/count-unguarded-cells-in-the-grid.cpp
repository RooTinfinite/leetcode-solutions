class Solution {
private:
    void fill_row(vector<vector<int>>& grid, int row, int col, int m, int n) {
        for (int i = col - 1; i >= 0; i--) {
            if (grid[row][i] == 2) break;
            grid[row][i] = 1;
        }
        
        for (int i = col + 1; i < n; i++) {
            if (grid[row][i] == 2) break;
            grid[row][i] = 1;
        }
        
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 2) break;
            grid[i][col] = 1;
        }
        
        for (int i = row + 1; i < m; i++) {
            if (grid[i][col] == 2) break;
            grid[i][col] = 1;
        }
    }
    
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }
        
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }
        
        for (const auto& guard : guards) {
            fill_row(grid, guard[0], guard[1], m, n);
        }
        
        int count = 0;
        for (const auto& row : grid) {
            count += count_if(row.begin(), row.end(), [](int x) { return x == 0; });
        }
        
        return count;
    }
};
