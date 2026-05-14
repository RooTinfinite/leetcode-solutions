public class Solution {
    public bool IsGood(int[] nums) {
        int n = nums.Length;
        int[] count = new int[n];
        foreach (int a in nums) {
            if (a < 1 || a >= n) {
                return false;
            }
            if (a < n - 1 && count[a] > 0) {
                return false;
            }
            if (a == n - 1 && count[a] > 1) {
                return false;
            }
            count[a]++;
        }
        return true;
    }
}