class Solution {
    int ans;
    public int countSubmatrices(int[][] grid, int k) {
        int n=grid.length;
        int m=grid[0].length;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                grid[i][j]+=grid[i][j-1];
            }
        }
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=grid[i][j];
                if(sum<=k)count++;
            }
        }
        return count;
    }
}