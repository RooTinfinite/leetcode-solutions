class Solution {
    public string[] CreateGrid(int m, int n) {
        string[] grid = new string[m];
        grid[0] = new string('.', n);
        string row = new string('#', n - 1) + '.';
        for (int i = 1; i < m; i++) {
            grid[i] = row;
        }
        return grid;
    }
}