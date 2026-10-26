static const int dirs[5] = {-1, 0, 1, 0, -1};

long long dfs(int** grid, int i, int j, int m, int n) {
    long long sum = grid[i][j];
    grid[i][j] = 0;
    for (int d = 0; d < 4; ++d) {
        int x = i + dirs[d];
        int y = j + dirs[d + 1];
        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0) {
            sum += dfs(grid, x, y, m, n);
        }
    }
    return sum;
}

int countIslands(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] > 0 && dfs(grid, i, j, m, n) % k == 0) {
                ++ans;
            }
        }
    }
    return ans;
}