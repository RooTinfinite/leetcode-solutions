class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int res = 0;
        const int n = mat[0].size();
        unordered_map<string, int> freq;
        string pattern;
        pattern.reserve(n);
        
        for (const auto& row : mat) {
            pattern.clear();
            const int firstBit = row[0];
            
            int i = 0;
            for (; i + 7 < n; i += 8) {
                char packed = 0;
                for (int j = 0; j < 8; j++) {
                    if (row[i + j] != firstBit) {
                        packed |= (1 << j);
                    }
                }
                pattern += packed;
            }
            
            if (i < n) {
                char packed = 0;
                for (int j = 0; i + j < n; j++) {
                    if (row[i + j] != firstBit) {
                        packed |= (1 << j);
                    }
                }
                pattern += packed;
            }
            
            res = max(res, ++freq[pattern]);
        }
        return res;
    }
};