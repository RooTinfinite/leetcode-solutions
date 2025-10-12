class Solution {
    int operations = 0;

    public int minIncrease(int n, int[][] edges, int[] cost) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());

        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        dfs(0, -1, adj, cost);
        return operations;
    }

    private long dfs(int node, int parent, List<List<Integer>> adj, int[] cost) {
        long maxChild = 0;
        int count = 0, maxCount = 0;

        for (int child : adj.get(node)) {
            if (child == parent) continue;
            long childSum = dfs(child, node, adj, cost);
            if (childSum > maxChild) {
                maxChild = childSum;
                maxCount = 1;
            } else if (childSum == maxChild) {
                maxCount++;
            }
            count++;
        }

        operations += (count - maxCount);
        return cost[node] + maxChild;
    }
}