class Solution {
public:
    using ll = long long;

    ll minCost(int m, int n, vector<vector<int>>& penalty) {
        vector<vector<vector<ll>>> dist(m, vector<vector<ll>>(n, vector<ll>(2, LLONG_MAX)));
        priority_queue<tuple<ll,int,int,int>, vector<tuple<ll,int,int,int>>, greater<>> pq;

        dist[0][0][1] = 1;
        pq.emplace(1, 0, 0, 1);

        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        while(!pq.empty()) {
            auto [cost, i, j, parity] = pq.top();
            pq.pop();

            if(cost > dist[i][j][parity]) continue;
            if(i == m-1 && j == n-1) return cost;

            int np = parity ^ 1;

            if(cost + penalty[i][j] < dist[i][j][np]) {
                dist[i][j][np] = cost + penalty[i][j];
                pq.emplace(dist[i][j][np], i, j, np);
            }

            for(int d = 0; d < 4; d++) {
                int nr = i + dr[d];
                int nc = j + dc[d];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                bool ok = parity ? (d < 2) : (d >= 2);
                ll ncost = cost + 1LL * (nr + 1) * (nc + 1) + (ok ? 0 : penalty[i][j]);

                if(ncost < dist[nr][nc][np]) {
                    dist[nr][nc][np] = ncost;
                    pq.emplace(ncost, nr, nc, np);
                }
            }
        }

        return -1;
    }
};