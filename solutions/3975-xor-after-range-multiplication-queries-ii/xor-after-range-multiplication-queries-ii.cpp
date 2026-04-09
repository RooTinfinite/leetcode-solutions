typedef long long ll;

class Solution {
public:
    static constexpr long long MOD = (int)(1e9 + 7);

    // fast modular exponentiation: a^e mod m
    long long mod_pow(long long a, long long e, long long m = MOD) {
        a %= m;
        if (a < 0) a += m;
        long long r = 1 % m;
        while (e > 0) {
            if (e & 1) r = (r * a) % m;
            a = (a * a) % m;
            e >>= 1;
        }
        return r;
    }

    // modular inverse: a^{-1} mod m (m must be prime and a != 0 mod m)
    long long mod_inv(long long a, long long m = MOD) {
        a %= m;
        if (a < 0) a += m;
        return mod_pow(a, m - 2, m);
    }

    bool same(vector<int>& q, int k, int lm)
    {
        return q[2] == k && ((q[0] % k) == lm); 
    }

    int xorAfterQueries(vector<int>& nums1, vector<vector<int>>& qs) {
        sort(qs.begin(), qs.end(), [](const vector<int>& a, const vector<int>& b){
            int ka = a[2];
            int kb = b[2];
            if (ka != kb) return ka < kb;
            int la = a[0] % ka;
            int lb = b[0] % kb;
            return la < lb;
        });

        int m = qs.size();
        int i = 0;
        int n = nums1.size();
        vector<ll> nums(n);
        for (int i = 0; i < n; i++) nums[i] = nums1[i];
        vector<ll> dp(n, 1);
        int nq = sqrt(n);

        while (i < m)
        {
            auto& cur = qs[i];
            int k = cur[2];
            if (k > nq)
            {
                for (int j = cur[0]; j <= cur[1]; j += k)
                {
                    nums[j] = nums[j] * (ll)(cur[3]) % MOD;
                }
                i++;
                continue;
            }
            int lm = cur[0] % k;
            int j = i + 1;
           
            while (j < m && same(qs[j], k, lm))
            {
                j++;
            }
            for (int x = i; x < j; x++)
            {
                auto& q = qs[x];
                int l = q[0];
                int r = q[1];
                int v = q[3];
                dp[l] = dp[l] * v % MOD;
                int e = l + ((r - l)/k + 1) * k;
                if (e < n)
                {
                    dp[e] = dp[e] * mod_inv(v) % MOD;
                }
            }
            ll pre = 1;
            for (int x = lm; x < n; x += k)
            {
                dp[x] = dp[x] * pre % MOD;
                pre = dp[x];

                nums[x] = nums[x] * dp[x] % MOD;
                dp[x] = 1;
            }
            i = j;
        }

        ll cur = nums[0];
        for (int i = 1; i < n; i++)
        {
            cur = cur ^ nums[i];
        }
        return cur;

        
    }
};