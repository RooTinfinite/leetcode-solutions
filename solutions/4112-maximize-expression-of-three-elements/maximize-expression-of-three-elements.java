class Solution {
    public int maximizeExpressionOfThree(int[] nums) {
        int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE, min1 = Integer.MAX_VALUE;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2) max2 = nums[i];
            if(nums[i] < min1) min1 = nums[i];
        }
        return max1 + max2 - min1;
    }
}