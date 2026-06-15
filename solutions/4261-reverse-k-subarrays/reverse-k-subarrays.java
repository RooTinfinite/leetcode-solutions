class Solution {
    public int[] reverseSubarrays(int[] nums, int k) {
        if (nums.length < 1 || k < 1)
            return nums;

        int sections = nums.length / k;

        int left = 0;
        int right = 0;

        while (right < nums.length) {
            if (right - left == sections - 1) {
                int tRight = right;
                int tLeft = left;
                while (tRight > tLeft) {
                    int temp = nums[tLeft];
                    nums[tLeft] = nums[tRight];
                    nums[tRight] = temp;
                    tLeft ++;
                    tRight --;
                }

                left = right + 1;
            }

            right++;
        }

        return nums;
    }
}