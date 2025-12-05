public class Solution {
    public int CountPartitions(int[] nums) {
        int totalSum = 0;
        foreach (int x in nums) {
            totalSum += x;
        }
        return totalSum % 2 == 0 ? nums.Length - 1 : 0;
    }
}