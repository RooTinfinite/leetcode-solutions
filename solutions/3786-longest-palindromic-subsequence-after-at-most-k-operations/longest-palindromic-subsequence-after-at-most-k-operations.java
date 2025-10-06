import java.util.Arrays;

class Solution {
    static int[][][] dp = new int[200][200][201];
    static int n;

    public int longestPalindromicSubsequence(String a, int k) {
        char[] s = a.toCharArray();
        n = s.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int p = 0; p <= k; p++) {
                    dp[i][j][p] = -1;
                }
            }
        }
        
        return f(s,0,n-1,k);
    }

    int f(char[] s, int i, int j, int k){
        if(i > j)return 0;
        if(i == j)return 1;
        if(dp[i][j][k] != -1)return dp[i][j][k];
        int ans = 0;
        if(s[i]==s[j])ans = 2+f(s, i+1,j-1,k);
        else {
            ans = Math.max(f(s,i+1,j,k),f(s,i,j-1,k));
            int dist = Math.abs(s[j]-s[i]);
            dist = Math.min(dist, 26-dist);
            if(k >= dist)ans = Math.max(ans, 2+f(s,i+1,j-1,k-dist));
        }
        dp[i][j][k] = ans;
        return ans;
    }
}