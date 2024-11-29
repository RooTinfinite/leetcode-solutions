class Solution {
    constexpr static int d[5] = {0, 1, 0, -1, 0};
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[1][0] > 1 && grid[0][1] > 1) 
            return -1;
            
        const int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [t, pos] = pq.top();
            pq.pop();
            
            int i = pos / m, j = pos % m;
            if (t > dist[i][j]) continue;
            if (i == n-1 && j == m-1) return t;
            
            for (int k = 0; k < 4; k++) {
                int r = i + d[k], s = j + d[k+1];
                if (r < 0 || r >= n || s < 0 || s >= m) 
                    continue;
                    
                int wait = ((grid[r][s] ^ t) & 1) ^ 1;
                int next = max(t + 1, grid[r][s] + wait);
                
                if (next < dist[r][s]) {
                    dist[r][s] = next;
                    pq.push({next, r * m + s});
                }
            }
        }
        return -1;
    }
};