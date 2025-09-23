class Solution {
    public int maximizeSum(int[] nums, int k) {
        int max = Integer.MIN_VALUE;
        
        // Find the maximum element
        for (int x : nums) {
            max = Math.max(max, x);
        }
        
        int ans = 0;
        
        // Add max and keep incrementing it k times
        while (k-- > 0) {
            ans += max;
            max++;
        }
        
        return ans;
    }
}