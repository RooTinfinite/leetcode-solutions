public class Solution {
    public int ShortestPath(int n, int[][] edges, string labels, int k) {
        var g = new List<(int y, int w)>[n];
        for (int i = 0; i < n; i++) {
            g[i] = new List<(int, int)>();
        }
        foreach (var e in edges) {
            g[e[0]].Add((e[1], e[2]));
        }

        long[,] dis = new long[n, k + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dis[i, j] = int.MaxValue;
            }
        }
        // {shortest path length, node index, number of consecutive identical
        // letters at the end}
        var pq = new PriorityQueue<(long d, int x, int cnt), long>();

        dis[0, 1] = 0;
        pq.Enqueue((0, 0, 1), 0);

        while (pq.Count > 0) {
            var (d, x, cnt) = pq.Dequeue();

            if (d > dis[x, cnt]) {
                continue;
            }
            if (x == n - 1) {
                return (int)d;
            }

            foreach (var (y, w) in g[x]) {
                int newCnt = labels[x] == labels[y] ? cnt + 1 : 1;
                if (newCnt > k) {
                    continue;
                }

                long nd = d + w;
                if (nd < dis[y, newCnt]) {
                    dis[y, newCnt] = nd;
                    pq.Enqueue((nd, y, newCnt), nd);
                }
            }
        }

        return -1;
    }
}