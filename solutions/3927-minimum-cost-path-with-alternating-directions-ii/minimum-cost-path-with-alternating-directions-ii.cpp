class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& wait) {
        struct Compare {
            bool operator()(const tuple<long long, int, int>& a, const tuple<long long, int, int>& b) {
                return get<0>(a) > get<0>(b); 
            }
        };
        
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, Compare> pq;
        pq.push({1, 0, 0});
        
        vector<vector<long long>> h(m, vector<long long> (n, LLONG_MAX));
        h[0][0] = 1;
        while(!pq.empty()){
            auto [cost, x, y] = pq.top();
            pq.pop();

            if(cost > h[x][y]) continue;
            if(x==m-1 && y==n-1)return cost-wait[0][0];

            int nx = x+1, ny = y;
            if(nx < m && ny < n && h[nx][ny] > cost+wait[x][y]+((nx+1)*(ny+1))){
                h[nx][ny] = cost+wait[x][y]+((nx+1)*(ny+1));
                pq.push({h[nx][ny], nx, ny});
            }
            nx = x, ny = y+1;
            if(nx < m && ny < n && h[nx][ny] > cost+wait[x][y]+((nx+1)*(ny+1))){
                h[nx][ny] = cost+wait[x][y]+((nx+1)*(ny+1));
                pq.push({h[nx][ny], nx, ny});
            }
        }
        return -1;
    }
};