class Solution {
    public long maxProduct(int[] nums) {
        for (int i = 0; i < nums.length; i++) nums[i] = Math.abs(nums[i]);
        int m1 = -100000, m2 = -100000;
        for (int x : nums) {
            if (x > m1) {
                m2 = m1;
                m1 = x;
            } else if (x > m2) {
                m2 = x;
            }
        }
        return (long)m1 * (long)m2 * 100000L;
    }
}