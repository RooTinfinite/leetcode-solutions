import java.util.*;
class Solution {
    public long maximumMedianSum(int[] nums) {
        Arrays.sort(nums);
        long ans = 0;
        int n = nums.length;
        for (int i = 0; i < n / 3; i++) {
            ans += nums[n - 2 - 2 * i];
        }
        return ans;
    }
}