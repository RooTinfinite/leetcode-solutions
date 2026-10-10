class Solution {

    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n = nums1.length;
        int k = k1 + k2;
        int maxDif = 0;
        for (int i = 0; i < n; i++) {
            nums1[i] = Math.abs(nums1[i] - nums2[i]);
            maxDif = Math.max(maxDif, nums1[i]);
        }

        int l = 0,
            r = maxDif,
            res = 0;
        while (l <= r) {
            int mid = (l + r) >>> 1;
            long sum = 0;
            for (int num : nums1) {
                sum += num > mid ? num - mid : 0;
            }
            if (sum <= k) {
                r = mid - 1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }

        for (int num : nums1) {
            if (num > res) {
                k -= num - res;
            }
        }

        Arrays.sort(nums1);
        long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            long diff = Math.min(nums1[i], res);
            if (k > 0 && diff > 0) {
                diff--;
                k--;
            }
            ans += diff * diff;
        }
        return ans;
    }
}