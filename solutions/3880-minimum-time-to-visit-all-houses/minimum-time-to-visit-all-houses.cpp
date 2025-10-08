class Solution {
public:
    long long minTotalTime(vector<int>& forward, vector<int>& backward, vector<int>& queries) {
        int n = forward.size();
        vector<long long> fwd(n+1, 0), bwd(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            fwd[i] = fwd[i-1] + forward[i-1];
            bwd[i] = bwd[i-1] + (i < n ? backward[i] : backward[0]);
        }
        long long res = 0;
        int cur = 0;
        for (int q : queries) {
            int u = cur, v = q;
            long long cw = u <= v
                ? fwd[v] - fwd[u]
                : fwd[n] - (fwd[u] - fwd[v]);
            long long ccw = u >= v
                ? bwd[u] - bwd[v]
                : bwd[n] - (bwd[v] - bwd[u]);
            res += min(cw, ccw);
            cur = v;
        }
        return res;
    }
};