public class Solution {
    public int UniqueXorTriplets(int[] nums) {
        int n = nums.Length;
        if (n <= 2) {
            return n;
        }
        int ans = 1;
        while (ans <= n) {
            ans <<= 1;
        }
        return ans;
    }
}