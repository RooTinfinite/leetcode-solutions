class Solution {
    public int findValueOfPartition(int[] nums) {
        Arrays.sort(nums);

        int result = nums[1] - nums[0];
        int n = nums.length;

        for (int i = 2; i < n; i++)
            result = Math.min(result, nums[i] - nums[i - 1]);

        return result;
    }
}