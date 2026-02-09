public class Solution {
    public int MaxA(int n) {
       var dp = new int[n + 1];

        for(var i = 1; i <=n; i++){
            dp[i] = Math.Max(dp[i -1] + 1, dp[i]);
            for (var j = i + 2; j <=n ; j++ ){
                dp[j] = Math.Max(dp[j], dp[i - 1] * (j - i));
            }
        }
        return dp[n]     ;
    }
}