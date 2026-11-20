public class Solution {
    public int MaxSelectedElements(int[] nums) {
        Array.Sort(nums);
        var dp = new Dictionary<int, int>();
        int ans = 0;
        foreach (int x in nums) {
            dp.TryGetValue(x - 1, out int prev);
            dp.TryGetValue(x, out int curr);
            dp.TryGetValue(x + 1, out int next);
            dp[x + 1] = Math.Max(next, curr + 1);
            dp[x] = Math.Max(curr, prev + 1);
            ans = Math.Max(ans, Math.Max(dp[x], dp[x + 1]));
        }
        return ans;
    }
}