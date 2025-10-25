#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        auto kernel = [&](long long x) -> long long {
            long long res = 1;
            for (long long p = 2; p * p <= x; ++p) {
                int odd = 0;
                while (x % p == 0) {
                    x /= p;
                    odd ^= 1;
                }
                if (odd) res *= p;
            }
            if (x > 1) res *= x;
            return res;
        };

        vector<long long> k(n);
        for (int i = 0; i < n; ++i) k[i] = kernel(nums[i]);

        unordered_map<long long,int> freq;
        long long ans = 0;

        function<void(int,int)> dfs = [&](int u, int p) {
            long long ku = k[u];
            ans += freq[ku];
            freq[ku]++;

            for (int v : g[u]) if (v != p) dfs(v, u);

            if (--freq[ku] == 0) freq.erase(ku);
        };

        dfs(0, -1);
        return ans;
    }
};