public class Solution {
    public int LongestSubsequence(int[] nums) {
        int n = nums.Length;
        int totalXor = 0;
        bool allZero = true;

        foreach (int x in nums) {
            totalXor ^= x;
            if (x > 0) {
                allZero = false;
            }
        }

        if (totalXor > 0) {
            return n;
        }

        return allZero ? 0 : n - 1;
    }
}