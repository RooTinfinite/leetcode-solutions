public class Solution {
    public int[][] RotateGrid(int[][] grid, int k) {
        int m = grid.Length;
        int n = grid[0].Length;
        int nlayer = Math.Min(m / 2, n / 2);  // level count
        // enumerate each layer counterclockwise starting from the top-left
        // corner
        for (int layer = 0; layer < nlayer; ++layer) {
            List<int> r = new List<int>();
            List<int> c = new List<int>();
            List<int> val = new List<int>();  // each element's row index,
                                              // column index, and value
            for (int i = layer; i < m - layer - 1; ++i) {  // left
                r.Add(i);
                c.Add(layer);
                val.Add(grid[i][layer]);
            }
            for (int j = layer; j < n - layer - 1; ++j) {  // down
                r.Add(m - layer - 1);
                c.Add(j);
                val.Add(grid[m - layer - 1][j]);
            }
            for (int i = m - layer - 1; i > layer; --i) {  // right
                r.Add(i);
                c.Add(n - layer - 1);
                val.Add(grid[i][n - layer - 1]);
            }
            for (int j = n - layer - 1; j > layer; --j) {  // up
                r.Add(layer);
                c.Add(j);
                val.Add(grid[layer][j]);
            }
            int total = val.Count;  // total number of elements in each layer
            int kk = k % total;     // equivalent number of rotations
            // find the value at each index after rotation
            for (int i = 0; i < total; ++i) {
                int idx =
                    (i + total - kk) % total;  // the index corresponding to the
                                               // value after rotation
                grid[r[i]][c[i]] = val[idx];
            }
        }
        return grid;
    }
}