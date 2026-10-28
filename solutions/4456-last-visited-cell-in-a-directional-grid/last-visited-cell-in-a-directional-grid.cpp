class Solution {
public:
    vector<int> visit(char move, int x, int y) {
        if (move == 'L') {
            y--;
        } else if (move == 'R') {
            y++;
        } else if (move == 'U') {
            x--;
        } else if (move == 'D') {
            x++;
        }

        return {x, y};
    }

    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int currCellX = 0, currCellY = 0;

        while (true) {
            vis[currCellX][currCellY] = 1;

            vector<int> curr = visit(
                grid[currCellX][currCellY],
                currCellX,
                currCellY
            );

            int x = curr[0], y = curr[1];

            if (x < 0 || x >= n ||
                y < 0 || y >= m ||
                vis[x][y]) {
                break;
            }

            currCellX = x;
            currCellY = y;
        }

        return {currCellX, currCellY};
    }
};