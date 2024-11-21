class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> g(m, vector<int>(n, 0));
        
        // Mark guards and walls as 2
        for (const auto& guard : guards) {
            g[guard[0]][guard[1]] = 2;
        }
        for (const auto& wall : walls) {
            g[wall[0]][wall[1]] = 2;
        }
        
        // Directions: up, right, down, left
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        // Process each guard's line of sight
        for (const auto& guard : guards) {
            for (const auto& dir : dirs) {
                int x = guard[0], y = guard[1];
                while (true) {
                    x += dir.first;
                    y += dir.second;
                    if (x < 0 || x >= m || y < 0 || y >= n || g[x][y] == 2) {
                        break;
                    }
                    g[x][y] = 1;
                }
            }
        }
        
        // Count unguarded cells (cells with value 0)
        int ans = 0;
        for (const auto& row : g) {
            ans += count(row.begin(), row.end(), 0);
        }
        return ans;
    }
};
