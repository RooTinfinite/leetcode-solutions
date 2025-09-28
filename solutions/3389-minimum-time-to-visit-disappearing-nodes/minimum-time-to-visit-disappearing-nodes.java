class Solution {
    public int[] minimumTime(int n, int[][] edges, int[] disappear) {
        Map<Integer, List<int[]>> map = new HashMap<>();
        for(int[] edge: edges){
            int u = edge[0];
            int v = edge[1];
            int len = edge[2];
            map.putIfAbsent(u, new ArrayList<>());
            map.putIfAbsent(v, new ArrayList<>());
            map.get(u).add(new int[]{v, len});
            map.get(v).add(new int[]{u, len});
        }
        
        
        int[] res = new int[n];
        Arrays.fill(res, -1);
        
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparing(a->a[1]));
        pq.offer(new int[]{0, 0});
        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            int node = cur[0];
            int time = cur[1];
            if(res[node] != -1){
                continue;
            }
            res[node] = time;
            
            if(map.containsKey(node)){
                for(int[] no:map.get(node)){
                    int new_node = no[0];
                    int new_time = no[1];
                    if(res[new_node]==-1 && time+new_time < disappear[new_node]){
                        pq.offer(new int[]{new_node, time+new_time});
                    }
                }
            }
        }
        return res;
    }
}