import java.util.*;

class Solution {
    private long totalCost = 0;
    private int[][] counts;
    private int[] totalInGroup;
    private List<Integer>[] adj;

    public long interactionCosts(int n, int[][] edges, int[] group) {
        adj = new ArrayList[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for (int[] edge : edges) {
            adj[edge[0]].add(edge[1]);
            adj[edge[1]].add(edge[0]);
        }

        totalInGroup = new int[21];
        for (int g : group) totalInGroup[g]++;

        counts = new int[n][21];
        dfs(0, -1, group);

        return totalCost;
    }

    private void dfs(int u, int p, int[] group) {
        counts[u][group[u]] = 1;

        for (int v : adj[u]) {
            if (v == p) continue;
            
            dfs(v, u, group);
            
            for (int g = 1; g <= 20; g++) {
                if (totalInGroup[g] < 2) continue;
                
                long inSubtree = counts[v][g];
                long outsideSubtree = totalInGroup[g] - inSubtree;
                
                totalCost += inSubtree * outsideSubtree;
                counts[u][g] += counts[v][g];
            }
        }
    }
}