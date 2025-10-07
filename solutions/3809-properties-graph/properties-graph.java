class DSU{
    int[]par;
    public DSU(int n){
        par = new int[n];
        for(int i=0;i<n;i++){
            par[i] =i;
        }
    }
    public void union(int u, int v){
        int paru = find(u);
        int parv = find(v);
        if(paru!= parv){
            par[paru] = parv;
        }
    }
    public int find(int u){
        if(par[u] ==u) return u;
        return par[u]= find(par[u]);
    }
}
class Solution {
    public int intersect(int[]a, int[]b){
        Set<Integer> st = new HashSet<>();
        int cnt =0;
        for(int num: a){
            st.add(num);
        }
        for(int num: b){
            if(st.contains(num)){
                cnt++;
                st.remove(num);
            }
        }
        return cnt;
    }
    public int numberOfComponents(int[][] prop, int k) {
        int n = prop.length;
        int m = prop[0].length;
        DSU dsu = new DSU(n);
        int comp=n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cnt = intersect(prop[i], prop[j]);
                if(cnt>=k){
                    int pari = dsu.find(i);
                    int parj = dsu.find(j);
                    if(pari != parj){
                        dsu.union(i,j);
                        comp--;
                    }
                }
            }
        }
        return comp;
    }
}