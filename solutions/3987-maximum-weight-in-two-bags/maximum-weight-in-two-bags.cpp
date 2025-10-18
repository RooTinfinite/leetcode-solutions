class Solution {
public:
    int function(int i, vector<int>& weights, vector<vector<vector<int>>>& dp, int w1, int w2) {
        if (i >= weights.size()){
            return 0;
        }

        if (dp[i][w1][w2] != -1){
            return dp[i][w1][w2];
        }

        int max_val = function(i+1,weights,dp,w1,w2);

        if (w1 >= weights[i]){
            max_val = max(max_val,weights[i] + function(i+1,weights,dp,w1-weights[i],w2));
        }

        if (w2 >= weights[i]){
            max_val = max(max_val,weights[i] + function(i+1,weights,dp,w1,w2-weights[i]));
        }

        return dp[i][w1][w2] = max_val;
    }

    int maxWeight(vector<int>& weights, int w1, int w2) {
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(weights.size(),vector<vector<int>>(w1+1,vector<int>(w2+1,-1)));
        return function(0,weights,dp,w1,w2);
    }
};