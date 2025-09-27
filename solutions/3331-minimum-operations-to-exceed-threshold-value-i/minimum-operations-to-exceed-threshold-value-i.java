class Solution {
    public int minOperations(int[] nums, int k) {
        int operation = 0;
        int numsSize = nums.length;
        for (int i = 0 ; i<numsSize;i++) {
            if (nums[i] < k) {
                operation++;
            }
        }
        return operation;
    }
}