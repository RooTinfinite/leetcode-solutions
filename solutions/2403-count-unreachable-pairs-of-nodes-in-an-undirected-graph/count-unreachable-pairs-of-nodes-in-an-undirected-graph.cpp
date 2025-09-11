#define ll long long int

class Solution {
public:
    void dfs(int node, unordered_map<int,vector<int>>& gr, ll& cnt, vector<int>& vis){
        vis[node] = 1;
        cnt++;
        for(auto& i: gr[node]){
            if(vis[i]==0) dfs(i,gr,cnt,vis);   
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> gr;
        for(int i=0;i<edges.size();i++){
            gr[edges[i][0]].push_back(edges[i][1]);
            gr[edges[i][1]].push_back(edges[i][0]);
        }
        ll ans = ((ll)n*(n-1))/2;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ll cnt = 0;
                dfs(i,gr,cnt,vis);
                ans -= (cnt*(cnt-1))/2;
            }
        }
        return ans;
    }
};