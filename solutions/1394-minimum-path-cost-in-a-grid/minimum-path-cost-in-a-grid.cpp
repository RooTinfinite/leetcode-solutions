class Solution {
public:
    using vvi =  vector<vector<int>>;
    vvi grid;
    vvi cost;
    vvi dp;
    int m,n;


    // rec(i,j) => returns the minimum cost of path to (i,j)
    int rec(int i,int j){

        //pruning:
        if(i>=m || i<0 || j<0 || j>=n) return 1e9;

        //base case: 
        if(i==0) return grid[i][j];

        //cache check
        if(dp[i][j]!=-1) return dp[i][j];

        //computations
        int row = i-1;
        int ans = 1e8;

        for(int col=0;col<n;++col){
            int val = grid[row][col];
            int costForComing = cost[val][j];
            ans = min(ans,grid[i][j]+costForComing+rec(row,col));
        }


        //save and return 
        return dp[i][j] = ans;

    }


    int minPathCost(vector<vector<int>>& matrix, vector<vector<int>>& moveCost) {
        
        //globalisation kardi taki bar bar na likhna pade
        grid = move(matrix);
        cost = move(moveCost);
        m = grid.size();
        n = grid[0].size();
        dp = vvi(m+1,vector<int>(n+1,-1));

        //ab last row mein se best select kar lunga
        int ans = INT_MAX;
        int row = m-1;
        for(int col = 0;col<n;++col){
            ans = min(ans,rec(row,col));
        }


        return ans;


        
    }
};