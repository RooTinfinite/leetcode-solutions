class Solution {
    public long minCost(int n, String colors, int[][] edges) {
        int[] head = new int[n];
        int[] to = new int[2 * (n - 1)];
        int[] next = new int[2 * (n - 1)];

        Arrays.fill(head, -1);

        int idx = 0;

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            to[idx] = v;
            next[idx] = head[u];
            head[u] = idx++;

            to[idx] = u;
            next[idx] = head[v];
            head[v] = idx++;
        }

        int[] parent = new int[n];
        int[] order = new int[n];
        int[] subtreeSize = new int[n];

        long[] dp = new long[n];

        parent[0] = -1;
        order[0] = 0;

        int count = 1;

        for (int i = 0; i < count; i++) {
            int u = order[i];

            for (int j = head[u]; j != -1; j = next[j]) {
                int v = to[j];

                if (v == parent[u]) {
                    continue;
                }

                parent[v] = u;
                order[count++] = v;
            }
        }

        long baseline = 0;
        long maxSaving = 0;

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            subtreeSize[u] = 1;
            long childContribution = 0;

            for (int j = head[u]; j != -1; j = next[j]) {
                int v = to[j];

                if (parent[v] != u) {
                    continue;
                }

                subtreeSize[u] += subtreeSize[v];
                childContribution += Math.max(0L, dp[v]);
            }

            long weight;

            if (colors.charAt(u) == 'R') {
                weight = subtreeSize[u];
                baseline += subtreeSize[u];
            } else {
                weight = -subtreeSize[u];
            }

            dp[u] = weight + childContribution;
            maxSaving = Math.max(maxSaving, dp[u]);
        }

        return baseline - maxSaving;
    }
}