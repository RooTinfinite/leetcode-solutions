class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<string, int> map;
        int maxCount = 0;
        
        for (const auto& row : matrix) {
            string pattern(m, '0');
            int firstBit = row[0];
            
            for (int j = 0; j < m; j++) {
                if (row[j] != firstBit) {
                    pattern[j] = '1';
                }
            }
            
            maxCount = max(maxCount, ++map[pattern]);
        }
        
        return maxCount;
    }
};