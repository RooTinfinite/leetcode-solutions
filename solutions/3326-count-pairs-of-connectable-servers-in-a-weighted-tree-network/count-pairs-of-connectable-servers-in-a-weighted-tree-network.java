class Solution {
    ArrayList<ArrayList<int[]>> graph;
    int mod;
    public int[] countPairsOfConnectableServers(int[][] edges, int signalSpeed) {
        int n = edges.length+1; 
        int res[] = new int[n];
        mod = signalSpeed;
        
        graph = new ArrayList<ArrayList<int[]>>();
        
        for(int i = 0; i<n; i++)graph.add(new ArrayList<int[]>());
        
        for(int e[] : edges){
            graph.get(e[0]).add(new int[]{e[1],e[2]});
            graph.get(e[1]).add(new int[]{e[0],e[2]});
        }
        
        for(int i = 0; i<n; i++){
            res[i] = fun(i);
        }
        
        return res;
    }
    
    
    int fun(int i){
        int res = 0,cur = 0; 
        
        for(int j[] : graph.get(i)){
            int t = dfs(j[0],i,j[1]);
            res += t*cur;
            cur += t;
        }
        
        return res;
    }
    
    int dfs(int node, int par, int wt){
        int res = wt%mod == 0 ? 1: 0;
        
        for(int i[] : graph.get(node)){
            if(i[0] == par)continue;
            res += dfs(i[0],node,wt+i[1]);
        }
        
        return res;
    }
}