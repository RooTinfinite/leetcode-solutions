class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (min(grid[0][1], grid[1][0]) > 1) {
            return -1;
        }
        
        int ROWS = grid.size(), COLS = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        minHeap.push({0, 0, 0}); // {time, r, c}
        set<pair<int, int>> visit;
        
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            int t = curr[0], r = curr[1], c = curr[2];
            
            if (r == ROWS - 1 && c == COLS - 1) {
                return t;
            }
            
            vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nc < 0 || nr == ROWS || nc == COLS || 
                    visit.count({nr, nc})) {
                    continue;
                }
                
                int wait = (abs(grid[nr][nc] - t) % 2 == 0) ? 1 : 0;
                int nTime = max(grid[nr][nc] + wait, t + 1);
                minHeap.push({nTime, nr, nc});
                visit.insert({nr, nc});
            }
        }
        return -1;
    }
};