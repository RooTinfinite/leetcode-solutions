public class Solution {
    public int CountUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[,] grid = new int[m,n];
        // 0 = free, 1 = guard, 2 = wall, 3 = guardable
        
        foreach (var guard in guards) {
            grid[guard[0], guard[1]] = 1;
        }
        
        foreach (var wall in walls) {
            grid[wall[0], wall[1]] = 2;
        }
        
        void MarkGuarded(int r, int c) {
            for (int row = r + 1; row < m; row++) {
                if (grid[row,c] == 1 || grid[row,c] == 2) break;
                grid[row,c] = 3;
            }
            for (int row = r - 1; row >= 0; row--) {
                if (grid[row,c] == 1 || grid[row,c] == 2) break;
                grid[row,c] = 3;
            }
            for (int col = c + 1; col < n; col++) {
                if (grid[r,col] == 1 || grid[r,col] == 2) break;
                grid[r,col] = 3;
            }
            for (int col = c - 1; col >= 0; col--) {
                if (grid[r,col] == 1 || grid[r,col] == 2) break;
                grid[r,col] = 3;
            }
        }
        
        foreach (var guard in guards) {
            MarkGuarded(guard[0], guard[1]);
        }
        
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i,j] == 0) {
                    result++;
                }
            }
        }
        
        return result;
    }
}