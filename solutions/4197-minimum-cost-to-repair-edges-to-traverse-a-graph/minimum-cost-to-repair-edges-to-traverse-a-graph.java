class Solution {
    private int[][][] adj;
    private int k, n;
    public int minCost(int n, int[][] edges, int k) {
        this.adj = buildGraph(edges, n); //optimized adj list template
        this.k = k;
        this.n = n;

        if(!check(Integer.MAX_VALUE)) return -1; //return early if it's impossible

        int left = Integer.MAX_VALUE, right = 1;
        for(int[] edge : edges) { //find min and max edge weights
            int val = edge[2];
            left = Math.min(left, val);
            right = Math.max(right, val);
        }

        while(left < right) { //binary search the smallest valid edge weight
            int mid = left + right >>> 1;
            if(check(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    private boolean check(int x) { //regular BFS
        Queue<Integer> queue = new LinkedList<>();
        boolean[] seen = new boolean[n];
        seen[0] = true;
        queue.offer(0);
        for(int i = 0; i < k; i++) { //only take k steps
            for(int j = queue.size(); j > 0; j--) {
                int current = queue.poll();
                for(int[] next : adj[current]) {
                    int index = next[0];
                    if(!seen[index] && next[1] <= x) {
                        if(index == n - 1) return true;
                        seen[index] = true;
                        queue.offer(index);
                    }
                }
            }
        }
        return false;
    }
    private static int[][][] buildGraph(int[][] edges, int n) {
        int[] degree = new int[n];
        for(int[] edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        int[][][] adj = new int[n][][];
        for(int i = 0; i < n; i++) adj[i] = new int[degree[i]][];
        for(int[] edge : edges) {
            int a = edge[0], b = edge[1], c = edge[2];
            adj[a][--degree[a]] = new int[] {b, c};
            adj[b][--degree[b]] = new int[] {a, c};
        }
        return adj;
    }
}