class Solution {
public:
    bool simpleGraphExists(vector<int>& degrees) {
        int n = degrees.size();
        if (n == 0) return true;
        long long sum = 0;
        for (int d : degrees) sum += d;
        if (sum % 2) return false;
        sort(degrees.rbegin(), degrees.rend());
        vector<long long> pre(n + 1);
        for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + degrees[i - 1];
        for (int k = 1; k <= n; ++k) {
            long long left = pre[k];
            long long right = (long long)k * (k - 1);
            int lo = k, hi = n - 1, h = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (degrees[mid] <= k) {
                    h = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if (h == -1) right += (long long)(n - k) * k;
            else right += (long long)(h - k) * k + pre[n] - pre[h];
            if (left > right) return false;
        }
        return true;
    }
};