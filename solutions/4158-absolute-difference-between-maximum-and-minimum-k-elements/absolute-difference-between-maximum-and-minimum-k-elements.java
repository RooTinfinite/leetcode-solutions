class Solution {
    public int absDifference(int[] nums, int k) {
        Arrays.sort(nums);
        int max_sum = 0, min_sum = 0;
        for(int i = 0, j = nums.length - 1; i < k; i++, j--) {
            min_sum += nums[i];
            max_sum += nums[j];
        }
        return max_sum - min_sum;
    }
}