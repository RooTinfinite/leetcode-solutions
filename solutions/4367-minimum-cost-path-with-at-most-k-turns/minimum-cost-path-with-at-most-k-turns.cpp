using ll   = long long;
using pii  = pair<int, int>;
using vi   = vector<int>;
using vl   = vector<ll>;
using vvi  = vector<vector<int>>;

#define pb        push_back
#define all(x)    (x).begin(), (x).end()
#define rall(x)   (x).rbegin(), (x).rend()
#define sz(x)     (int)(x).size()
#define rep(i, n) for (int i = 0; i < (n); ++i)

const int inf  = 1e9;
const ll  linf = 4e18;
const int mod  = 1e9 + 7;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? (a = b, true) : false; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? (a = b, true) : false; }

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = sz(grid), n = sz(grid[0]);
        // state: cell + direction just moved in + turns used
        // may revisit cells, all costs +ve, so dijkstra

        vi cost(m*n*(k+1)*4, inf);
        auto id = [&](int i, int j, int d, int t) -> int {
            return ((i*n + j)*4 + d)*(k+1) + t;
        };
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        priority_queue<pii, vector<pii>, greater<pii>> pq;

        // first move is free of a turn whichever way it goes
        for(int i=0;i<4;i++){
            int s=id(0,0,i,0);
            cost[s]=grid[0][0];
            pq.push({grid[0][0], s});
        }

        while(!pq.empty()){
            auto [cur, pos] = pq.top(); pq.pop();

            if(cur > cost[pos])continue;   // stale entry

            int t=pos%(k+1);
            int rest=pos/(k+1);
            int d=rest%4;
            rest/=4;
            int i=rest/n, j = rest%n;

            if(i==m-1 && j==n-1)return cur;   // first pop of target is the answer

            for(int q=0;q<4;q++){
                int nx=i+dx[q], ny=j+dy[q];
                if(!(nx >=0 && nx < m && ny>=0 && ny<n))continue;

                int nt=t+(q!=d);
                if(nt>k)continue;

                int ns=id(nx, ny, q, nt);
                int nc=cur+grid[nx][ny];

                if(ckmin(cost[ns], nc))pq.push({nc, ns});
            }
        }
        return -1;
    }
};