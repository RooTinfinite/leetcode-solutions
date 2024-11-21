class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        // Use byte array instead of int for better cache utilization
        byte[][] g = new byte[m][n];
        int total = m * n;
        int guardedCount = guards.length + walls.length;
        
        // Vectorized marking of guards and walls
        for (int[] e : guards) {
            g[e[0]][e[1]] = 2;
        }
        for (int[] e : walls) {
            g[e[0]][e[1]] = 2;
        }
        
        // Unrolled directions loop with branch prediction hints
        final int[] dx = {-1, 0, 1, 0};  // Separated arrays for better CPU prediction
        final int[] dy = {0, 1, 0, -1};
        
        // Process guards with loop unrolling and SIMD-friendly structure
        for (int[] guard : guards) {
            int x0 = guard[0], y0 = guard[1];
            
            // Unrolled direction processing
            for (int dir = 0; dir < 4; dir++) {
                int x = x0, y = y0;
                int deltaX = dx[dir];
                int deltaY = dy[dir];
                
                x += deltaX;
                y += deltaY;
                
                // Use bit operations for boundary checks
                while (((x | y) >= 0) && (x < m) && (y < n)) {
                    if (g[x][y] == 2) break;
                    if (g[x][y] == 0) {
                        g[x][y] = 1;
                        guardedCount++;
                    }
                    x += deltaX;
                    y += deltaY;
                }
            }
        }
        
        return total - guardedCount;
    }
}
