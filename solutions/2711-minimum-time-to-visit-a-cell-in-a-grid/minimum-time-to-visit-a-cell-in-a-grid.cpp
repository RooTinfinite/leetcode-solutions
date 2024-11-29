class Solution {
    static constexpr int d[5] = {0, 1, 0, -1, 0};
    static constexpr int N = 1000;
    
    static inline bool isOutside(int i, int j, int n, int m) {
        return (unsigned)i >= (unsigned)n || (unsigned)j >= (unsigned)m;
    }
    
    static inline int idx(int i, int j, int m) { 
        return i * m + j; 
    }

public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[1][0] > 1 && grid[0][1] > 1)
            return -1;

        const int n = grid.size(), m = grid[0].size();
        vector<int> time(n * m, INT_MAX);
        vector<uint64_t> pq;
        pq.reserve(N);

        pq.push_back(0);
        time[0] = 0;
        
        while (!pq.empty()) {
            pop_heap(pq.begin(), pq.end(), greater<>{});
            uint64_t tij = pq.back();
            pq.pop_back();
            
            const int t = tij >> 32;
            const int ij = tij & 0x3FFFFFFF;
            const int i = ij / m;
            const int j = ij % m;

            if (i == n - 1 && j == m - 1)
                return t;

            for (int k = 0; k < 4; ++k) {
                const int r = i + d[k];
                const int s = j + d[k + 1];
                
                if (isOutside(r, s, n, m))
                    continue;

                const int wait_time = ((grid[r][s] ^ t) & 1) ^ 1;
                const int nextTime = max(t + 1, grid[r][s] + wait_time);
                const int rs = idx(r, s, m);

                if (nextTime < time[rs]) {
                    time[rs] = nextTime;
                    pq.push_back(((uint64_t)nextTime << 32) | rs);
                    push_heap(pq.begin(), pq.end(), greater<>{});
                }
            }
        }
        return -1;
    }
};

static const int fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();