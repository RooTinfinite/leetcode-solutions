class Solution {
    public int smallestBalancedIndex(int[] nums) {
        long lsum = 0;
        for (int x : nums) lsum += x;

        long rprod = 1;
        for (int i = nums.length - 1; i >= 0; --i) {
            lsum -= nums[i];  // Update from sum(nums[0..i]) -> sum(nums[0..i-1])
            if (lsum == rprod)  // If match return, since next lsum < cur lsum and next rprod >= cur rprod
                return i;
            if (rprod > lsum / nums[i])  // rprod can only increase, while lsum only decrease, so there no more matches
                break;

            rprod *= nums[i];  // Update from prod(nums[i+1...n-1]) -> prod(nums[i..n-1])
        }

        return -1;
    }
}