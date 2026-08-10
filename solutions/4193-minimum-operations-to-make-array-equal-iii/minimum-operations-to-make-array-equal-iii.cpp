using ll = long long;

class Solution {
public:
    ll minOperations(vector<int>& nums) {
        map<ll, ll> freq;

        for (int x : nums)
            ++freq[x];

        ll n = nums.size();

        if (freq.size() == 1)
            return 0;

        vector<pair<ll, ll>> values(freq.begin(), freq.end());

        ll m = values.size();
        vector<ll> saving(m);

        for (ll i = 0; i < m; ++i)
            saving[i] = values[i].second << 1;

        for (ll i = 0; i < m; ++i) {
            ll d = values[i].first;
            ll next = d * 2;

            while (next <= values.back().first) {
                auto it = lower_bound(
                    values.begin() + i + 1,
                    values.end(),
                    next,
                    [](const pair<ll, ll>& p, ll value) {
                        return p.first < value;
                    }
                );

                if (it == values.end())
                    break;

                ll j = it - values.begin();
                ll x = it->first;

                if (x % d == 0) {
                    saving[i] += values[j].second;
                    saving[j] += values[i].second;
                    next = x + d;
                } else {
                    next = (x / d + 1) * d;
                }
            }
        }

        ll ans = n;

        for (ll i = 0; i < m; ++i) {
            if (values[i].first == 1)
                continue;

            ans = min(ans, (n << 1) - saving[i]);
        }

        return ans;
    }
};