class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> g(n);
        g.reserve(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        auto bfs = [&](int start) {
            vector<int> d(n, -1);
            d[start] = 0;
            vector<int> q;
            q.reserve(n);
            q.push_back(start);
            int h = 0;
            while (h < q.size()) {
                int u = q[h++];
                for (int v : g[u]) {
                    if (d[v] == -1) {
                        d[v] = d[u] + 1;
                        q.push_back(v);
                    }
                }
            }
            return d;
        };

        auto dx = bfs(x);
        auto dy = bfs(y);
        auto dz = bfs(z);

        int cc = 0;
        for (int i = 0; i < n; ++i) {
            long long a = dx[i], b = dy[i], c = dz[i];
            long long m = max({a, b, c});
            if (a * a + b * b + c * c == 2 * m * m)  
                cc++;
        }
        return cc;
    }
};