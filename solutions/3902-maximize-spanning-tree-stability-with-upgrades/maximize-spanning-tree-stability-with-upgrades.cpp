class Solution {
public:
    class DSU {
private:
    vector<int> parent, sizes;

public:
    DSU(int n) {
        parent.resize(n);
        sizes.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return;

        if (sizes[xr] < sizes[yr]) swap(xr, yr);
        parent[yr] = xr;
        sizes[xr] += sizes[yr];
    }
    
    int getSize(int x) {
        return sizes[find(x)];
    }
};

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int> >msts;
        vector<vector<int> >nmsts;
        for(int i=0;i<edges.size();i++){
            int u =edges[i][0],v=edges[i][1],s=edges[i][2],must=edges[i][3];
            if(must==1)msts.push_back({u,v,s});
            else nmsts.push_back({s,u,v});
        }
        int mustans=1e9;
        int nmustans=1e9;
        DSU d(n);
        for(int i=0;i<msts.size();i++){
            int u=msts[i][0],v=msts[i][1],s=msts[i][2];
            if(d.find(u)==d.find(v))return -1;
            d.unite(u,v);
            mustans=min(mustans,s);
        }
        sort(nmsts.begin(),nmsts.end());
        reverse(nmsts.begin(),nmsts.end());
        vector<int>nans;
        for(int i=0;i<nmsts.size();i++){
            int s=nmsts[i][0],u=nmsts[i][1],v=nmsts[i][2];
            if(d.find(u)==d.find(v))continue;
            d.unite(u,v);
            nans.push_back(s);
        }
        sort(nans.begin(),nans.end());
        for(int i=0;i<nans.size();i++){
            if(k>0){
                nans[i]*=2;
                k--;
            }
        }
        sort(nans.begin(),nans.end());
        int finalans=1e9;
        finalans=min(finalans,mustans);
      if(not nans.empty())  finalans=min(finalans,nans[0]);
        if(d.getSize(0)!=n)return -1;
        return finalans;
    }
};