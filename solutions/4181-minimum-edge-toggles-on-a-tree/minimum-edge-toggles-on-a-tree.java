class Solution {
    List<Integer> ans = new ArrayList<>();
    List<int[]> []graph;// for stroing the graph as array of list of array
    int[] need;// for checking which node needs to be change
    public List<Integer> minimumFlips(int n, int[][] edges, String start, String target) {
        graph = new ArrayList[n];
        for(int i=0;i<n;i++){
            graph[i] = new ArrayList<>();
        }
        for(int i=0;i<n-1;i++){
            int u = edges[i][0];
            int v = edges[i][1];

           graph[u].add(new int[]{v,i});
           graph[v].add(new int[]{u,i});
        }
        need = new int[n];
        for(int i=0;i<n;i++){
            if(start.charAt(i)!=target.charAt(i))
              need[i]=1;
        }
        Dfs(0,-1);
        if(need[0]==1){//agar root abhi bhi galat h to impossible h same bnana
           
            return Arrays.asList(-1);
           
        }
        Collections.sort(ans);
        return ans;
    }
  public  void Dfs(int node ,int parent){

      for(int []edge : graph[node]){
          int child = edge[0];
          int edgeind = edge[1];

 
          if(child==parent) continue;

          Dfs(child,node);

          if(need[child]==1){
              ans.add(edgeind);
              need[child]^=1;
              need[node]^=1;
          }
      }
  }
    
}