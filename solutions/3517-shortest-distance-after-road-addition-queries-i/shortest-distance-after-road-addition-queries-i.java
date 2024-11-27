class Solution {
    private void dfs(List<List<Integer>> tree, int c, int[] dp) {
        int d = dp[c] + 1;
        for (int x : tree.get(c)) {
            if (dp[x] <= d) continue;
            dp[x] = d;
            dfs(tree, x, dp);
        }
    }
    
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = n - 1 - i;
        }
        
        List<List<Integer>> tree = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            tree.add(new ArrayList<>());
        }
        
        for (int i = 0; i < n - 1; i++) {
            tree.get(i + 1).add(i);
        }
        
        int m = queries.length;
        int[] res = new int[m];
        
        for (int i = 0; i < m; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            tree.get(b).add(a);
            dp[a] = Math.min(dp[a], dp[b] + 1);
            dfs(tree, a, dp);
            res[i] = dp[0];
        }
        
        return res;
    }
}

