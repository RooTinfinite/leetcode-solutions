class Solution {
    public int minOperations(int[] nums, int x) {
        int current = 0;
        for (int num : nums) {
            current += num;
        }
        int n = nums.length;
        int mini = Integer.MAX_VALUE;
        int left = 0;

        for (int right = 0; right < n; right++) {
            // sum([0,..,left) + (right,...,n-1]) = x
            current -= nums[right];
            // if smaller, move `left` to left
            while (current < x && left <= right) {
                current += nums[left];
                left += 1;
            }
            // check if equal
            if (current == x) {
                mini = Math.min(mini, (n-1-right)+left);
            }
        }
        return mini != Integer.MAX_VALUE ? mini : -1;
    }
}