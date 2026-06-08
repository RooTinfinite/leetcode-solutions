class Solution {
    public int[] delayedCount(int[] nums, int k) {
        int max = 0;
        for(int num : nums) max = Math.max(max, num);
        int[] freq = new int[max + 1];
        
        int[] ans = new int[nums.length];
        for(int i = nums.length - 2 - k; i >= 0; i--) {
            freq[nums[i + k + 1]]++;
            ans[i] = freq[nums[i]];
        }
        return ans;
    }
}