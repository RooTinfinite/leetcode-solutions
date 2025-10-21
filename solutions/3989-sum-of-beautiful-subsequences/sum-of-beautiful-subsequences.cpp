#define ll long long
const int MOD = 1000000007;

struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int n_) { n = n_; f.assign(n + 1, 0); }

    void update(int i, int val) {
        ++i;
        while (i <= n) {
            int tmp = f[i] + val;
            if (tmp >= MOD) tmp -= MOD;
            f[i] = tmp;
            i += i & -i;
        }
    }

    int pref(int i) const {
        if (i < 0) return 0;
        ++i;
        ll s = 0;
        while (i > 0) {
            s += f[i];
            i -= i & -i;
        }
        return (int)(s % MOD);
    }

    int range(int l, int r) const {
        if (r < l) return 0;
        int res = pref(r) - (l ? pref(l - 1) : 0);
        if (res < 0) res += MOD;
        return res;
    }
};

class Solution {
public:
    int totalBeauty(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());


        vector<int> uniq = nums;
        sort(uniq.begin(), uniq.end());
        uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
        int U = uniq.size();
        vector<int> rank(mx + 1, -1); 
        for (int i = 0; i < U; ++i) rank[uniq[i]] = i;


        vector<vector<int>> divisors(mx + 1);
        for (int i = 1; i <= mx; ++i)
            for (int j = i; j <= mx; j += i)
                divisors[j].push_back(i);


        vector<vector<int>> multiples_in_nums(mx + 1);
        for (int x : nums) {
            int r = rank[x];
            for (int d : divisors[x]) multiples_in_nums[d].push_back(r);
        }

        Fenwick ft(U);

        vector<int> cnt(mx + 1, 0);
        ll ans = 0;

        vector<int> touched;
        touched.reserve(1024);

        for (int g = mx; g >= 1; --g) {
            auto &v = multiples_in_nums[g];
            if (v.empty()) { cnt[g] = 0; continue; }

            touched.clear();
            touched.reserve(v.size());


            for (int pos : v) {
                int less = (pos == 0 ? 0 : ft.range(0, pos - 1));
                int add = less + 1;
                if (add >= MOD) add -= MOD;
                ft.update(pos, add);
                touched.push_back(pos);
            }

            int total = ft.range(0, U - 1);
            cnt[g] = total;

            for (int gg = 2 * g; gg <= mx; gg += g) {
                cnt[g] -= cnt[gg];
                if (cnt[g] < 0) cnt[g] += MOD;
            }

            ans += ( (ll)g * (ll)cnt[g] ) % MOD;
            ans %= MOD;

            sort(touched.begin(), touched.end());
            touched.erase(unique(touched.begin(), touched.end()), touched.end());
            for (int pos : touched) {
                int cur = ft.range(pos, pos);
                if (cur) {
                    int neg = (MOD - cur) % MOD;
                    ft.update(pos, neg); 
                }
            }
        }

        return (int)ans;
    }
};