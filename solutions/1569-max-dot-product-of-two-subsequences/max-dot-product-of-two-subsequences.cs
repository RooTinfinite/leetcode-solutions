public class Solution {
    public int MaxDotProduct(int[] nums1, int[] nums2) {
        int m = nums1.Length, n = nums2.Length;
        int[] current = new int[n + 1], previous = new int[n + 1];
        Array.Fill(current, int.MinValue);
        Array.Fill(previous, int.MinValue);

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int curr_product = nums1[i - 1] * nums2[j - 1];
                current[j] = Math.Max(Math.Max(Math.Max(curr_product, previous[j]), current[j - 1]), curr_product + Math.Max(0, previous[j - 1]));
            }
            (current, previous) = (previous, current);
        }
        return previous[n];
    }
}