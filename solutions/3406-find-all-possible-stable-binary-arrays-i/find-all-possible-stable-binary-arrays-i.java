class Solution {
    int mod = 1000000007;

    public int numberOfStableArrays(int zero, int one, int limit) {
        long[][][] dp = new long[zero+1][one+1][2];
        boolean[][][] vis = new boolean[zero+1][one+1][2];
        long res = (helper(vis, dp, zero, one, limit, 0) + helper(vis, dp, zero, one, limit, 1)) % mod;
        return (int)res;
    }
    
    public long helper(boolean[][][] vis, long[][][] dp, int zero, int one, int limit, int curr) {
        if(zero == 0 && one == 0) return 1;

        if(vis[zero][one][curr]) return dp[zero][one][curr];
        vis[zero][one][curr] = true;
        long res = 0;

        if(curr == 1) {
            for(int i = 1; i <= limit && i<=one; i++) {
                res += helper(vis, dp, zero, one - i, limit, 0) % mod;
            }
        }else {
            for(int i = 1; i <= limit && i <= zero; i++) {
                res += helper(vis, dp, zero - i, one, limit, 1) % mod;
            }
        }

        dp[zero][one][curr] = res;
        return res;
    }
}