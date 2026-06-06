class Solution {
    static final long neg_inf = Long.MIN_VALUE/4;
    
    public long f(int[] nums1, int[] nums2, int ind1, int ind2, int k, long[][][] dp) {
        if(k == 0) return 0;
        if(ind1 >= nums1.length || ind2 >= nums2.length) {
            return neg_inf;
        }
        if(dp[ind1][ind2][k] != Long.MIN_VALUE) return dp[ind1][ind2][k];
        
        long pick = f(nums1, nums2, ind1+1, ind2+1, k-1, dp);
        if(pick != neg_inf) {
            pick += (long)nums1[ind1]*(long)nums2[ind2];
        }
        
        long notPick = Math.max(f(nums1, nums2, ind1+1, ind2, k, dp), f(nums1, nums2, ind1, ind2+1, k, dp));
        return dp[ind1][ind2][k] = Math.max(pick, notPick);
    }
    public long maxScore(int[] nums1, int[] nums2, int k) {
        long[][][] dp = new long[nums1.length][nums2.length][k+1];
        for(long[][] mat: dp) {
            for(long[] row: mat) Arrays.fill(row, Long.MIN_VALUE);
        }
        long ans = f(nums1, nums2, 0, 0, k, dp);

        return ans;
    }
}