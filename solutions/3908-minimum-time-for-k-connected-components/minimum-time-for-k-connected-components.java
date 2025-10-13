class Solution {
    public int minTime(int n, int[][] edges, int k) {
        List<List<int[]>> adj = new ArrayList<>();
        int high = Integer.MIN_VALUE;
        for(int i=0; i<n; i++) {
            adj.add(new ArrayList<>());
        }

        for(int[] edge : edges) {
            adj.get(edge[0]).add(new int[] {edge[1], edge[2]});
            adj.get(edge[1]).add(new int[] {edge[0], edge[2]});
            high = Math.max(high, edge[2]);
        }

        int low = 0;
        int ans = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int tmp = count(adj, n, mid);

            if(tmp >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                
                low = mid + 1;
            }
        }
        return ans;
    }
    int count(List<List<int[]>> adj, int n, int time) {
        boolean[] vis = new boolean[n];
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(adj, vis, i, time);
                cnt++;
            }
        }
        return cnt;
    }
    void dfs(List<List<int[]>> adj, boolean[] vis, int u, int time) {
        vis[u] = true;
        for(int[] edge : adj.get(u)) {
            if(!vis[edge[0]] && time < edge[1]) {
                dfs(adj, vis, edge[0], time);
            }
        }
        return;
    }
}