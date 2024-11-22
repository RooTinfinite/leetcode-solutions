class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        const int r = matrix.size(), c = matrix[0].size();
        unordered_map<bitset<300>, int, hash<bitset<300>>> mp(r);
        bitset<300> pattern;

        for (int i = 0; i < r; i++) {
            const bool term0 = matrix[i][0];
            #pragma unroll
            for (int j = 0; j < c; j++) 
                pattern[j] = matrix[i][j] ^ term0;
            ++mp[pattern];
            pattern.reset();
        }

        int max_rows = 0;
        for (const auto& p : mp)
            max_rows = max_rows < p.second ? p.second : max_rows;

        return max_rows;
    }
};