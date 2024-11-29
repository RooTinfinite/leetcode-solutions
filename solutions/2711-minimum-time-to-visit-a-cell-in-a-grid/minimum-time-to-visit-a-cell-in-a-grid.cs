public class Solution {
    public int MinimumTime(int[][] grid) {
        if (Math.Min(grid[0][1], grid[1][0]) > 1) {
            return -1;
        }
        
        int ROWS = grid.Length, COLS = grid[0].Length;
        var minHeap = new PriorityQueue<(int t, int r, int c), int>();
        minHeap.Enqueue((0, 0, 0), 0); // (time, r, c)
        var visit = new HashSet<string>();
        
        while (minHeap.Count > 0) {
            var (t, r, c) = minHeap.Dequeue();
            
            if (r == ROWS - 1 && c == COLS - 1) {
                return t;
            }
            
            var dirs = new[] { (1, 0), (-1, 0), (0, 1), (0, -1) };
            foreach (var (dr, dc) in dirs) {
                int nr = r + dr, nc = c + dc;
                string key = $"{nr},{nc}";
                
                if (nr < 0 || nc < 0 || nr == ROWS || nc == COLS || 
                    visit.Contains(key)) {
                    continue;
                }
                
                int wait = (Math.Abs(grid[nr][nc] - t) % 2 == 0) ? 1 : 0;
                int nTime = Math.Max(grid[nr][nc] + wait, t + 1);
                minHeap.Enqueue((nTime, nr, nc), nTime);
                visit.Add(key);
            }
        }
        return -1;
    }
}