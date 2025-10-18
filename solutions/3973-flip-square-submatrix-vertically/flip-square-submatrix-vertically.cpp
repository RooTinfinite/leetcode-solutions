class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; i++) {
            int top = x + i;
            int bottom = x + k - 1 - i;
            for (int col = 0; col < k; col++) {
                swap(grid[top][y + col], grid[bottom][y + col]);
            }
        }
        return grid;
    }
};
