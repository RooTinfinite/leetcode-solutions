#define ll long long
const ll inf = 1e18;
class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int p, vector<int>& cost, int s, int t) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e:edges){
            int u = e[0] , v = e[1] , w = e[2];
            adj[u].push_back({v,w});
        }
        vector<ll> ans(2,-1);
        vector<vector<ll>> dist(n,vector<ll>(p+1,inf));
        // priority queue stores {time, node, remaining power}
        priority_queue<vector<ll> , vector<vector<ll>> , greater<vector<ll>>> pq;
        dist[s][p] = 0;
        pq.push({0,s,p});
        ll best = -1, bestp = -1;
        while(!pq.empty()){
            auto vec = pq.top(); pq.pop();
            ll time = vec[0] , u = vec[1] , remp = vec[2];
            if(time!=dist[u][remp]) continue;
            if(best!=-1 && time>best) break;
            if(u==t){
                if(best==-1) best = time;
                bestp = max(remp,bestp);
                continue;
            }
            if(remp<cost[u]) continue;
            ll nxtp = remp-cost[u];
            for(auto &nei:adj[u]){
                ll v = nei.first , w = nei.second;
                ll ntime = time+w;
                if(ntime<dist[v][nxtp]){
                    dist[v][nxtp] = ntime;
                    pq.push({ntime, v,nxtp});
                }
            }
        }
        ans[0] = best , ans[1] = bestp;
        return ans;
    }
};