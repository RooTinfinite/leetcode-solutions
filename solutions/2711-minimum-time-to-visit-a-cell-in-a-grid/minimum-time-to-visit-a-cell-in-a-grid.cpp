class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        const int rows = grid.size();
        const int cols = grid[0].size();
        const vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));
        seen[0][0] = true;
        
        using State = pair<int, pair<int, int>>;
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, {0, 0}});
        
        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            auto [row, col] = pos;
            pq.pop();
            
            if (row == rows - 1 && col == cols - 1) 
                return time;
            
            for (const auto& [dx, dy] : moves) {
                int newRow = row + dx;
                int newCol = col + dy;
                
                if (newRow >= 0 && newCol >= 0 && 
                    newRow < rows && newCol < cols && 
                    !seen[newRow][newCol]) {
                    
                    int nextTime = max(time + 1, grid[newRow][newCol]);
                    if (nextTime % 2 != (time + 1) % 2) {
                        nextTime++;
                    }
                    
                    pq.push({nextTime, {newRow, newCol}});
                    seen[newRow][newCol] = true;
                }
            }
        }
        return -1;
    }
};