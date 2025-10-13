class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<bool> seen(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> h;
        h.push({0, 0});
        vector<vector<vector<int>>> G(n);
        for (const auto& edge : edges) {
            G[edge[0]].push_back({edge[1], edge[2], edge[3]});
        }
        while (!h.empty()) {
            auto [t, u] = h.top();
            h.pop();
            if (u == n - 1) {
                return t;
            }
            if (seen[u]) continue;
            seen[u] = true;
            for (const auto& edge : G[u]) {
                int v = edge[0], s = edge[1], e = edge[2];
                if (t <= e) {
                    int t2 = max(s, t) + 1;
                    if (!seen[v]) {
                        h.push({t2, v});
                    }
                }
            }
        }
        return -1;
    }
};