import java.util.*;

class Solution {
    public int longestBalanced(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            Set<Integer> e = new HashSet<>();
            Set<Integer> o = new HashSet<>();
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) e.add(nums[j]);
                else o.add(nums[j]);
                if (e.size() == o.size()) ans = Math.max(ans, j - i + 1);
            }
        }
        return ans;
    }
}