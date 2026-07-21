#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> adj;
    int K;

    struct State {
        vector<long long>
            normal; 
        vector<long long>
            flipped; 
    };

    pair<vector<long long>, vector<long long>> dfs(int u, int p,
                                                   const vector<int>& nums) {
        vector<long long> dp0(K + 1, -1e15), dp1(K + 1, -1e15);

        dp0[K] = nums[u];
        dp1[K] = -nums[u];

        dp0[0] = -nums[u];
        dp1[0] = nums[u];

        for (int v : adj[u]) {
            if (v == p)
                continue;
            auto [child_dp0, child_dp1] = dfs(v, u, nums);

            vector<long long> next_dp0(K + 1, -1e15);
            vector<long long> next_dp1(K + 1, -1e15);

            // Merge child states into current node states
            // i is the closest inverted distance in u's current accumulated
            // subtree j is the closest inverted distance in v's subtree. In u's
            // view, it becomes j + 1.
            for (int i = 0; i <= K; ++i) {
                for (int j = 0; j <= K; ++j) {
                    int real_j = min(K, j + 1);

                    // Check distance constraint: distance between the two
                    // inverted nodes must be >= K The distance between them is
                    // i + (j + 1)
                    if (i + j + 1 < K)
                        continue;

                    int next_dist = min(i, real_j);

                    // For dp0 (incoming parity to u is 0):
                    // If u itself is NOT inverted (i > 0), the parity passing
                    // down to v remains 0. If u itself IS inverted (i == 0),
                    // the parity passing down to v toggles to 1.
                    long long child_contrib0 =
                        (i == 0) ? child_dp1[j] : child_dp0[j];
                    if (dp0[i] > -1e14 && child_contrib0 > -1e14) {
                        next_dp0[next_dist] =
                            max(next_dp0[next_dist], dp0[i] + child_contrib0);
                    }

                    // For dp1 (incoming parity to u is 1):
                    // If u itself is NOT inverted (i > 0), the parity passing
                    // down to v remains 1. If u itself IS inverted (i == 0),
                    // the parity passing down to v toggles to 0.
                    long long child_contrib1 =
                        (i == 0) ? child_dp0[j] : child_dp1[j];
                    if (dp1[i] > -1e14 && child_contrib1 > -1e14) {
                        next_dp1[next_dist] =
                            max(next_dp1[next_dist], dp1[i] + child_contrib1);
                    }
                }
            }
            dp0 = move(next_dp0);
            dp1 = move(next_dp1);
        }

        return {dp0, dp1};
    }

public:
    int subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums,
                            int k) {
        int n = nums.size();
        K = k;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // At the root (node 0), there is no incoming inversion from above, so
        // incoming parity is 0.
        auto [dp0, dp1] = dfs(0, -1, nums);

        long long max_sum = -1e15;
        for (int i = 0; i <= K; ++i) {
            max_sum = max(max_sum, dp0[i]);
        }

        return (int)max_sum;
    }
};