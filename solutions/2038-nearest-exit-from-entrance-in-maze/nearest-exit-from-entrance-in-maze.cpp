class Solution {
public:
    int dirx[4] = { -1, 0, 0, 1 };
    int diry[4] = { 0, 1, -1, 0 };
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<array<int, 3>> q; // {i, j, steps}
        // push the starting point (i, j) with initial step 0
        q.push({entrance[0], entrance[1], 0});
        // BFS
        while (!q.empty()) {
            auto [i, j, steps] = q.front(); q.pop();
            // handle exit condition, we can exit if
            // 1. the current position is not the entrance 
            bool isAtTheEntrance = i == entrance[0] && j == entrance[1];
            // 2. and the current position is at the border
            bool isAtTheBorder = i == 0 || j == 0 || i == m - 1 || j == n - 1;
            if (!isAtTheEntrance && isAtTheBorder) return steps;
            // try for 4 directions
            for (int d = 0; d < 4; d++) {
                int next_i = i + dirx[d];
                int next_j = j + diry[d];
                // check if we can move to (next_i, next_j)
                if (next_i >= 0 && next_j >= 0 && next_i < m && next_j < n && maze[next_i][next_j] == '.') {
                    // if so, we mark the next cell to `+` so that we won't visit it again
                    maze[next_i][next_j] = '+';
                    // add the next position to the queue with steps + 1
                    q.push({next_i, next_j, steps + 1});
                }
            }
        }
        return -1;
    }
};