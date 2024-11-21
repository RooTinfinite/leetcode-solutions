class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // Mark obstacles
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }
        
        // Process guards' vision
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        for (const auto& guard : guards) {
            int gx = guard[0], gy = guard[1];
            
            for (const auto& dir : directions) {
                int x = gx, y = gy;
                int dx = dir.first, dy = dir.second;
                
                while (x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && grid[x + dx][y + dy] != 2) {
                    x += dx;
                    y += dy;
                    grid[x][y] = 1;
                }
            }
        }
        
        // Count unguarded cells (value 0)
        int unguarded = 0;
        for (const auto& row : grid) {
            unguarded += count(row.begin(), row.end(), 0);
        }
        
        return unguarded;
    }
};
