class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int ans = 0, p1 = 0, p2 = 0;
        while (p1 < nums1.length && p2 < nums2.length) {
            // If p1 is larger, we should move on to a smaller p1.
            if (nums1[p1] > nums2[p2]) {
                p1++;
            }
            
            // Otherwise, get their distance and move on to a smaller p2.
            else {
                ans = Math.max(ans, p2 - p1);
                p2++;
            }
        }
        
        return ans;
    }
}