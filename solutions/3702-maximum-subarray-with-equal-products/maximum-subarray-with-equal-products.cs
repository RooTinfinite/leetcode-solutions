public class Solution {
    public int MaxLength(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.Length; i++) {
            long prodVal = nums[i];
            long gcdVal = nums[i];
            long lcmVal = nums[i];
            for (int j = i + 1; j < nums.Length; j++) {
                prodVal = prodVal * nums[j];
                gcdVal = Gcd(gcdVal, nums[j]);
                lcmVal = lcmVal * nums[j] / Gcd(lcmVal, nums[j]);
                if (prodVal > gcdVal * lcmVal) {
                    break;
                }
                if (prodVal == gcdVal * lcmVal) {
                    res = Math.Max(res, j - i + 1);
                }
            }
        }
        return res;
    }

    private long Gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}