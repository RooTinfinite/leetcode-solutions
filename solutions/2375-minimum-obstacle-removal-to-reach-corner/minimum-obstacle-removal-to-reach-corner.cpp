using int3 = tuple<int, int, int>; // (dist, i, j)
const static int d[5] = {0, 1, 0, -1, 0};
class Solution {
public:
    inline static bool isOutside(int i, int j, int n, int m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    static int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<int3, vector<int3>, greater<int3>> pq;

        pq.emplace(0, 0, 0);
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto [currD, i, j] = pq.top();
            pq.pop();

            // reach the target
            if (i == n - 1 && j == m - 1)
                return currD;

            // Traverse all four directions
            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (isOutside(r, s, n, m))
                    continue;

                // minimum distance to reach (r, s)
                int nextD = grid[r][s] + currD;

                // update if this path having shorter distance
                if (nextD < dist[r][s]) {
                    dist[r][s] = nextD;
                    pq.emplace(nextD, r, s);
                }
            }
        }
        return -1; // never reach
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();