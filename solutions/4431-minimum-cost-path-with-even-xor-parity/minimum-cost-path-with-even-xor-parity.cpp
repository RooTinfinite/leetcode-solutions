#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int parity(int val) {
        return __builtin_popcount(val) % 2;
    }

    int minActivationCost(vector<vector<int>>& edges,
                          vector<int>& values) {

        int ans = INT_MAX;
        int n = values.size();

        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        queue<pair<int, int>> q;
        q.push({0, -1});

        while (!q.empty()) {

            auto [node, par] = q.front();
            q.pop();

            int odd1 = INT_MAX;
            int odd2 = INT_MAX;
            int even = INT_MAX;

            for (auto &[adjNode, w] : adj[node]) {

                int p = parity(values[adjNode]);

                if (p == 1) {
                    if (w < odd1) {
                        odd2 = odd1;
                        odd1 = w;
                    }
                    else if (w < odd2) {
                        odd2 = w;
                    }
                }
                else {
                    even = min(even, w);
                }

                if (adjNode != par) {
                    q.push({adjNode, node});
                }
            }

            int p = parity(values[node]);

            if (p == 0) {

                // One adjacent even-parity node
                if (even != INT_MAX) {
                    ans = min(ans, even);
                }

                // Two adjacent odd-parity nodes
                if (odd2 != INT_MAX) {
                    ans = min(ans, odd1 + odd2);
                }
            }
            else {

                // One adjacent odd-parity node
                if (odd1 != INT_MAX) {
                    ans = min(ans, odd1);
                }
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};