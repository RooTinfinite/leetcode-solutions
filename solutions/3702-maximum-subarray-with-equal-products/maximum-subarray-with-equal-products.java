class Solution {
    public int maxLength(int[] nums) {
        int n = nums.length;
        int maxLen = 1;
        for(int i = 0; i < n; i++) {
            int pro = nums[i];
            int gcd = nums[i];
            int lcm = nums[i];
            for(int j = i + 1; j < n; j++) {
                gcd = GCD(gcd, nums[j]);
                pro *= nums[j];
                lcm = LCM(lcm, nums[j]);
                if(lcm * gcd == pro) {
                    maxLen = Math.max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
    public static int LCM(int a, int b) {
        return (a * b) / GCD(a, b);
    }
    static int GCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}