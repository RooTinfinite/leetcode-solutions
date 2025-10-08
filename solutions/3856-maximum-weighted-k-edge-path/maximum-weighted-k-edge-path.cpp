class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        // Build adjacency list for DAG
        vector<vector<pair<int, int>>> adj(n);
        for(auto& e : edges) adj[e[0]].push_back({e[1], e[2]});

        vector<vector<set<int>>> dp(n, vector<set<int>>(k + 1));

        // Base Case
        for(int u = 0; u < n; u++) dp[u][0].insert(0);

        for(int e = 0; e < k; e++){
            for(int u = 0; u < n; u++){
                for(auto& [v, wt] : adj[u]){
                    for(auto& w : dp[u][e]){
                        int new_w = w + wt;
                        if(new_w < t) dp[v][e + 1].insert(new_w);
                    }
                }
            }
        }

        // Find the maximum weight across all nodes that used exactly k edges
        int ans = -1;
        for(int u = 0; u < n; u++){
            if(!dp[u][k].empty()) 
                ans = max(ans, *prev(dp[u][k].end()));
        }
        return ans;
    }
};