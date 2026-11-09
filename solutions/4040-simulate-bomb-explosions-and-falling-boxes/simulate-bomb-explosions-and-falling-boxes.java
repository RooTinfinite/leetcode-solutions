class Solution {
    static final int[][] dirs = new int[][]{{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

    public char[][] finalGrid(char[][] grid) {
        int rowCnt = grid.length;
        int colCnt = grid[0].length;
        int rowCntM1 = rowCnt - 1;
        int colCntM1 = colCnt - 1;

        boolean boxFound = false;
        boolean bombFound = false;
        for (char[] row : grid) {  
            for (int ch : row) {
                if (ch == '#') {
                    boxFound = true;
                    if (bombFound)  break;
                }
                if (ch == '*') {
                    bombFound = true;
                    if (boxFound)  break;
                }
            }
        }
        
        if (!boxFound)
            return grid;

        if (!bombFound) {
            int[] staticCnts = new int[colCnt];
            for (int r = 0; r < rowCnt; r++) {
                char[] row = grid[r];
                for (int c = 0; c < colCnt; c++) {
                    if (row[c] == '#') {
                        staticCnts[c]++;
                        grid[r][c] = '-';
                    }
                }
            }
            for (int c = 0; c < colCnt; c++)
                for (int r = rowCnt - staticCnts[c]; r < rowCnt; r++)
                    grid[r][c] = '#';
            return grid;
        }

        char[][] result = new char[rowCnt][colCnt];
        int[] lastBomb = new int[colCnt];
        for (int c = lastBomb.length - 1; c >= 0; c--)  lastBomb[c] = -1;
        List<Pair<Integer,Integer>> exploding = new ArrayList();
        for (int r = 0; r < rowCnt; r++) {
            char[] row = grid[r];
            char[] resultRow = result[r];
            for (int c = 0; c < colCnt; c++) {
                if (row[c] == '*') {
                    lastBomb[c] = r;
                    resultRow[c] = '*';
                    if ((c > 0 && row[c - 1] == '#') || (c < colCntM1 && row[c + 1] == '#') || 
                                (r > 0 && grid[r - 1][c] == '#') || (r < rowCntM1 && grid[r + 1][c] == '#'))
                        exploding.add(new Pair(r, c));
                } else {
                    resultRow[c] = '-';
                }
            }
        }

        for (Pair rc : exploding) {
            int r = (int)rc.getKey();
            int c = (int)rc.getValue();
            for (int[] delta : dirs) {
                int xr = r + delta[0];
                int xc = c + delta[1];
                if (xr >= 0 && xr < rowCnt && xc >= 0 && xc < colCnt && grid[xr][xc] == '#')
                    grid[xr][xc] = '-';
            }
        }

        int[] lastExplodable = new int[colCnt];
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
                if (c > 0 && topStaticR == lastBomb[c - 1] + 1)  left = Math.max(0, c - 2);
                if (c < colCntM1 && topStaticR == lastBomb[c + 1] + 1)  right = Math.min(colCntM1, c + 2);
                boolean explosion = false;
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
}