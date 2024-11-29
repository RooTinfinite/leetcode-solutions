using info = pair<int, int>; // (time, position)
const static int d[5] = {0, 1, 0, -1, 0};

class Solution {
    template<typename T>
    struct Grid {
        vector<T> data;
        int m;
        
        Grid(int n, int m, T init): data(n * m, init), m(m) {}
        T& operator()(int i, int j) { return data[i * m + j]; }
        const T& operator()(int i, int j) const { return data[i * m + j]; }
    };
    
    static bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

public:
    int minimumTime(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        
        // Early exit check
        if (grid[1][0] > 1 && grid[0][1] > 1) return -1;
        
        // Initialize distance grid
        Grid<int> dist(n, m, INT_MAX);
        dist(0, 0) = 0;
        
        // Priority queue for Dijkstra
        priority_queue<info, vector<info>, greater<>> pq;
        pq.emplace(0, 0);
        
        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();
            
            int i = pos / m, j = pos % m;
            
            // Skip if we found a better path already
            if (time > dist(i, j)) continue;
            
            if (i == n-1 && j == m-1) return time;
            
            for (int k = 0; k < 4; k++) {
                int ni = i + d[k];
                int nj = j + d[k+1];
                
                if (!isValid(ni, nj, n, m)) continue;
                
                // Calculate minimum time needed to move to next cell
                int w = ((grid[ni][nj] - time) & 1) ? 0 : 1;
                int nextTime = max(time + 1, grid[ni][nj] + w);
                
                if (nextTime < dist(ni, nj)) {
                    dist(ni, nj) = nextTime;
                    pq.emplace(nextTime, ni * m + nj);
                }
            }
        }
        
        return -1;
    }
};
