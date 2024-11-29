class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        
        if (grid[1][0] > 1 && grid[0][1] > 1) {
            return -1;
        }
        
        vector<int> visited(m * n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        const vector<int> directions = {0, -1, 0, 1, 0};
        
        pq.push({0, 0});
        visited[0] = 0;
        
        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();
            
            int row = pos / n;
            int col = pos % n;
            
            if (row == m - 1 && col == n - 1) {
                return time;
            }
            
            for (int i = 0; i < 4; i++) {
                int newRow = row + directions[i];
                int newCol = col + directions[i + 1];
                int newPos = newRow * n + newCol;
                
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || visited[newPos] != -1) {
                    continue;
                }
                
                int newTime;
                if (grid[newRow][newCol] <= time + 1) {
                    newTime = time + 1;
                } else if ((time + 1) % 2 != grid[newRow][newCol] % 2) {
                    newTime = grid[newRow][newCol] + 1;
                } else {
                    newTime = grid[newRow][newCol];
                }
                
                visited[newPos] = newTime;
                pq.push({newTime, newPos});
            }
        }
        
        return -1;
    }
};