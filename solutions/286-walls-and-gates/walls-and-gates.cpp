class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        // you can do a multisource BFS from the gates
        // BFS not DFS since shortest path
        // you simply mark the first time you reach each empty room
        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int dir[4][2] {
            {1, 0},
            {0, 1},
            {-1 , 0},
            {0, -1}
        };

        int t = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                pair<int, int> curr = q.front();
                q.pop();
                if (rooms[curr.first][curr.second] == INT_MAX) {
                    rooms[curr.first][curr.second] = t;
                } else if (rooms[curr.first][curr.second] == -1) {
                    continue;
                } else if (rooms[curr.first][curr.second] != 0) {
                    continue;
                }

                for (auto d : dir) {
                    int nx = curr.first + d[0];
                    int ny = curr.second + d[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        if (rooms[nx][ny] != 0) {
                            q.push({nx, ny});
                        }
                    }
                }
            }
            t++;
        }
    }
};