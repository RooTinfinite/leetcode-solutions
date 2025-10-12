class Solution {
    public boolean canMakeEqual(int[] nums, int k) {
        return check(nums, k, 1) || check(nums, k, -1);
    }

    static boolean check(int[] nums, int k, int tar) {
        int n = nums.length;
        int[] arr = nums.clone();
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] != tar) {
                arr[i] *= -1;
                arr[i + 1] *= -1;
                count++;
                if (count > k) return false;
            }
        }

        return arr[n - 1] == tar;
    }
}