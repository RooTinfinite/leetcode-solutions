class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
            adj.get(i).add(i + 1);
        }
        
        List<Integer> resList = new ArrayList<>();
        for (int[] query : queries) {
            adj.get(query[0]).add(query[1]);
            resList.add(shortestPath(adj, n));
        }
        
        return resList.stream().mapToInt(Integer::intValue).toArray();
    }
    
    private int shortestPath(List<List<Integer>> adj, int n) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0, 0}); // node, length
        Set<Integer> visit = new HashSet<>();
        visit.add(0);
        
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int cur = curr[0];
            int length = curr[1];
            
            if (cur == n - 1) return length;
            
            for (int nei : adj.get(cur)) {
                if (!visit.contains(nei)) {
                    q.offer(new int[]{nei, length + 1});
                    visit.add(nei);
                }
            }
        }
        return -1;
    }
}