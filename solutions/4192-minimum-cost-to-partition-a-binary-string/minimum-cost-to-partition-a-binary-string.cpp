class Solution {
public:
    using ll = long long;
    vector<int> pref;
    int encCost, flatCost;

    ll solve(int l, int r) {
        int len = r - l + 1;
        ll ones = pref[r + 1] - pref[l];

        ll ans;
        if (ones == 0) ans = flatCost;
        else ans = 1LL * len * ones * encCost;

        if (len % 2 == 0) {
            int mid = (l + r) >> 1;
            ans = min(ans, solve(l, mid) + solve(mid + 1, r));
        }

        return ans;
    }

    long long minCost(string s, int encCost_, int flatCost_) {
        int n = (int)s.size();
        encCost = encCost_;
        flatCost = flatCost_;

        pref.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (s[i] == '1');
        }

        return solve(0, n - 1);
    }
};