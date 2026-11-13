class Solution {
public:
    using ll = long long;
    bool repeatedStringMatch(string a, string b, int x, int y) {
        ll n = size(a), m = size(b), an = n * x, bn = m * y;
        if(bn > an) return 0;
        ll need = min(bn, n + m - 1);
        string s, t;
        while(size(s) < n + need - 1)  s += a;
        for(ll i = 0; i < need; i++) t += b[i % m];
        auto position = s.find(t);
        if(position == string::npos) return false;
        ll req = (position + bn + n - 1) / n;
        return req <= x;
    }
};