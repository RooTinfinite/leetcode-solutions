class Solution {
    public int FirstStableIndex(int[] nums, int k) {
        int n = nums.Length;
        int[] minValue = new int[n];
        minValue[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minValue[i] = Math.Min(minValue[i + 1], nums[i]);
        }

        int maxValue = 0;
        for (int i = 0; i < n; i++) {
            maxValue = Math.Max(maxValue, nums[i]);
            if (maxValue - minValue[i] <= k) {
                return i;
            }
        }
        return -1;
    }
}