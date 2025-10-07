class Solution {
    public int makeArrayPositive(int[] nums) {
        long[] prefixSum = new long[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if (i == 0) {
                prefixSum[i] = nums[i];
            } else {
                prefixSum[i] = prefixSum[i - 1] + nums[i];
            }
        }

        int count = 0;
        long maxPrefixSum = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            if (prefixSum[i + 2] - maxPrefixSum <= 0) {
                count++;
                maxPrefixSum = prefixSum[i + 2];
                i += 2;
            } else {
                maxPrefixSum = Math.max(maxPrefixSum, prefixSum[i]);
            }
        }
        return count;
    }
}