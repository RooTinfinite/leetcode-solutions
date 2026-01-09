class Solution {
public:
    using ll = long long;

    vector<vector<int>> adj;
    vector<ll> dist, subtree_sum, ans;
    vector<int> values;

    void re_rooting(int node, int parent) {
        ans[node] = dist[node];
        for (int v : adj[node]) {
            if (v == parent)
                continue;

            subtree_sum[node] -= subtree_sum[v];
            dist[node] -= (dist[v] + subtree_sum[v]);

            subtree_sum[v] += subtree_sum[node];
            dist[v] += (dist[node] + subtree_sum[node]);

            re_rooting(v, node);

            dist[v] -= (dist[node] + subtree_sum[node]);
            subtree_sum[v] -= subtree_sum[node];

            dist[node] += (dist[v] + subtree_sum[v]);
            subtree_sum[node] += subtree_sum[v];
        }
    }

    void preCompute(int node, int parent) {
        subtree_sum[node] = values[node];
        dist[node] = 0;
        for (int v : adj[node]) {
            if (v == parent)
                continue;
            preCompute(v, node);
            subtree_sum[node] += subtree_sum[v];
            dist[node] += dist[v] + subtree_sum[v];
        }
    }

    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int maxLabel = 0;
        for (int x : group)
            maxLabel = max(maxLabel, x);

        vector<int> present(maxLabel + 1, 0);
        for (int x : group)
            present[x] = 1;

        ll totalAnswer = 0;

        for (int g = 0; g <= maxLabel; g++) {
            if (!present[g])
                continue;

            values.assign(n, 0);
            int cntGroup = 0;
            for (int i = 0; i < n; i++) {
                if (group[i] == g) {
                    values[i] = 1;
                    cntGroup++;
                }
            }
            if (cntGroup <= 1)
                continue;

            dist.assign(n, 0);
            subtree_sum.assign(n, 0);
            ans.assign(n, 0);

            preCompute(0, -1);
            re_rooting(0, -1);

            ll sumDist = 0;
            for (int i = 0; i < n; i++)
                if (values[i])
                    sumDist += ans[i];
            totalAnswer += sumDist / 2;
        }

        return totalAnswer;
    }
};