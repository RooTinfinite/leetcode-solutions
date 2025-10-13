class GCDSparseTable {
private:
    vector<vector<int>> st;
    vector<int> logVal;
    int n;

public:
    GCDSparseTable(const vector<int>& a) {
        n = a.size();
        int maxLog = 32 - __builtin_clz(n);
        st.assign(n, vector<int>(maxLog));
        logVal.assign(n + 1, 0);

        for (int i = 2; i <= n; i++)
            logVal[i] = logVal[i / 2] + 1;

        for (int i = 0; i < n; i++)
            st[i][0] = a[i];

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int getGCD(int l, int r) {
        int j = logVal[r - l + 1];
        return __gcd(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

class Solution {
public:
    vector<int> a;
    int n, maxC;

    bool canBreak(int maxLen, GCDSparseTable& st) {
        int changes = 0, l = 0;

        for (int r = 0; r < n; r++) {
            int g = st.getGCD(l, r);

            while (l + 1 <= r && g == 1) {
                l++;
                g = st.getGCD(l, r);
            }

            if (r - l + 1 > maxLen) {
                l = r + 1;
                changes++;
            }
        }
        return changes <= maxC;
    }

    int minStable(vector<int>& nums, int _maxC) {
        a = nums;
        n = a.size();
        maxC = _maxC;

        if (count(a.begin(), a.end(), 1) + maxC >= n) return 0;

        GCDSparseTable st(a);
        int l = 0, r = n + 1;

        while (r > l + 1) {
            int mid = (l + r) / 2;
            if (canBreak(mid, st)) r = mid;
            else l = mid;
        }
        return r;
    }
};