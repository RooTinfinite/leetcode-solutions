public class Solution {
    public int FirstStableIndex(int[] nums, int k) {
        int n = nums.Length;
        for (int i = 0; i < n; i++) {
            int maxValue = nums[i];
            int minValue = nums[i];
            for (int j = 0; j < i; j++) {
                maxValue = Math.Max(maxValue, nums[j]);
            }
            for (int j = i + 1; j < n; j++) {
                minValue = Math.Min(minValue, nums[j]);
            }
            if (maxValue - minValue <= k) {
                return i;
            }
        }
        return -1;
    }
}