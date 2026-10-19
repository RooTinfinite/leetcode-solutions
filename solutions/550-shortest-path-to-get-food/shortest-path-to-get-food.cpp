class Solution {
private:
    // Possible moves: right, left, up, down
    const vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

public:
    int getFood(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Find starting position marked as '*'
        vector<int> start = {-1, -1};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '*') {
                    start[0] = i;
                    start[1] = j;
                    break;
                }
            }
        }

        // BFS queue for level-by-level traversal
        queue<vector<int>> queue;
        queue.push(start);
        int steps = 1;

        // BFS traversal
        while (!queue.empty()) {
            int levelSize = queue.size();

            // Process all cells at current level
            while (levelSize-- > 0) {
                vector<int> pos = queue.front();
                queue.pop();

                // Try all four directions
                for (auto& d : dir) {
                    int newRow = d[0] + pos[0];
                    int newCol = d[1] + pos[1];

                    if (isValid(grid, newRow, newCol)) {
                        // Found food
                        if (grid[newRow][newCol] == '#') return steps;

                        // Mark as visited and add to queue
                        grid[newRow][newCol] = 'X';
                        queue.push({newRow, newCol});
                    }
                }
            }
            steps++;
        }

        // No path found to food
        return -1;
    }

private:
    // Check if position is within bounds and not blocked
    bool isValid(vector<vector<char>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < grid.size() &&
               col < grid[0].size() && grid[row][col] != 'X';
    }
};