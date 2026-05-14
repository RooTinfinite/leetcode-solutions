class Solution {

    public boolean isGood(int[] nums) {
        int n = nums.length;
        int[] count = new int[n];
        for (int a : nums) {
            if (a >= n) {
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