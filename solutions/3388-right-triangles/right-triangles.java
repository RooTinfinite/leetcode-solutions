class Solution {
    public long numberOfRightTriangles(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        long count = 0;

        int[] rowCount = new int[row];
        int[] colCount = new int[col];
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == 1){
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == 1){
                    count += (long) (rowCount[i]-1)*(colCount[j]-1);
                }
            }
        }
        return count;
    }
}