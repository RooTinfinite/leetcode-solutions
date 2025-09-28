class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols= grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i-1>=0){
                    if(grid[i][j]!=grid[i-1][j]){
                        return false;
                    }
                }
                else if(j+1<cols){
                    if(grid[i][j] == grid[i][j+1]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};