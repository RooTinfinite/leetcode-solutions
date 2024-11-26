class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
       int ans=0;
       int n=grid.size();

       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]!=0){
               ans=ans+(grid[i][j]*6 - (grid[i][j]-1)*2);
               }
               if((j+1)<n){
                   ans=ans-(min(grid[i][j],grid[i][j+1]));
               }
               if((i+1)<n){
                   ans=ans-(min(grid[i][j],grid[i+1][j]));
               }
               if(j!=0){
                   ans=ans-(min(grid[i][j],grid[i][j-1]));
               }
               if(i!=0){
                   ans=ans-(min(grid[i][j],grid[i-1][j]));
               }
           }
       }
       return ans;

    }
};