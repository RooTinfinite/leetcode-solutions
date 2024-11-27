class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            adj[i].push_back(i + 1);
        }
        
        auto shortest_path = [&]() -> int {
            queue<pair<int, int>> q;
            q.push({0, 0}); // node, length
            unordered_set<int> visit;
            visit.insert(0);
            
            while (!q.empty()) {
                auto [cur, length] = q.front();
                q.pop();
                
                if (cur == n - 1) {
                    return length;
                }
                
                for (int nei : adj[cur]) {
                    if (visit.find(nei) == visit.end()) {
                        q.push({nei, length + 1});
                        visit.insert(nei);
                    }
                }
            }
            return -1;
        };
        
        vector<int> res;
        for (const auto& query : queries) {
            int src = query[0];
            int dst = query[1];
            adj[src].push_back(dst);
            res.push_back(shortest_path());
        }
        
        return res;
    }
};