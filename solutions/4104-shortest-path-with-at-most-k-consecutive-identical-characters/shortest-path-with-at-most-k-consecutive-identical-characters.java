class Solution {
    public int shortestPath(int n, int[][] edges, String labels, int k) {
        long INF = Long.MAX_VALUE / 4;

        List<int[]>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for (int[] e : edges) adj[e[0]].add(new int[]{e[1], e[2]});

        long[][] dist = new long[n][k + 1];
        for (long[] row : dist) Arrays.fill(row, INF);

        // {distance, node, cnt}
        PriorityQueue<long[]> pq =
            new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));

        dist[0][1] = 0;
        pq.offer(new long[]{0, 0, 1});

        while (!pq.isEmpty()) {
            long[] cur = pq.poll();
            long d = cur[0];
            int u = (int) cur[1];
            int run = (int) cur[2];

            if (d != dist[u][run]) continue;

            for (int[] vec : adj[u]) {
                int v = vec[0], w = vec[1];
                int newRun = (labels.charAt(v) == labels.charAt(u)) ? run + 1 : 1;
                if (newRun > k) continue;

                if (dist[v][newRun] > d + w) {
                    dist[v][newRun] = d + w;
                    pq.offer(new long[]{dist[v][newRun], v, newRun});
                }
            }
        }

        long ans = INF;
        for (int i = 1; i <= k; i++) ans = Math.min(ans, dist[n - 1][i]);
        return ans == INF ? -1 : (int) ans;
    }
}