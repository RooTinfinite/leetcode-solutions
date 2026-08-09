class Solution {
public:
    vector<string> createGrid(int k) {
        int B = 0;
        while ((2 << B) <= k) B++;
        int R = B + 3, C = 2 * B + 1;
        vector<string> g(R, string(C, '#'));
        g[0][0] = '.';
        for (int i = 0; i < B; i++)
            g[i][2*i+1] = g[i+1][2*i] = g[i+1][2*i+1] = g[i+1][2*i+2] = '.';
        int cmin = C - 1;
        for (int i = 0; i <= B; i++)
            if (k >> i & 1) {
                cmin = min(cmin, 2*i);
                for (int r = i + 1; r <= R - 2; r++) g[r][2*i] = '.';
            }
        for (int c = cmin; c < C; c++) g[R-1][c] = '.';
        return g;
    }
};