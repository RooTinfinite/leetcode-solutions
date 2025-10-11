class Solution {
    public int[][] minAbsDiff(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int rows = m - k + 1;
        int cols = n - k + 1;
        int[][] ans = new int[rows][cols];

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){

                int[] temp = new int[k*k];
                int index = 0;

                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        temp[index++] = grid[x][y];
                    }
                }

                Arrays.sort(temp);

                int minDiff = Integer.MAX_VALUE;
                for (int l = 1; l < temp.length; l++) {
                    if (temp[l] != temp[l - 1]) { 
                        int diff = temp[l] - temp[l - 1];
                        if (diff < minDiff) {
                            minDiff = diff;
                        }
                    }
                }
                
                if (minDiff == Integer.MAX_VALUE) {
                    minDiff = 0;
                }
                
                ans[i][j] = minDiff;               

            }
        }

        return ans;
    }
}