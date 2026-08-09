using ll = long long;

class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        ll ops = 0, res = k;

        for (ll x : nums) {
            if (res < x) {
                ll add = (x - res + k - 1) / k;
                ops += add;
                res += add * k;
            }
            res -= x;
        }

        const ll MOD = 1e9 + 7;

        if (ops % 2 == 0)
            return ((ops / 2) % MOD) * ((ops + 1) % MOD) % MOD;

        return (ops % MOD) * (((ops + 1) / 2) % MOD) % MOD;
    }
};