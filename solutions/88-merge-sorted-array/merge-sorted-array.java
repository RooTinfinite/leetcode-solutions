class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // Initialize pointers
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;

        // While there are elements in nums2 to process
        while (p2 >= 0) {
            // If nums1 still has elements AND nums1's element is larger
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                // Otherwise take from nums2
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
        // Note: No need to copy remaining elements from nums1 
        // because they are already in place.
    }
}