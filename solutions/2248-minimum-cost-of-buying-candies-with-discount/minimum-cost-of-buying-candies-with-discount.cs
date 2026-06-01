public class Solution {
    public int MinimumCost(int[] cost) {
        Array.Sort(cost);
        Array.Reverse(cost);

        int res = 0;
        int n = cost.Length;
        for (int i = 0; i < n; ++i) {
            if (i % 3 != 2) {
                res += cost[i];
            }
        }
        return res;
    }
}
