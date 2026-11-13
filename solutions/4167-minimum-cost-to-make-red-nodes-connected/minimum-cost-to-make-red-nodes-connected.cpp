# define ll long long 
class Solution {
public:
    long long minCost(int n, string colors, vector<vector<int>>& edges) {
        vector<vector<int>>g(n);
        for(auto &i:edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<ll>red(n,0);
        vector<ll>blue(n,0);
        vector<ll>sub(n,0);
        ll ans=LLONG_MAX;
        function<void(ll,ll)>dfs=[&](ll v,ll p){
            sub[v]=1;
            for(auto child:g[v]){
                if(child==p) continue;
                dfs(child,v);
                sub[v]+=sub[child];
                blue[v]+=blue[child];
                red[v]+=min(red[child],blue[child]);
            }
            if(colors[v]=='B') red[v]+=sub[v];
            else blue[v]+=sub[v];
        };

        dfs(0,-1);

        function<void(ll,ll)>dfs2=[&](ll v,ll p){
            ans=min(ans,red[v]+blue[0]-blue[v]);
            for(auto child:g[v]){
                if(child==p) continue;
                dfs2(child,v); 
            }
        };
        dfs2(0,-1);
        return min(blue[0],ans);
    }
};