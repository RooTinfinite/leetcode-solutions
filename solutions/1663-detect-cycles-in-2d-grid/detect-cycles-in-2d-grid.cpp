class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();             // Number of rows in the grid
        int n = grid[0].size();          // Number of columns in the grid

        // Direction vectors for moving right, down, left, and up
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        // 2D vector to keep track of visited cells
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Iterate through each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the current cell has not been visited
                if (!vis[i][j]) {
                    char target = grid[i][j]; // Character to match for the cycle

                    // Queue for BFS: stores current cell and its parent cell
                    queue<pair<pair<int, int>, pair<int, int>>> q;
                    q.push({{i, j}, {i, j}}); // Initialize with current cell as its own parent
                    vis[i][j] = 1;            // Mark the current cell as visited

                    // Perform BFS
                    while (!q.empty()) {
                        int r = q.front().first.first;     // Current row
                        int c = q.front().first.second;    // Current column
                        int pr = q.front().second.first;   // Parent row
                        int pc = q.front().second.second;  // Parent column
                        q.pop();

                        // Explore all four directions
                        for (int k = 0; k < 4; k++) {
                            int nr = r + dr[k]; // New row
                            int nc = c + dc[k]; // New column

                            // Check if the new position is within bounds and has the same character
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == target) {
                                if (!vis[nr][nc]) {
                                    // If the neighbor has not been visited, mark it and add to the queue
                                    vis[nr][nc] = 1;
                                    q.push({{nr, nc}, {r, c}});
                                } else if (nr != pr || nc != pc) {
                                    // If the neighbor is visited and not the parent, a cycle is detected
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        // No cycle found in the grid
        return false;
    }
};