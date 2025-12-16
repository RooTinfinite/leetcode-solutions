class Solution {
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> t(n + 1), a;
        auto u = [&](int i, int d) { for (++i; i <= n; i += i & -i) t[i] += d; };
        auto q = [&](int i) { int r = 0; for (++i; i > 0; i -= i & -i) r += t[i]; return r; };
        auto ok = [&](int i) { return i >= 0 && i < n - 1 && s[i] != s[i + 1]; };
        for (int i = 0; i < n - 1; i++) if (ok(i)) u(i, 1);
        for (auto& v : queries) {
            if (v[0] == 1) {
                int j = v[1], p = ok(j - 1), c = ok(j);
                s[j] ^= 3;
                if (ok(j - 1) != p) u(j - 1, ok(j - 1) - p);
                if (ok(j) != c) u(j, ok(j) - c);
            } else {
                int l = v[1], r = v[2];
                a.push_back((r - l) - (l >= r ? 0 : q(r - 1) - q(l - 1)));
            }
        }
        return a;
    }
};