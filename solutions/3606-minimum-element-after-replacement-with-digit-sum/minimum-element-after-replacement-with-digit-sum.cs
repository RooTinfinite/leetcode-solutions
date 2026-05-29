public class Solution {
    public int MinElement(int[] nums) {
        int ans = 37;
        foreach (int num in nums) {
            int dig = 0;
            int n = num;
            while (n > 0) {
                dig += n % 10;
                n /= 10;
            }
            ans = Math.Min(ans, dig);
        }
        return ans;
    }
}