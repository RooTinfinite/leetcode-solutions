public class Solution {
    public long CountFairPairs(int[] nums, int lower, int upper) {
        Array.Sort(nums);
        return CountPairs(nums, upper) - CountPairs(nums, lower - 1);
    }
    
    private long CountPairs(int[] nums, int target) {
        long count = 0;
        int left = 0, right = nums.Length - 1;
        
        while (left < right) {
            if (nums[left] + nums[right] > target) right--;
            else {
                count += right - left;
                left++;
            }
        }
        return count;
    }
}
