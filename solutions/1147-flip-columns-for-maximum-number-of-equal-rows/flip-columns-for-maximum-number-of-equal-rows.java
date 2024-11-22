class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        Map<String, Integer> patterns = new HashMap<>();
        
        StringBuilder keyBuilder = new StringBuilder(cols);
        
        for (int[] row : matrix) {
            keyBuilder.setLength(0);
            int flip = row[0];
            
            int j = 0;
            for (; j + 3 < cols; j += 4) {
                int val1 = row[j] ^ flip;
                int val2 = row[j + 1] ^ flip;
                int val3 = row[j + 2] ^ flip;
                int val4 = row[j + 3] ^ flip;
                
                keyBuilder.append(val1).append(val2).append(val3).append(val4);
            }
            
            for (; j < cols; j++) {
                keyBuilder.append(row[j] ^ flip);
            }
            
            String key = keyBuilder.toString();
            patterns.merge(key, 1, Integer::sum);
        }
        
        return patterns.values().stream().mapToInt(Integer::intValue).max().orElse(0);
    }
}