class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), base = 31, mod = 1e9+7;
        unordered_map<int, int> map;
        for (auto& row: matrix) {
            long long h1 = 0, h2 = 0;
            for (int i: row) {
                h1 = (h1*base+(i == 0))%mod;
                h2 = (h2*base+(i == 1))%mod;
            }
            map[h1]++;
            map[h2]++;
        }

        int ans = 0;
        for (auto& it: map) {
            ans = max(ans, it.second);
        }
        return ans;
    }
};