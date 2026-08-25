public class Solution {
    public int MissingMultiple(int[] nums, int k) {
        HashSet<int> seen = new HashSet<int>(nums);
        int ans = k;
        while (seen.Contains(ans)) {
            ans += k;
        }
        return ans;
    }
}