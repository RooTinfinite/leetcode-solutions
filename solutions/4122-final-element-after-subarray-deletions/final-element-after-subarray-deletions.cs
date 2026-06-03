public class Solution {
    public int FinalElement(int[] nums) => 
        Math.Max(nums.First(), nums.Last());
}