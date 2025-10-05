class Solution {
    public int minMaxWeight(int n, int[][] edges, int threshold) {
        int minW = Integer.MAX_VALUE ;
        int maxW = 0 ; 
        for(int[] edge : edges){
            minW = Math.min(minW , edge[2]);
            maxW = Math.max(maxW , edge[2]);
        }
        int ans = -1 ; 
        int l = minW ; 
        int r = maxW ; 
        while(l <= r){
            int mid = l + (r-l)/2 ;
            if(isPossible(n , edges , mid)){
                ans = mid ;
                r = mid-1 ; 
            }else{
                l = mid+1 ;
            }
        }
        return ans ; 
    }
    public boolean isPossible(int n, int[][] edges, int threshold) {
        List<List<Integer>> revGraph = new ArrayList<>();
        for(int i = 0 ; i < n ; i++) revGraph.add(new ArrayList<>());
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(edge[2] <= threshold){
                revGraph.get(v).add(u);
            }
        }
        boolean[] visited = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        visited[0] = true ;
        int count = 1 ;

        while(!q.isEmpty()){
            int curr = q.poll();
            for(Integer neighbor : revGraph.get(curr)){
                if(visited[neighbor] == false){
                    visited[neighbor] = true ; 
                    q.add(neighbor);
                    count++ ;
                }
            }
        }
        return count == n ;
    }

}