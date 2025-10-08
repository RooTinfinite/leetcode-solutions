class Solution {
    long dp[][][];
    HashMap<Integer, HashSet<Integer>> adj = new HashMap<>();

    public void postOrder(int i, int nums[], int n, int k) {
        if (adj.get(i) == null || adj.get(i).size() == 0) {
            for (int t = k; t > 0; t--) {
                dp[i][t][0] = nums[i];
                dp[i][t][1] = nums[i];
            }
            dp[i][0][0] = Math.min(nums[i], -nums[i]);
            dp[i][0][1] = Math.max(nums[i], -nums[i]);
            return;
        }
        for (int j : adj.get(i)) {
            postOrder(j, nums, n, k);
            for (int t = k; t > 0; t--) {
                dp[i][t][0] += dp[j][t - 1][0];
                dp[i][t][1] += dp[j][t - 1][1];
            }
            dp[i][0][0] -= dp[j][k][1];
            dp[i][0][1] -= dp[j][k][0];
        }
        dp[i][k][0] += nums[i];
        dp[i][k][1] += nums[i];
        dp[i][0][0] -= nums[i];
        dp[i][0][1] -= nums[i];

        for (int t = k - 1; t > 0; t--) {
            dp[i][t][0] += nums[i];
            dp[i][t][1] += nums[i];
            dp[i][t][0] = Math.min(dp[i][t][0], dp[i][t + 1][0]);
            dp[i][t][1] = Math.max(dp[i][t][1], dp[i][t + 1][1]);
        }
        dp[i][0][0] = Math.min(dp[i][0][0], dp[i][1][0]);
        dp[i][0][1] = Math.max(dp[i][0][1], dp[i][1][1]);
    }

    public long subtreeInversionSum(int[][] edges, int[] nums, int k) {
        if(k==0 || k==1){
            long sum=0;
            for(int i:nums){
                sum+=Math.max(i,-i);
            }
            return sum;
        }
        k -= 1;
        int n=nums.length;
        for (int edge[] : edges) {
            if (adj.get(edge[0]) == null) {
                adj.put(edge[0], new HashSet<Integer>());
            }
            if (adj.get(edge[1]) == null) {
                adj.put(edge[1], new HashSet<Integer>());
            }
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        int topo[] = new int[n];
        // int i = 0;
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j : adj.get(topo[i])) {
                adj.get(j).remove(topo[i]);
                topo[++c] = j;
            }

        }

        // int n = nums.length;
        dp = new long[n][k + 1][2];
        postOrder(0, nums, n, k);
        // System.out.println(Arrays.deepToString(dp));
        return dp[0][0][1];

    }
}