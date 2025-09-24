class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size(), L = logs.size();
        vector<pair<int,int>> qs(m);
        for (int i = 0; i < m; ++i) qs[i] = {queries[i], i};
        sort(logs.begin(), logs.end(), [](vector<int> &a, vector<int> &b) { 
            return a[1] < b[1]; 
        });
        sort(qs.begin(), qs.end());
        vector<int> freq(n + 1, 0), res(m , 0);
        int active = 0, l = 0, r = 0;
        for (int i = 0; i < m; ++i) {
            int t = qs[i].first, idx = qs[i].second; 
            while (r < L && logs[r][1] <= t) {
                if (++freq[logs[r][0]] == 1) ++active;
                ++r;
            }
            while (l < L && logs[l][1] < t - x) {
                if (--freq[logs[l][0]] == 0) --active;
                ++l;
            }
            res[idx] = n - active;
        }
        return res;
    }
};