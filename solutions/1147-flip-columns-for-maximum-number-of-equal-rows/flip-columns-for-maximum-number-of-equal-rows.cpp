class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        const int r = matrix.size(), c = matrix[0].size();
        unordered_map<bitset<300>, int, hash<bitset<300>>> mp;
        mp.reserve(r);
        bitset<300> pattern;

        for (const auto& row : matrix) {
            pattern.reset();
            const bool term0 = row[0];
            for (int j = 0; j < c; ++j) 
                pattern[j] = row[j] ^ term0;
            ++mp[pattern];
        }

        int max_rows = 0;
        for (const auto& [_, count] : mp)
            max_rows = std::max(max_rows, count);

        return max_rows;
    }
};