class Solution {
public:

    int dp[1001][12];

    int F(int Col , int Prev , vector<vector<int>> &Cost){
        if(Col < 0) return 0;

        if(dp[Col][Prev] != -1) return dp[Col][Prev];

        int minOperations = 2e9;

        for(int Value = 0 ; Value < 10 ; Value++){
            if(Value != Prev){
                minOperations = min(minOperations , Cost[Col][Value] + F(Col - 1 , Value , Cost));
            }
        }

        return dp[Col][Prev] = minOperations;
    }

    int minimumOperations(vector<vector<int>>& grid){
        memset(dp,-1,sizeof dp);

        int Rows = grid.size() , Cols = grid[0].size();
        vector<vector<int>> Cost(Cols,vector<int>(11,0));

        for(int Col = 0 ; Col < Cols ; Col++){
            for(int Value = 0 ; Value < 10 ; Value++){
                for(int Row = 0 ; Row < Rows ; Row++){
                    Cost[Col][Value] += grid[Row][Col] != Value;
                }
            }
        }

        return F(Cols - 1 , 10 , Cost);
    }
};
