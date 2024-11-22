class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patterns;
        
        for (const auto& row : matrix) {
            string pattern;
            int first = row[0];
            
            for (int num : row) {
                pattern += (num == first ? '1' : '0');
            }
            patterns[pattern]++;
        }
        
        int maxCount = 0;
        for (const auto& [pattern, count] : patterns) {
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};