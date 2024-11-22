class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        const int r = matrix.size(), c = matrix[0].size();
        unordered_map<string, int> mp;
        mp.reserve(r);
        
        string pattern;
        pattern.reserve(c);
        
        for (const auto& row : matrix) {
            pattern.clear();
            bool term0 = row[0];
            for (int j = 0; j < c; j++) {
                pattern.push_back('0' + (row[j] ^ term0));
            }
            mp[pattern]++;
        }
        
        int max_rows = 0;
        for (const auto& [key, count] : mp) {
            max_rows = max(max_rows, count);
        }
        
        return max_rows;
    }
};