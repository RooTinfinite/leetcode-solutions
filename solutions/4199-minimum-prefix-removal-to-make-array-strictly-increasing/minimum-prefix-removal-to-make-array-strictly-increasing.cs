public class Solution {
    public int MinimumPrefixLength(int[] nums) {
        int i = nums.Length - 1;
        while (i > 0 && nums[i - 1] < nums[i]) {
            i--;
        }
        return i;
    }
}