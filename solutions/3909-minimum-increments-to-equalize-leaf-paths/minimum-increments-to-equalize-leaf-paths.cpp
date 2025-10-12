class Solution {
public:
    // DFS returns max path sum from this node to a leaf
    long long dfs(int node, int parent, int& operations, vector<vector<int>>& adj, vector<int>& cost) {
        long long maxChildSum = 0;
        int childCount = 0, maxCount = 0;

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;

            long long childSum = dfs(neighbor, node, operations, adj, cost);
            if (childSum > maxChildSum) {
                maxChildSum = childSum;
                maxCount = 1;
            } else if (childSum == maxChildSum) {
                maxCount++;
            }
            childCount++;
        }

        operations += (childCount - maxCount);
        return cost[node] + maxChildSum;
    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int operations = 0;
        dfs(0, -1, operations, adj, cost);
        return operations;
    }
};