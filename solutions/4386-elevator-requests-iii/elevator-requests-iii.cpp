class Solution {
public:
    long long solve(int mask, int last, int start, int n,
        vector<vector<int>>& req,
        vector<vector<long long>>& dp
    ) {
        // Remove the last request
        int prevMask = mask ^ (1 << last);

        // Base case:
        // last is the first request
        if(prevMask == 0) {
            long long time = abs(start - req[last][1]);
            // Cannot complete before req[last][0]
            time = max(time, (long long)req[last][0]);
            return dp[mask][last] = time;
        }

        // Already calculated
        if(dp[mask][last] != -1) return dp[mask][last];

        long long curRes = LLONG_MAX;

        // Try every possible previous request
        for(int i = 0; i < n; i++) {
            // Request i must be present
            // in the previous mask
            if(!(prevMask & (1 << i))) continue;

            // Minimum time to complete
            // prevMask and finish at i
            long long prevTime =solve(prevMask, i, start, n, req, dp);

            // Travel from request i to request last
            long long travel = abs(req[i][1] -req[last][1]);

            // We may have to wait until
            // request last becomes available
            long long time = prevTime + travel;
            time = max(time, (long long)req[last][0]);

            // Choose the best previous request
            curRes = min(curRes, time);
        }
        return dp[mask][last] = curRes;
    }

    long long elevatorRequests(int n, int start,
        vector<vector<int>>& req
    ) {

        int m = req.size();

        // dp[mask][last]
        vector<vector<long long>> dp(1 << m,
            vector<long long>(m, -1)
        );

        // Mask with all requests completed
        int full = (1 << m) - 1;

        long long res = LLONG_MAX;
        // Any request can be the final request
        for(int i = 0; i < m; i++) {
            res = min(res, solve(full, i, start, m, req, dp));
        }
        return res;
    }
};