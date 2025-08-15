class Solution {
    public int sumOfBeauties(int[] nums) {
        int n = nums.length;
        int[] pref = new int[n];
        int[] suf = new int[n];

        pref[0] = nums[0];
        for (int i = 1; i < n - 1; i++) {
            pref[i] = Math.max(pref[i - 1], nums[i]);
        }

        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i > 0; i--) {
            suf[i] = Math.min(suf[i + 1], nums[i]);
        }

        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > pref[i - 1] && nums[i] < suf[i + 1]) {
                res += 2;
            } else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
                res += 1;
            }
        }
        return res;
    }
}