class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> result(n, vector<int>(n));
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c) {
                int nc = (c - rowShift[r] % n + n) % n;
                int nr = (r - colShift[nc] % n + n) % n;
                result[nr][nc] = grid[r][c];
            }
        return result;
    }
};