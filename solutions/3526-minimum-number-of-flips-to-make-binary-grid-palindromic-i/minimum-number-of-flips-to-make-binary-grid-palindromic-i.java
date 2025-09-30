class Solution {
    public int minFlips(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int c = 0;
        for(int i=0;i<m;i++){
            int l=0;
            int h=n-1;
            while(l<h){
                if(grid[i][l]!=grid[i][h]){
                    c+=1;
                }
                l++;
                h--;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int l=0;
            int h=m-1;
            while(l<h){
                if(grid[l][i]!=grid[h][i]){
                    ans+=1;
                }
                l++;
                h--;
            }
        }
        return Math.min(c,ans);
    }
}