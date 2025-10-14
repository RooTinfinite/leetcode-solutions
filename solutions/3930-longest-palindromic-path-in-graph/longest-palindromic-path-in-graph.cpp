class Solution {
public:
    bool dp[1 << 15][15][15];

    int maxLen(int n, vector<vector<int>>& edg, string lab) {

        vector<vector<int>> adj(n);
        for (auto it : edg) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int fmask = (1 << n) - 1;
        int ans = 1;

        for (int mask = 1; mask <= fmask; mask++) {

            if (__builtin_popcount(mask) == 1) {
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        dp[mask][i][i] = true;
                        for (int u : adj[i]) {
                            if (lab[u] == lab[i]) {
                                int nmask = mask | (1 << u);
                                dp[nmask][i][u] = true;
                            }
                        }
                        break;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (!dp[mask][i][j])
                        continue;
                    ans = max(ans, __builtin_popcount(mask));

                    for (int u : adj[i]) {
                        for (int v : adj[j]) {
                            if (lab[u] == lab[v] && u != v) {
                                if (((mask >> u) & 1) || ((mask >> v) & 1))
                                    continue;
                                int nmask = mask | (1 << u) | (1 << v);
                                dp[nmask][u][v] = true;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};