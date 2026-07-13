#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

class Solution {
public:
    vector<int> powerUpdate(vector<int>& nums, int p, vector<vector<int>>& queries) {
        indexed_multiset idx_multiset;
        const int MOD = 1e9 + 7;
        std::vector<int> res;
        for (int x : nums) {
            idx_multiset.insert(x);
        }

        auto modPow = [&] (long long a, long long b) {
            a %= MOD;
            long long exp = 1;
            while (b > 0) {
                if (b % 2 == 1) {
                    exp = exp * a % MOD;
                }
                a = a * a % MOD;
                b /= 2;
            }
            return exp;
        };



        for (std::vector<int> q : queries) {
            int val = q[0], k = q[1];
            idx_multiset.insert(val);
            int n = (int)idx_multiset.size();
            auto ele = idx_multiset.find_by_order(n - k);
            int x = *ele;
            p = modPow(p, x);
            res.push_back(p);
        }
        return res;
    }
};