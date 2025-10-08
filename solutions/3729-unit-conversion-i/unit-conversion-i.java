class Solution {
    int[] solve(List<int[]>[] g,int src){

        Queue<int[]> q = new LinkedList<int[]>();
        q.offer(new int[]{src,1});

        int[] dist = new int[g.length];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[src] = 1;

        int mod = (int)(1e9+7);

        while(!q.isEmpty()){
            int[] top = q.poll();

            for(int[] adj:g[top[0]]){

                int w =(int) (((long)top[1]*adj[1])%mod);

                if(w<dist[adj[0]]){
                    dist[adj[0]] = w;
                    q.offer(new int[]{adj[0],w});
                }
            }
        }
        return dist;
    }
    public int[] baseUnitConversions(int[][] conversions) {
        int n = conversions.length+1;
        List<int[]>[] g= new List[n];

        for(int i = 0;i<n;i++)
            g[i] = new ArrayList<int[]>();

        for(int[] e:conversions){
            g[e[0]].add(new int[]{e[1],e[2]});
        }

        int[] dist = solve(g,0);
        return dist;
    }
}