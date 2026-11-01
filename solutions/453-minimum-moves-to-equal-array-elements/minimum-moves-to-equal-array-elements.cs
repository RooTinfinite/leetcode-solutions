public class Solution {
    public int MinMoves(int[] nums) {
        int sum = 0, min = int.MaxValue;
        foreach (int x in nums) {
            sum += x;
            min = Math.Min(min, x);
        }
        return sum - nums.Length * min;
    }
}