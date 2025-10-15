class Solution {
public:
    int earliestFinishTime(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        int ans = INT_MAX;
        // take land first

        int n = a.size();
        int minEnd = INT_MAX;
        for (int i = 0; i < n; i++) {
            minEnd = min(minEnd, a[i] + b[i]);
        }
        int m = c.size();

        for (int i = 0; i < m; i++) {
            ans = min(ans, d[i] + max(minEnd, c[i]));
        }

        // take water first;
        minEnd = INT_MAX;
        for (int i = 0; i < m; i++) {
            minEnd = min(minEnd, c[i] + d[i]);
        }

        for (int i = 0; i < n; i++) {
            ans = min(ans, b[i] + max(minEnd, a[i]));
        }

        return ans;
    }
};