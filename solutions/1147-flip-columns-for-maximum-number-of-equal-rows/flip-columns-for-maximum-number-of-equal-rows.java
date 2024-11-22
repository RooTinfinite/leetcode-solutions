class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String, Integer> patterns = new HashMap<>();
        int maxCount = 0;
        
        for (int[] row : matrix) {
            char[] pattern = new char[row.length];
            int firstBit = row[0];
            
            for (int j = 0; j < row.length; j++) {
                pattern[j] = (row[j] == firstBit) ? '0' : '1';
            }
            
            String key = new String(pattern);
            maxCount = Math.max(maxCount, patterns.merge(key, 1, Integer::sum));
        }
        
        return maxCount;
    }
}