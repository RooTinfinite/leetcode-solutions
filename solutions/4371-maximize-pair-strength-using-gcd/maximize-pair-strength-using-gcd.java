class Solution {
    public long maxPairStrength(int[] nums) {
        long res = 0;

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                long x = gcd(nums[i], nums[j]);
                long strength = (nums[i] / x) * (nums[j] / x);
                if (strength > res)
                    res = strength;
            }
        }

        return res;
    }

    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }
}