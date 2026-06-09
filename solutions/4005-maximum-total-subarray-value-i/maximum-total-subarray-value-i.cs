public class Solution {
    public long MaxTotalValue(int[] nums, int k) {
        int m1 = int.MaxValue, m2 = int.MinValue;
        foreach (int x in nums) {
            m1 = Math.Min(m1, x);
            m2 = Math.Max(m2, x);
        }
        return (long)(m2 - m1) * k;
    }
}