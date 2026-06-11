class Solution {
public:
    long long rob(vector<int>& a, vector<int>& col) {
        int n = a.size();
        long long dp0 = 0, dp1 = a[0], new0 = 0, new1 = 0;

        for (int i = 1; i < n; i++) {
            if (col[i] == col[i-1]) {
                new1 = dp0 + a[i];
                new0 = max(dp0, dp1);
            }
            else {
                new0 = max(dp0, dp1);
                new1 = max(dp0, dp1) + a[i];
            }
            dp0 = new0, dp1 = new1;
        }
        return max(dp0, dp1);
    }
};