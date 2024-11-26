class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        const int rows = grid.size();
        const int cols = grid[0].size();
        static const int dx[] = {0, 0, 1, -1};
        static const int dy[] = {1, -1, 0, 0};
        
        vector<vector<bool>> seen(rows, vector<bool>(cols));
        seen[0][0] = true;
        
        using State = pair<int, pair<int, int>>;
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.emplace(0, make_pair(0, 0));
        
        while (!pq.empty()) {
            const int time = pq.top().first;
            const int row = pq.top().second.first;
            const int col = pq.top().second.second;
            pq.pop();
            
            if (row == rows - 1 && col == cols - 1) 
                return time;
            
            for (int i = 0; i < 4; ++i) {
                const int newRow = row + dx[i];
                const int newCol = col + dy[i];
                
                if (unsigned(newRow) < unsigned(rows) && 
                    unsigned(newCol) < unsigned(cols) && 
                    !seen[newRow][newCol]) {
                    
                    int nextTime = max(time + 1, grid[newRow][newCol]);
                    nextTime += (nextTime ^ (time + 1)) & 1;
                    
                    pq.emplace(nextTime, make_pair(newRow, newCol));
                    seen[newRow][newCol] = true;
                }
            }
        }
        return -1;
    }
};