public class Solution {
    public int MinimumOperations(int[] nums) {
        return nums.Select(x => { return Math.Min(x % 3, 3 - x % 3); }).Sum();
    }
}