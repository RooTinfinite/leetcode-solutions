class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int n = energy.length;
        int[] dp = new int[n];
        
        int res = Integer.MIN_VALUE;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = energy[i] + (i + k < n ? dp[i + k] : 0);
            res = Math.max(res, dp[i]);
        }
        
        return res;
    }
}