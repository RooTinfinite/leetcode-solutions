class Solution {
    static constexpr int d[5] = {0, 1, 0, -1, 0};
    
    static inline bool isOutside(const int i, const int j, const int n, const int m) {
        return (unsigned)i >= (unsigned)n || (unsigned)j >= (unsigned)m;
    }

public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[1][0] > 1 && grid[0][1] > 1)
            return -1;

        const int n = grid.size(), m = grid[0].size();
        const int nm = n * m;
        vector<int> time(nm, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        time[0] = 0;
        pq.emplace(0, 0);
        
        while (!pq.empty()) {
            const auto [t, pos] = pq.top();
            pq.pop();
            
            const int i = pos / m;
            const int j = pos % m;

            if (i == n - 1 && j == m - 1)
                return t;

            for (int k = 0; k < 4; ++k) {
                const int r = i + d[k];
                const int s = j + d[k + 1];
                
                if (isOutside(r, s, n, m))
                    continue;

                const int wait_time = ((grid[r][s] ^ t) & 1) ^ 1;
                const int nextTime = max(t + 1, grid[r][s] + wait_time);
                const int rs = r * m + s;

                if (nextTime < time[rs]) {
                    time[rs] = nextTime;
                    pq.emplace(nextTime, rs);
                }
            }
        }
        return -1;
    }
};

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();