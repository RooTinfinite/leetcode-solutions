class Solution {
    public int maxStability(int n, int[][] edges, int k) {
        par = new int [n];
        rank = new int[n];
        for(int i = 0;i<n;i++){
            par[i] = i;
        }

        int comp = n;

        Arrays.sort(edges,(a,b)->(b[3]==a[3]?Integer.compare(b[2],a[2]):Integer.compare(b[3],a[3])));
        int minOne = (int)1e9;
        int minZero = (int)1e9;

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int [] e: edges){
            boolean union = union(e[0],e[1]);
            
            if(e[3]==1 && !union) return -1;

            if(union){
                comp--;
                
                if(e[3]==0){
                    pq.add(e[2]);
                }else{
                    minOne = Math.min(minOne,e[2]);
                }
            }
            
        }
        while(!pq.isEmpty()){
            if(k-->0){
                minZero = Math.min(minZero, pq.poll()*2);
            }else{
                minZero = Math.min(minZero,pq.poll());
            }
        }
        if(comp!=1) return -1;
        return Math.min(minOne, minZero);
    }

    int par[];
    int rank[];

    boolean union(int u, int v){
        int parU = get(u);
        int parV = get(v);
        if(parU==parV) return false;
        if(rank[parU]>=rank[parV]){
            par[parV] = parU;
            if(rank[parU]==rank[parV]) rank[parU]++;
        }else{
            par[parU] = parV;
        }
        return true;
    }


    int get(int u){
        if(par[u]==u) return u;

        return par[u] = get(par[par[u]]);
    }
}