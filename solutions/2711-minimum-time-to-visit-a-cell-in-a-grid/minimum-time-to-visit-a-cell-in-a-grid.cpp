class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        const vector<pair<int,int>> DIRS = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        
        int rows = grid.size(), cols = grid[0].size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));
        
        pq.push({0, 0, 0}); // (time, row, col)
        seen[0][0] = true;
        
        while (!pq.empty()) {
            auto [time, row, col] = pq.top();
            pq.pop();
            
            for (const auto& [dr, dc] : DIRS) {
                int newRow = row + dr;
                int newCol = col + dc;
                
                if (newRow < 0 || newRow >= rows || 
                    newCol < 0 || newCol >= cols || 
                    seen[newRow][newCol]) {
                    continue;
                }
                
                int newTime = time + 1;
                if (grid[newRow][newCol] > newTime) {
                    newTime += ((grid[newRow][newCol] - time) / 2) * 2;
                }
                
                if (newRow == rows - 1 && newCol == cols - 1) {
                    return newTime;
                }
                
                seen[newRow][newCol] = true;
                pq.push({newTime, newRow, newCol});
            }
        }
        
        return -1;
    }
};