class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        const int r = matrix.size(), c = matrix[0].size();
        unordered_map<bitset<300>, int, hash<bitset<300>>> mp(r);
        bitset<300> pattern;
        int max_rows = 0;

        for (int i = 0; i < r; i++) {
            const bool term0 = matrix[i][0];
            int j = 0;
            
            for (; j + 7 < c; j += 8) {
                unsigned char packed = 0;
                for (int k = 0; k < 8; k++) {
                    if (matrix[i][j + k] ^ term0) {
                        packed |= (1 << k);
                    }
                }
                for (int k = 0; k < 8; k++) {
                    pattern[j + k] = (packed >> k) & 1;
                }
            }
            for (; j < c; j++) {
                pattern[j] = matrix[i][j] ^ term0;
            }
            max_rows = max(max_rows, ++mp[pattern]);
            pattern.reset();
        }
        return max_rows;
    }
};