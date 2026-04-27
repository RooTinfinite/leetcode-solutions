class Solution {

    class DisjointSet {

        int[] f;

        public DisjointSet(int m, int n) {
            f = new int[m * n];
            for (int i = 0; i < m * n; ++i) {
                f[i] = i;
            }
        }

        public int find(int x) {
            return x == f[x] ? x : (f[x] = find(f[x]));
        }

        public void merge(int x, int y) {
            f[find(x)] = find(y);
        }
    }

    int[] patterns = { 0, 0b1010, 0b0101, 0b1100, 0b0110, 0b1001, 0b0011 };
    int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    int[][] grid;
    int m;
    int n;
    DisjointSet ds;

    public boolean hasValidPath(int[][] grid) {
        this.grid = grid;
        m = grid.length;
        n = grid[0].length;
        ds = new DisjointSet(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                handler(i, j);
            }
        }
        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1));
    }

    public int getId(int x, int y) {
        return x * n + y;
    }

    public void handler(int x, int y) {
        int pattern = patterns[grid[x][y]];
        for (int i = 0; i < 4; ++i) {
            if ((pattern & (1 << i)) != 0) {
                int sx = x + dirs[i][0];
                int sy = y + dirs[i][1];
                if (
                    sx >= 0 &&
                    sx < m &&
                    sy >= 0 &&
                    sy < n &&
                    (patterns[grid[sx][sy]] & (1 << ((i + 2) % 4))) != 0
                ) {
                    ds.merge(getId(x, y), getId(sx, sy));
                }
            }
        }
    }
}