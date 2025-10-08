class Solution {
public:
    vector<vector<int>> specialGrid(int N) {
        vector<vector<int>> grid(1 << N, vector<int>(1 << N));
        for (int i = 0 ; i  < N ; i++) {
            for (int j = 0 ; j < (1 << N) ; j++)
                for (int k = 0 ; k < (1 << N) ; k++) {
                int temp = (j >> i) % 2;
                int y = (k >> i) % 2;
                if (temp == 0) {
                        // Upper half
                        grid[j][k] += (y == 0 ? 3 : 0) << (2 * i);
                        // 3: top-left, 0: top-right
                    } else {
                        // Lower half
                        grid[j][k] += (y == 0 ? 2 : 1) << (2 * i);
                        // 2: bottom-left, 1: bottom-right
                    }
                }
            }
        return grid;
    }
};