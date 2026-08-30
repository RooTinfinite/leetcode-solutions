class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        long long INF = 1e18;
        vector<long long> dp(sum + 1, INF);
        dp[0] = 0;
        for (long long x : nums) {
            vector<long long> cost(sum + 1, INF);

            vector<pair<int, int>> options;

            long long curr = x;
            int down = 0;
            while (curr > 0) {

                long long val = curr;
                int up = 0;
                while (val <= sum) {

                    if (cost[val] == INF) {
                        options.push_back({(int)val, down + up});
                    }

                    cost[val] = min(
                        cost[val],
                        (long long)down + up
                    );

                    if (val > sum / 2)
                        break;

                    val *= 2;
                    up++;
                }

                curr /= 2;
                down++;
            }
            vector<long long> next = dp;

            for (int s = 0; s <= sum; s++) {

                if (dp[s] == INF)
                    continue;

                for (auto [value, operations] : options) {

                    if (s + value > sum)
                        continue;

                    next[s + value] = min(
                        next[s + value],
                        dp[s] + operations
                    );
                }
            }

            dp = move(next);
        }
        if(dp[sum] == INF){
            return -1;
        }
        return dp[sum];
    }
};