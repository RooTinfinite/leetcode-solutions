class Solution {

    static class Node implements Comparable<Node> {
        int r, c, p;
        long d;

        Node(int r, int c, int p, long d) {
            this.r = r;
            this.c = c;
            this.p = p;
            this.d = d;
        }

        public int compareTo(Node o) {
            return Long.compare(this.d, o.d);
        }
    }

    public long minCost(int m, int n, int[][] penalty) {
        long INF = Long.MAX_VALUE / 4;
        long[][][] dist = new long[m][n][2];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j][0] = INF;
                dist[i][j][1] = INF;
            }
        }

        PriorityQueue<Node> pq = new PriorityQueue<>();

        dist[0][0][0] = 1;
        pq.offer(new Node(0, 0, 0, 1));

        int[] dr = { 0, 1, 0, -1 };
        int[] dc = { 1, 0, -1, 0 };

        while (!pq.isEmpty()) {
            Node curr = pq.poll();

            if (curr.d != dist[curr.r][curr.c][curr.p])
                continue;

            int np = curr.p ^ 1;

            long nd = curr.d + penalty[curr.r][curr.c];
            if (nd < dist[curr.r][curr.c][np]) {
                dist[curr.r][curr.c][np] = nd;
                pq.offer(new Node(curr.r, curr.c, np, nd));
            }

            for (int k = 0; k < 4; k++) {
                int nr = curr.r + dr[k];
                int nc = curr.c + dc[k];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                boolean followsRule;

                if (curr.p == 0) {
                    followsRule = (k == 0 || k == 1);
                } else {
                    followsRule = (k == 2 || k == 3);
                }

                long cost = curr.d + (long) (nr + 1) * (nc + 1);

                if (!followsRule) {
                    cost += penalty[curr.r][curr.c];
                }

                if (cost < dist[nr][nc][np]) {
                    dist[nr][nc][np] = cost;
                    pq.offer(new Node(nr, nc, np, cost));
                }
            }
        }

        return Math.min(dist[m - 1][n - 1][0], dist[m - 1][n - 1][1]);
    }
}