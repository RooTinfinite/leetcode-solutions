class Solution {
    public int minimumTime(int[][] grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        int rows = grid.length;
        int cols = grid[0].length;
        
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        minHeap.offer(new int[]{0, 0, 0}); // time, row, col
        
        int[][] seen = new int[rows][cols];
        seen[0][0] = 1;
        
        int[][] moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!minHeap.isEmpty()) {
            int[] curr = minHeap.poll();
            int currTime = curr[0];
            int currRow = curr[1];
            int currCol = curr[2];
            
            if (currRow == rows - 1 && currCol == cols - 1) 
                return currTime;
            
            for (int[] move : moves) {
                int nextRow = move[0] + currRow;
                int nextCol = move[1] + currCol;
                
                if (nextRow >= 0 && nextCol >= 0 && 
                    nextRow < rows && nextCol < cols && 
                    seen[nextRow][nextCol] == 0) {
                    
                    int waitTime = ((grid[nextRow][nextCol] - currTime) % 2 == 0) ? 1 : 0;
                    int nextTime = Math.max(currTime + 1, grid[nextRow][nextCol] + waitTime);
                    
                    minHeap.offer(new int[]{nextTime, nextRow, nextCol});
                    seen[nextRow][nextCol] = 1;
                }
            }
        }
        return -1;
    }
}