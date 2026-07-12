class Solution {

    static class Edge {
        int to;
        long w;

        Edge(int t, long w) {
            this.to = t;
            this.w = w;
        }
    }

    static class Node implements Comparable<Node> {

        int u;
        long d;

        Node(int u, long d) {
            this.u = u;
            this.d = d;
        }

        public int compareTo(Node o) {
            return Long.compare(this.d, o.d);
        }
    }

        static final long INF = Long.MAX_VALUE / 4;

        long[] dijkstra(ArrayList<Edge>[] g, int s) {

            int n = g.length;

            long[] d = new long[n];

            Arrays.fill(d, INF);

            PriorityQueue<Node> pq = new PriorityQueue<>();

            d[s] = 0;

            pq.offer(new Node(s, 0));

            while (!pq.isEmpty()) {

                Node cur = pq.poll();

                int u = cur.u;

                if (cur.d != d[u]) {
                    continue;
                }

                for (Edge e : g[u]) {

                    int v = e.to;

                    long nd = d[u] + e.w;

                    if (nd < d[v]) {

                        d[v] = nd;

                        pq.offer(new Node(v, nd));
                    }
                }
            }

            return d;
        }
    
    public int[] minCost(int n, int[] prices, int[][] roads) {
        ArrayList<Edge>[] empty = new ArrayList[n];
        ArrayList<Edge>[] carry = new ArrayList[n];  

        for(int i = 0; i < n; i++){
            empty[i] = new ArrayList<>();
            carry[i] = new ArrayList<>();
        }

        for(int[] r : roads){
            int u = r[0];
            int v = r[1];

            long c = r[2];
            long t = r[3];

            empty[u].add(new Edge(v, c));
            empty[v].add(new Edge(u, c));

            carry[u].add(new Edge(v, c * t));
            carry[v].add(new Edge(u, c * t));
        }

        long[][] de = new long[n][];
        long[][] dc = new long[n][];

        for(int i = 0; i < n; i++){
            de[i] = dijkstra(empty, i);
            dc[i] = dijkstra(carry, i);  
        }

        int[] res = new int[n];

        for(int i = 0; i < n; i++){
            long best = prices[i];
            for(int j = 0; j < n; j++){
                if(de[i][j] == INF || dc[j][i] == INF){
                    continue;
                }

                long curr = de[i][j] + dc[j][i] + prices[j];

                if(curr < best){
                    best = curr;
                }
            }

            res[i] = (int) best;
        }

        return res;
    }
}