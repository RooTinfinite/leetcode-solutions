public class Solution {
    public int MinRemoval(int[] nums, int k) {
        int n = nums.Length;
        Array.Sort(nums);

        int ans = n;
        int right = 0;

        for (int left = 0; left < n; left++) {
            while (right < n && nums[right] <= (long)nums[left] * k) {
                right++;
            }
            ans = Math.Min(ans, n - (right - left));
        }

        return ans;
    }
}