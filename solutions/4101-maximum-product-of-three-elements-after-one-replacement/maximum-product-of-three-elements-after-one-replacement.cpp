class Solution {
public:
    using ll = long long;
    long long maxProduct(vector<int>& a) {
        for (int i = 0; i < a.size(); i++) a[i] = (ll)abs(a[i]);
        int m1 = -1e5, m2 = -1e5;
        for (int x : a) {
            if (x > m1) m2 = m1, m1 = x;
            else if (x > m2) m2 = x;
        }
        return (ll)m1 * (ll)m2 * 1e5;
    }
};