class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        Map<String, Integer> map = new HashMap<>();
        int maxCount = 0;
        
        for (int[] row : matrix) {
            StringBuilder normal = new StringBuilder();
            StringBuilder flipped = new StringBuilder();
            
            for (int j = 0; j < m; j++) {
                normal.append(row[j]);
                flipped.append(row[j] ^ 1);
            }
            
            String pattern = normal.toString();
            String flippedPattern = flipped.toString();
            
            if (pattern.compareTo(flippedPattern) > 0) {
                pattern = flippedPattern;
            }
            
            maxCount = Math.max(maxCount, map.merge(pattern, 1, Integer::sum));
        }
        return maxCount;
    }
}