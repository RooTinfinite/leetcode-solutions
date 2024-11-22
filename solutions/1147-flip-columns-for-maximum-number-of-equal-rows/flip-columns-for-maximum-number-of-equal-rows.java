class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String, Integer> patterns = new HashMap<>();
        int maxCount = 0;
        
        for (int[] row : matrix) {
            StringBuilder pattern = new StringBuilder();
            int firstBit = row[0];
            
            for (int bit : row) {
                pattern.append(bit == firstBit ? '1' : '0');
            }
            
            int count = patterns.merge(pattern.toString(), 1, Integer::sum);
            maxCount = Math.max(maxCount, count);
        }
        
        return maxCount;
    }
}