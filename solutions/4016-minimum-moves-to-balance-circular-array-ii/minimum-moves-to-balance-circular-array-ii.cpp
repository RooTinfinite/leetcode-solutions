class Solution {
public:
    struct Edge {
        int to;
        long long cap;
        long long cost;
        int rev;
        Edge(int _to, long long _cap, long long _cost, int _rev)
            : to(_to), cap(_cap), cost(_cost), rev(_rev) {}
    };

    struct MinCostFlow {
        int N;
        vector<vector<Edge>> G;
        vector<long long> dist, potential;
        vector<int> pv_v, pv_e;

        MinCostFlow(int n): N(n), G(n), dist(n), potential(n), pv_v(n), pv_e(n) {}

        void addEdge(int u, int v, long long cap, long long cost) {
            G[u].emplace_back(v, cap, cost, (int)G[v].size());
            G[v].emplace_back(u, 0, -cost, (int)G[u].size()-1);
        }

        pair<long long,long long> minCostMaxFlow(int s, int t, long long maxf = LLONG_MAX) {
            long long flow = 0, cost = 0;
            const long long INF = (1LL<<60);
            fill(potential.begin(), potential.end(), 0);

            while (flow < maxf) {
                priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
                fill(dist.begin(), dist.end(), INF);
                dist[s] = 0;
                pq.emplace(0, s);

                while (!pq.empty()) {
                    auto [d,u] = pq.top(); pq.pop();
                    if (d != dist[u]) continue;
                    for (int ei = 0; ei < (int)G[u].size(); ++ei) {
                        Edge &e = G[u][ei];
                        if (e.cap <= 0) continue;
                        long long nd = dist[u] + e.cost + potential[u] - potential[e.to];
                        if (nd < dist[e.to]) {
                            dist[e.to] = nd;
                            pv_v[e.to] = u;
                            pv_e[e.to] = ei;
                            pq.emplace(nd, e.to);
                        }
                    }
                }

                if (dist[t] == INF) break;

                for (int i = 0; i < N; ++i) {
                    if (dist[i] < INF) potential[i] += dist[i];
                }

                long long addf = maxf - flow;
                int v = t;
                while (v != s) {
                    Edge &e = G[pv_v[v]][pv_e[v]];
                    addf = min(addf, e.cap);
                    v = pv_v[v];
                }

                v = t;
                while (v != s) {
                    Edge &e = G[pv_v[v]][pv_e[v]];
                    Edge &rev = G[v][e.rev];
                    e.cap -= addf;
                    rev.cap += addf;
                    v = pv_v[v];
                }

                long long addcost = potential[t] - potential[s];
                flow += addf;
                cost += addf * addcost;
            }

            return {flow, cost};
        }
    };

    long long minMoves(vector<int>& bal) {
        int n = (int)bal.size();
        long long total = 0;
        for (int x : bal) total += x;
        if (total < 0) return -1;

        int S = n, T = n + 1;
        MinCostFlow mcf(n + 2);

        const long long INF_CAP = (1LL << 50);

        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            mcf.addEdge(i, j, INF_CAP, 1);
            mcf.addEdge(j, i, INF_CAP, 1);
        }

        long long demandSum = 0;
        for (int i = 0; i < n; ++i) {
            if (bal[i] > 0) {
                mcf.addEdge(S, i, bal[i], 0);
            } else if (bal[i] < 0) {
                mcf.addEdge(i, T, -1LL * bal[i], 0);
                demandSum += -1LL * bal[i];
            }
        }

        auto res = mcf.minCostMaxFlow(S, T, demandSum);
        if (res.first < demandSum) return -1;
        return res.second;
    }
};