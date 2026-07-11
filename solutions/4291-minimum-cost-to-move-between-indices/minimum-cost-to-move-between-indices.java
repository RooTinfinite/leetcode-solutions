class Solution {
    public int[] minCost(int[] nums, int[][] queries) {
        int n = nums.length;
        int len = queries.length;
        long[] pre = new long[n];
        long[] suff = new long[n];

        for (int i = 0; i < n-1; i++) {
            long diffFromRight = (long) nums[i+1] - nums[i];
            long diffFromLeft = (i>0) ?(long) (nums[i]-nums[i-1]) :Long.MAX_VALUE;
            pre[i+1] = pre[i] + (diffFromRight < diffFromLeft ?1 :diffFromRight);
        }

        for (int i = n-1; i > 0; i--) {
            long diffFromLeft = (long) nums[i] - nums[i-1];
            long diffFromRight = (i < n-1) ?(long) nums[i+1]-nums[i] :Long.MAX_VALUE;
            suff[i-1] = suff[i] + (diffFromLeft<=diffFromRight ?1 :diffFromLeft);
        }

        int[] ans = new int[len];
        for (int i = 0; i < len; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            if (l <= r) ans[i] = (int) (pre[r]-pre[l]);
            else ans[i] = (int) (suff[r]-suff[l]);
        }
        return ans;
    }
}