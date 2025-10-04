class Solution {
    public int maximumMatchingIndices(int[] nums1, int[] nums2) {
        int n = nums2.length;
        int max = 0;
        for (int left = 0; left < n; left++) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (nums2[i] == nums1[(left+i) % n]) {
                    count++;
                }
            }
            max = Math.max(max, count);
        }

        return max;
    }
}