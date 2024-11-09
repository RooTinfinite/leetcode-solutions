public class Solution {
    public int MaxProfit(int[] nums) {
        int minPro = int.MaxValue;
        int maxPro = 0;
        foreach (int num in nums) {
            minPro = Math.Min(num, minPro);
            maxPro = Math.Max(maxPro, num - minPro);
        }
        return maxPro;
    }
}