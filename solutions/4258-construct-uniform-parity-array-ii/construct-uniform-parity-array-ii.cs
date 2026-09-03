public class Solution {
    public bool UniformArray(int[] nums1) {
        int mn = nums1[0];
        bool hasOdd = false;
        foreach (int v in nums1) {
            if (v < mn) {
                mn = v;
            }
            if ((v & 1) == 1) {
                hasOdd = true;
            }
        }
        if ((mn & 1) == 1) {
            return true;
        }
        return !hasOdd;
    }
}