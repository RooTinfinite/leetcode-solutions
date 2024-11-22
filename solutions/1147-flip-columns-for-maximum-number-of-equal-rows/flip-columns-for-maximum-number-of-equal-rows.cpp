class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int res = 0;
        const int n = mat[0].size();
        unordered_map<bitset<300>, int> freq;
		for (auto& row : mat) {
            bitset<300> same;
            same.set(0);
			for (int i = 1; i < row.size(); i++) {
				if (row[0] != row[i]) {
                    same.flip(i);
                }
			}
			freq[same]++;
            res = max(res, freq[same]);
		}
        return res;
    }
};