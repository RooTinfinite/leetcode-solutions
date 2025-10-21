
class Solution {
    // dp[i]: Can number i be formed?
    static final int MAX_K = 4001;
    boolean[] dp = new boolean[MAX_K];

    public boolean[] subsequenceSumAfterCapping(int[] nums, int k) {
        // Sort nums so we can easily find how many elements are greater than x in O(1)
        Arrays.sort(nums);
        int n = nums.length;

        // Initialize dp
        Arrays.fill(dp, false);
        dp[0] = true;

        // Index for nums
        int p = 0;

        // Answer array
        boolean[] ans = new boolean[n];

        // Traverse each x
        for (int i = 1; i <= n; i++) {
            while (p < n && nums[p] < i) {
                // Similar to knapsack with space optimization
                for (int j = k; j >= nums[p]; j--) {
                    dp[j] |= dp[j - nums[p]];
                }
                p++;
            }

            // Number of elements which are greater than i
            int cnt = n - p;

            // Multiple knapsacks
            for (int j = 0; j <= cnt; j++) {
                // Pick j knapsacks (each has weight of i)
                int weight = i * j;

                if (k < weight) break;

                // We can form dp[k - weight], so we can form dp[k]
                // by choosing j knapsacks (each has weight of i)
                if (dp[k - weight]) {
                    ans[i - 1] = true;
                    break;
                }
            }
        }

        return ans;
    }
}