class Solution {
    public long maxTotal(int[] nums, String s) {
        int n = nums.length;
        long ans = 0;
        long mini = Integer.MAX_VALUE;
        for(int i = n - 1; i >= 0; i--) {
            if(s.charAt(i) == '1') {
                // current value can be covered
                ans += nums[i];
                // smallest value in current block
                mini = Math.min(mini, nums[i]);
            } else {
                // a token from i+1 can move here
                if(i + 1 < n && s.charAt(i + 1) == '1') {
                    ans += nums[i];
                    // remove the smallest value once
                    mini = Math.min(mini, nums[i]);
                    ans -= mini;
                }
                // start a new block
                mini = Integer.MAX_VALUE;
            }
        }
        return ans;
    }
}