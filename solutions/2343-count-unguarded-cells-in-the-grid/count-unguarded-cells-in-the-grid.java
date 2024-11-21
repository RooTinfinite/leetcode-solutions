class Solution {
    private static final byte EMPTY = 0;
    private static final byte GUARDED = 1;
    private static final byte BLOCKED = 2;
    
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        // Use byte array for better memory efficiency
        byte[][] grid = new byte[m][n];
        int total = m * n;
        int blocked = guards.length + walls.length;
        
        if (blocked == total) return 0;
        
        // Process walls and guards in parallel streams for better performance
        Arrays.stream(walls).parallel().forEach(w -> grid[w[0]][w[1]] = BLOCKED);
        Arrays.stream(guards).parallel().forEach(g -> grid[g[0]][g[1]] = BLOCKED);
        
        // Pre-calculate array bounds
        final int lastRow = m - 1;
        final int lastCol = n - 1;
        
        // Process guards sight lines
        for (int[] guard : guards) {
            int row = guard[0], col = guard[1];
            
            // Optimize line of sight checks with direct array access
            // Left
            for (int j = col - 1; j >= 0 && grid[row][j] != BLOCKED; j--) {
                grid[row][j] = GUARDED;
            }
            // Right
            for (int j = col + 1; j <= lastCol && grid[row][j] != BLOCKED; j++) {
                grid[row][j] = GUARDED;
            }
            // Up
            for (int i = row - 1; i >= 0 && grid[i][col] != BLOCKED; i--) {
                grid[i][col] = GUARDED;
            }
            // Down
            for (int i = row + 1; i <= lastRow && grid[i][col] != BLOCKED; i++) {
                grid[i][col] = GUARDED;
            }
        }
        
        // Count unguarded cells using parallel stream
        return (int) IntStream.range(0, m)
            .parallel()
            .mapToLong(i -> IntStream.range(0, n)
                .filter(j -> grid[i][j] == EMPTY)
                .count())
            .sum();
    }
}

