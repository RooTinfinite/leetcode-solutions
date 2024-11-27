class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n-1; i++) {
            adj[i].push_back(i+1);
        }
        
        vector<int> depth(n);
        for (int i = 0; i < n; i++) {
            depth[i] = i;
        }
        
        auto bfs = [&](int node) {
            queue<int> q;
            q.push(node);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int nei : adj[curr]) {
                    if (depth[nei] > depth[curr] + 1) {
                        depth[nei] = depth[curr] + 1;
                        q.push(nei);
                    }
                }
            }
        };
        
        vector<int> ans;
        for (const auto& query : queries) {
            int s = query[0], e = query[1];
            adj[s].push_back(e);
            if (depth[e] > depth[s] + 1) {
                depth[e] = depth[s] + 1;
                bfs(e);
            }
            ans.push_back(depth[n-1]);
        }
        
        return ans;
    }
};

