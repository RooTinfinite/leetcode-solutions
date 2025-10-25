class Solution {
    public boolean areSimilar(int[][] mat, int k) {
        int rows = mat.length, cols = mat[0].length;
        int result[][] = new int[rows][cols];
        k%=cols;
        for (int i = 0; i < rows; i += 2) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = mat[i][(j+k)%cols];
            }
        }
        for (int i = 1; i < rows; i += 2) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = mat[i][(j-k+cols)%cols];
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(result[i][j]!=mat[i][j])
                    return false;
            }
        }
        return true;
    }
}