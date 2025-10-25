import java.util.*;

class Solution {
    public long minOperations(int[] nums1, int[] nums2) {
        int n = nums1.length;
        long ops = 0;
        int append = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int high = Math.max(nums2[i], nums1[i]);
            int low = Math.min(nums2[i], nums1[i]);

            if (low <= nums2[n] && nums2[n] <= high) {
                append = 0;
            } else {
                append = Math.min(append, Math.abs(high - nums2[n]));
                append = Math.min(append, Math.abs(low - nums2[n]));
            }

            ops += Math.abs(nums2[i] - nums1[i]);
        }

        return ops + append + 1;
    }
}
