class DisjointSet {
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n) {
       rank.resize(n+1,0);
       parent.resize(n+1,0);
       size.resize(n+1,0);
       for(int i=0;i<=n;i++){
         parent[i]=i;
         size[i]=1;
       }
    }

    int findUpar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUpar(parent[node]);
    }

    bool same(int u, int v) {
        return findUpar(u) == findUpar(v);
    }

    void unionByRank(int u, int v) {
        int par1= findUpar(u);
        int par2= findUpar(v);
        if(par1==par2) return;
        if(rank[par1]<rank[par2]){
           parent[par1]= par2;
        }
        else if(rank[par1]>rank[par2]){
           parent[par2]= par1;
        }
        else{
           parent[par1]=par2;
           rank[par2]++;
        }
    }

    void unionBySize(int u, int v) {
       int par1= findUpar(u);
       int par2= findUpar(v);
       if(par1==par2) return;
       if(size[par1]<size[par2]){
           parent[par1]=par2;
           size[par2]+=size[par1];
       }
       else{
           parent[par2]=par1;
           size[par1]+=size[par2];
       }
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& num, vector<vector<int>>& swp) {
        int n = num.size();
        DisjointSet dsu(n);
        for (auto &e : swp) dsu.unionBySize(e[0], e[1]);

        unordered_map<int, vector<int>> grp;
        unordered_map<int, pair<int,int>> cnt;

        for (int i = 0; i < n; ++i) {
            int p = dsu.findUpar(i);
            grp[p].push_back(num[i]);
            if (i % 2 == 0) cnt[p].first++;
            else cnt[p].second++;
        }

        long long ans = 0;
        for (auto &it : grp) {
            int p = it.first;
            vector<int> &vec = it.second;
            sort(vec.begin(), vec.end());

            long long sum = 0;
            for (int v : vec) sum += v;

            int odd = cnt[p].second;
            long long osum = 0;
            for (int i = 0; i < odd && i < (int)vec.size(); ++i)
                osum += vec[i];

            ans += (sum - 2LL * osum);
        }
        return ans;
    }
};