class Solution {
    List<List<int[]>> adj;
    public int minActivationCost(int[][] edges, int[] values) {
        adj = new ArrayList<>();
        int n = values.length;
        for(int i = 0; i < n;i++){
            adj.add(new ArrayList<>());
        }

        for(int edge[] : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj.get(u).add(new int[]{v,w});
            adj.get(v).add(new int[]{u,w});
        }
        int parityNode[] = new int[n];
        for(int i = 0; i < n;i++){
            int val = values[i];
            int cnt =0 ;
            while(val != 0){
                if((val & 1) == 1) cnt++;
                val >>= 1;
            }

            parityNode[i] = ((cnt & 1) == 0) ? 1 : 0;
        }
        long min = (long)1e16;
        for(int i = 0; i < n;i++){
            if(parityNode[i] == 1){
                int min1 = (int)1e10;
                int min2 = (int)1e10;
                for(int neigh[] : adj.get(i)){
                    int neighNode = neigh[0];
                    int neighWt = neigh[1];

                    if(parityNode[neighNode] == 1) min = Math.min(min, neighWt);
                    else{
                        if(min1 > neighWt){
                            min2 = min1;
                            min1 = neighWt;
                        }else if(min2 > neighWt){
                            min2 = neighWt;
                        }
                    } 
                }

                if(min1 != (int)1e10 && min2 != (int)1e10){
                    min = Math.min(min, min1+min2);
                }
            }else{
                for(int neigh[] : adj.get(i)){
                    int neighNode = neigh[0];
                    int neighWt = neigh[1];

                    if(parityNode[neighNode] == 0) min = Math.min(min, neighWt);
                }
            }
        }

        return min == (long)1e16 ? -1 : (int)min;
    }
}