class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> grid(n+1, vector<int>(n+1, 1000));
        
        for(int j = 1; j < n; j++) {
            grid[j][j+1] = 1;
            grid[j+1][j] = 1;
        }
        grid[x][y] = 1;
        grid[y][x] = 1;
        
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {              
                   grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);                
                }
            }
        }
        
        vector<int> result(n);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {

                if(i != j) {
                    int val = grid[i][j];
                    result[val-1]++;
                }

            }
        }
        
        return result;
        
    }
};