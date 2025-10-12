class Solution {
    class node{
        int t; long w;
        node(int _t, long _w){
            t=_t; w=_w;
        }
    }
    public int[] findMedian(int n, int[][] e, int[][] q) {
        int[][] p = new int[n][17];
        int[] d = new int[n];
        long[][] w = new long[n][17];
        makePar(n, e, p, d, w);

        int[] a = new int[q.length];
        for(int i=0; i<q.length; i++){
            a[i]=find(q[i][0], q[i][1], p, w, d);
        }

        return a;
    }
    private int find(int fr, int to, int[][] p, long[][] w, int[] d){
        long[] cpw = new long[2];//Common Par Weight
        int cp = getCommonPar(fr, to, p, w, d, cpw);
        if(cpw[0]==cpw[1])return cp;
        else if(cpw[0]>cpw[1]){
            return getPar(fr, p, w, (cpw[0]+cpw[1]+1)/2, true);
        }else{//if(cpw[0]<cpw[1]{
            return getPar(to, p, w, (cpw[0]+cpw[1])/2, false);
        }
    }
    private int getPar(int x, int[][] p, long[][] w, long z, boolean ceil){
        if(w[x][0]==z)return p[x][0];
        else if(w[x][0]>z)return ceil?p[x][0]:x;

        int u=0;
        for(; w[x][u]<z; u++);
        if(u<17 && w[x][u]==z)return p[x][u];
        
        u--;
        return getPar(p[x][u], p, w, z-w[x][u], ceil);
    }
    private int getCommonPar(int fr, int to, int[][] p, long[][] w, int[] d, long[] cpw){
        int ft=fr, tt=to;
        if(d[fr]>d[to])ft=goUp(fr, d[fr]-d[to], p, w, d, cpw, 0);
        if(d[fr]<d[to])tt=goUp(to, d[to]-d[fr], p, w, d, cpw, 1);

        while(ft!=tt){
            if(p[ft][0]==p[tt][0]){
                cpw[0]+=w[ft][0];
                cpw[1]+=w[tt][0];
                ft=p[ft][0]; tt=p[tt][0];
                continue;
            }
            int u=0;
            for(; p[ft][u]>=0&&p[ft][u]!=p[tt][u]; u++);
            u--;
            cpw[0]+=w[ft][u];
            cpw[1]+=w[tt][u];
            ft=p[ft][u];
            tt=p[tt][u];
        }
        return ft;
    }
    private int goUp(int x, int td, int[][] p, long[][] w, int[] d, long[] cpw, int i){
        if(td==0)return x;
        else if(td==1){
            cpw[i]+=w[x][0];
            return p[x][0];
        }
        int r=0, v=1;
        while(v<=td){
            v<<=1; r++;
        }
        v>>=1; r--;
        cpw[i] += w[x][r];
        return goUp(p[x][r], td-v, p, w, d, cpw, i);
    }

    private void makePar(int n, int[][] e, int[][] p, int[] d, long[][] w){
        for(int i=0; i<n; i++){
            Arrays.fill(p[i],-1);
            Arrays.fill(w[i], 1_000_000_000_000_000L);
        }

        ArrayList<node>[] x = new ArrayList[n];
        for(int i=0; i<n; i++)x[i]=new ArrayList<>();

        for(int[] ee:e){
            x[ee[0]].add(new node(ee[1], ee[2]));
            x[ee[1]].add(new node(ee[0], ee[2]));
        }

        for(node t:x[0]){
            dfs(t, 0, p, d, w, x);
        }
    }
    private void dfs(node t, int f, int[][] p, int[] d, long[][] w, ArrayList<node>[] x){
        p[t.t][0]=f; w[t.t][0]=t.w;
        for(int i=0; i<16&&p[p[t.t][i]][i]>=0; i++){
            p[t.t][i+1]=p[p[t.t][i]][i];
            w[t.t][i+1]=w[t.t][i] + w[p[t.t][i]][i];
        }

        d[t.t]=d[f]+1;

        for(node g:x[t.t]){
            if(g.t==f)continue;
            dfs(g, t.t, p, d, w, x);
        }
    }
}