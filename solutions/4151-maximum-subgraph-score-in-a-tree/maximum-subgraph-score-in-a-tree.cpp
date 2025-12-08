class Solution {
public:
    void dfs(int v,int par,vector<int>& sub,vector<vector<int>>& to,vector<int>& g){
        sub[v]+=(g[v]==1?1:-1);
        for(int u:to[v]){
            if(u==par)continue;
            dfs(u,v,sub,to,g);
            sub[v]+=max(0,sub[u]);
        }
    }
    void calc(int v,int par,int par_v,vector<int>& sub,vector<vector<int>>& to,vector<int>& g){
        sub[v]+=max(0,par_v);
        for(int u:to[v]){
            if(u==par)continue;
            calc(u,v,sub[v]-max(0,sub[u]),sub,to,g);
        }
    }
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<int>sub(n);
        vector<vector<int>>to(n);
        for(auto vec:edges){
            to[vec[0]].push_back(vec[1]);
            to[vec[1]].push_back(vec[0]);
        }
        dfs(0,-1,sub,to,good);
        
        calc(0,-1,0,sub,to,good);
        return sub;
    }
};