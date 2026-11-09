class Solution {
public:
    vector<vector<char>> finalGrid(vector<vector<char>>& grid) {
        const vector<vector<int>> dirs = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

        const int rowCnt = grid.size();
        const int colCnt = grid[0].size();
        const int rowCntM1 = rowCnt - 1;
        const int colCntM1 = colCnt - 1;

        vector<vector<char>> result(rowCnt, vector<char>(colCnt, '-'));
        vector<int> lastBomb(colCnt, -1);
        vector<vector<int>> exploding;
        int bombCnt = 0;
        int boxCnt = 0;
        for (int r = 0; r < rowCnt; r++) {
            const vector<char> &row = grid[r];
            vector<char> &resultRow = result[r];
            for (int c = 0; c < colCnt; c++) {
                const int ch = row[c];
                if (ch == '*') {
                    lastBomb[c] = r;
                    resultRow[c] = '*';
                    bombCnt++;
                    if ((c > 0 && row[c - 1] == '#') || (c < colCntM1 && row[c + 1] == '#') || 
                                (r > 0 && grid[r - 1][c] == '#') || (r < rowCntM1 && grid[r + 1][c] == '#')) {
                        exploding.push_back(vector<int>{r, c});
                    }
                } else if (ch == '#') {
                    boxCnt++;
                }
            }
        }

        if (boxCnt == 0)
            return grid;

        if (bombCnt == 0) {
            vector<int> staticCnts(colCnt, 0);
            for (int r = 0; r < rowCnt; r++) {
                vector<char> &row = grid[r];
                for (int c = 0; c < colCnt; c++) {
                    if (row[c] == '#') {
                        staticCnts[c]++;
                        row[c] = '-';
                    }
                }
            }
            for (int c = 0; c < colCnt; c++)
                for (int r = rowCnt - staticCnts[c]; r < rowCnt; r++)
                    grid[r][c] = '#';
            return grid;
        }

        for (vector<int> &rc : exploding) {
            const int r = rc[0];
            const int c = rc[1];
            for (const vector<int> &delta : dirs) {
                const int xr = r + delta[0];
                const int xc = c + delta[1];
                if (xr >= 0 && xr < rowCnt && xc >= 0 && xc < colCnt && grid[xr][xc] == '#')
                    grid[xr][xc] = '-';
            }
        }

        vector<int> lastExplodable(colCnt);
        for (int c = 0; c < colCnt; c++) {
            int r = lastBomb[c];
            if (c > 0 && lastBomb[c - 1] > r)  r = lastBomb[c - 1];
            if (c < colCntM1 && lastBomb[c + 1] > r)  r = lastBomb[c + 1];
            lastExplodable[c] = r;
        }

        for (int c = 0; c < colCnt; c++) {
            int staticBoxes = 0;
            for (int r = lastExplodable[c] + 1; r < rowCnt; r++)
                if (grid[r][c] == '#')
                    staticBoxes++;

            int topStaticR = rowCnt - staticBoxes;
            if (staticBoxes > 0 && topStaticR > 1 && 
                        ((c > 0 && topStaticR == lastBomb[c - 1] + 1) || 
                         (c < colCntM1 && topStaticR == lastBomb[c + 1] + 1))) {
                int left = c;
                int right = c;
                if (c > 0 && topStaticR == lastBomb[c - 1] + 1)  left = max(0, c - 2);
                if (c < colCntM1 && topStaticR == lastBomb[c + 1] + 1)  right = min(colCntM1, c + 2);
                bool explosion = false;
                for (int cTst = left; cTst <= right; cTst++) {
                    for (int r = topStaticR - 2; r >= 0; r--) {
                        if (grid[r][cTst] == '#') {
                            explosion = true;
                            break;
                        }
                        if (result[r][cTst] == '*' || (cTst > 0 && result[r][cTst - 1] == '*') || 
                                    (cTst < colCntM1 && result[r][cTst + 1] == '*'))
                            break;
                    }
                    if (explosion)  break;
                }
                if (explosion)  topStaticR++;
            }

            for (int r = topStaticR; r < rowCnt; r++) 
                result[r][c] = '#';
        }

        return result;
    }
};