class Solution {
public:
    vector<vector<int>> adj; // Use vector of vectors for dynamic sizing
    int ans;

    int dfs(int node, int parent) {
        int totalNodes = 0;
        bool isGood = true;
        int subtreeSize = -1;

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            int currentSize = dfs(neighbor, node);
            if (subtreeSize == -1) {
                subtreeSize = currentSize;
            } else if (currentSize != subtreeSize) {
                isGood = false;
            }
            totalNodes += currentSize;
        }

        if (isGood) ans++;
        return totalNodes + 1;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        adj.resize(n);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ans = 0;
        dfs(0, -1);
        return ans;
    }
};