import java.util.*;

class StateComparator implements Comparator<long[]> {
    public int compare(long[] a, long[] b) {
        return Long.compare(a[0], b[0]);
    }
}

class Solution {
    static final long inf = (long) 1e18;

    public long[] minTimeMaxPower(int n, int[][] edges, int p, int[] cost, int s, int t) {
        List<int[]>[] adj = new List[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].add(new int[]{v, w});
        }
        long[] ans = {-1, -1};
        long[][] dist = new long[n][p + 1];
        for (long[] row : dist) Arrays.fill(row, inf);
        // priority queue stores {time, node, remaining power}
        PriorityQueue<long[]> pq = new PriorityQueue<>(new StateComparator());
        dist[s][p] = 0;
        pq.offer(new long[]{0, s, p});
        long best = -1, bestp = -1;
        while (!pq.isEmpty()) {
            long[] vec = pq.poll();
            long time = vec[0];
            int u = (int) vec[1];
            int remp = (int) vec[2];
            if (time != dist[u][remp]) continue;
            if (best != -1 && time > best) break;
            if (u == t) {
                if (best == -1) best = time;
                bestp = Math.max(remp, bestp);
                continue;
            }
            if (remp < cost[u]) continue;
            int nxtp = remp - cost[u];
            for (int[] nei : adj[u]) {
                int v = nei[0], w = nei[1];
                long ntime = time + w;
                if (ntime < dist[v][nxtp]) {
                    dist[v][nxtp] = ntime;
                    pq.offer(new long[]{ntime, v, nxtp});
                }
            }
        }
        ans[0] = best;
        ans[1] = bestp;
        return ans;
    }
}