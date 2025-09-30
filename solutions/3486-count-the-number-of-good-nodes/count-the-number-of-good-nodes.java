import java.util.*;

class Solution {
    private List<List<Integer>> adj;  // Use List of Lists for adjacency list
    private int ans;

    private int dfs(int node, int parent) {
        int totalNodes = 0;
        boolean isGood = true;
        int subtreeSize = -1;

        for (int neighbor : adj.get(node)) {
            if (neighbor == parent) continue;
            int currentSize = dfs(neighbor, node);
            if (subtreeSize == -1) {
                subtreeSize = currentSize;
            } else if (currentSize != subtreeSize) {
                isGood = false;
            }
            totalNodes += currentSize;
        }

        if (isGood) ans++;
        return totalNodes + 1;
    }

    public int countGoodNodes(int[][] edges) {
        int n = edges.length + 1;
        adj = new ArrayList<>(n);

        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        ans = 0;
        dfs(0, -1);
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] edges = {{0, 1}, {1, 2}, {1, 3}};
        int result = solution.countGoodNodes(edges);
        System.out.println("Number of good nodes: " + result);
    }
}
