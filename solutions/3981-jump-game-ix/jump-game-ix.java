class Solution {
    public int[] maxValue(int[] nums) {
        int n = nums.length;
        int[] pref = new int[n], suff = new int[n], res = new int[n];
        int max = -1, min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            max = Math.max(max, nums[i]);
            pref[i] = max;
            min = Math.min(min, nums[n - 1 - i]);
            suff[n - 1 - i] = min;
        }


        res[n - 1] = pref[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            res[i] = pref[i];
            if (pref[i] > suff[i + 1]) res[i] = res[i + 1];
        }
        return res;
    }
}