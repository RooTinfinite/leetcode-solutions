class Solution {
public:
    int solve(vector<int>& pre, vector<int>& suff, int skip,vector<int>&a) {
        int n = a.size();
        for (int i = 1; i <= n; i++) {
            if (i - 1 == skip) {
                pre[i] = pre[i - 1];
                continue;
            }
            pre[i] = gcd(pre[i - 1], a[i - 1]);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == skip) {
                suff[i] = suff[i + 1];
                continue;
            }
            suff[i] = gcd(suff[i + 1], a[i]);
        }
        int curr = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i == skip)
                continue;
            if (pre[i + 1] == suff[i + 1])
                curr++;
        }
        return curr;
    }
    int maxValidSplits(vector<int>& a) {
        int n = a.size(), ans = 0;
        vector<int> premain(n + 1, 0);
        for (int i = 1; i <= n; i++)
            premain[i] = gcd(premain[i - 1], a[i - 1]);
        for (int i = 0; i <= n; i++) {
            if (i > 0 && premain[i] == premain[i - 1])
                continue;
            int skip = i - 1;
            vector<int> pre(n + 1, 0);
            vector<int> suff(n + 1, 0);
            ans = max(ans, solve(pre, suff, i - 1,a));
        }
        return ans;
    }
};