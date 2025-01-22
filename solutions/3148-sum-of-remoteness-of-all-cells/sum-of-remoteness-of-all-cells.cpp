class Solution {
    pair<long long, int> dfs(int x, int y, vector<vector<int>>& g) {
        if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y] < 0) {
            return {0, 0};
        }
        const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        pair<long long, int> r = {g[x][y], 1};
        g[x][y] = -1;
        for (int i = 0; i < 4; ++i) {
            const auto& p = dfs(x + dx[i], y + dy[i], g);
            r.first += p.first;
            r.second += p.second;
        }
        return r;
    }
public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        long long s = 0;
        for (const auto& g : grid) {
            for (int x : g) {
                s += max(x, 0);
            }
        }
        long long r = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] > 0) {
                    const auto p = dfs(i, j, grid);
                    r += (s - p.first) * p.second; 
                }
            }
        }
        return r;
    }
};