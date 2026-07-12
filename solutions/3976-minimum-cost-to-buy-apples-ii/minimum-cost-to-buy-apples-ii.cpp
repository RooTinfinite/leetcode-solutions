class Solution {
private:
    using ll = long long;
    
    vector<ll> dijkstra(int src, vector<vector<pair<int,ll>>> &adj) {
        int n = adj.size();
        
        vector<ll> dist(n, INT_MAX);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        pq.emplace(0, src);
        dist[src] = 0;

        while(!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto &it : adj[node]) {
                auto [adjNode, edgeWt] = it;
                if(dis + edgeWt < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWt;
                    pq.emplace(dist[adjNode], adjNode);
                }
            }
        }

        return dist;
    }
    
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<pair<int,ll>>> adjFree(n);
        vector<vector<pair<int,ll>>> adjWithTax(n);

        for(auto &it : roads) {
            int u = it[0], v = it[1];
            ll cost = it[2], tax = it[3];

            adjFree[u].emplace_back(v, cost);
            adjFree[v].emplace_back(u, cost);

            adjWithTax[u].emplace_back(v, cost * tax);
            adjWithTax[v].emplace_back(u, cost * tax);
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            vector<ll> distFree = dijkstra(i, adjFree);
            vector<ll> distWithTax = dijkstra(i, adjWithTax);

            ll mini = prices[i]; // local shop

            // buy from any other shop
            for(int j = 0; j < n; j++) {
                // skip unreachable nodes
                if(distFree[j] == INT_MAX || distWithTax[j] == INT_MAX) continue;

                // go + buy + return
                ll totalCost = distFree[j] + prices[j] + distWithTax[j]; 
                mini = min(mini, totalCost);
            }

            ans[i] = (int)mini;
        }

        return ans;
    }
};