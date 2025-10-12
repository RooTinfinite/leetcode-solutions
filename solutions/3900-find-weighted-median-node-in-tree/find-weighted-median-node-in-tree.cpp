#define ll long long 
class Solution {
private:
    vector<int>level;
    vector<vector<pair<int,int>>>adj;
    vector<ll>cost;
    vector<vector<int>>up;
    int k=0,n;
    
    void dfs(int node,vector<bool>&visited){
        for(auto it:adj[node]){
            int child=it.first;
            if(visited[child])continue;
            else{
                visited[child]=true;
                level[child]=level[node]+1;
                cost[child]=cost[node]+1LL*it.second;
                up[child][0]=node;
                for(int i=1;i<k;i++){
                    up[child][i]=up[up[child][i-1]][i-1];
                }
                dfs(child,visited);
            }
        }
        return;
    }
    
    void preprocess(int root){
        cost=vector<ll>(n);
        level=vector<int>(n);
        vector<bool>visited(n,false);
        visited[root]=true;
        cost[root]=0;
        level[root]=0;
        k=ceil(log2(n))+1;
        up=vector<vector<int>>(n,vector<int>(k));
        for(int i=0;i<k;i++){
            up[root][i]=0;
        }
        dfs(root,visited);
        return;
    }

    int lca(int u,int v){
        if(level[u]>level[v])swap(u,v);
        int diff=level[v]-level[u];
        for(int i=k-1;i>=0;i--){
            if(diff &(1<<i)){
                v=up[v][i];
            }
        }
        if(u==v)return u;
        for(int i=k-1;i>=0;i--){
            if(up[u][i]!=up[v][i]){
                u=up[u][i];
                v=up[v][i];
            }
        }
        return up[u][0];
    }
    int kthancestor(int u,int diff){
        if(diff==0)return u;
        int v=u;
        for(int i=k-1;i>=0;i--){
            if(diff &(1<<i)){
                v=up[v][i];
            }
        }
        return v;
    }
    ll dist(int u,int v){
        return cost[u]+cost[v]-1LL*2*cost[lca(u,v)];
    }
    int calcans(int u,int v){
        int ca=lca(u,v);
        ll d=dist(u,v);
        ll d1=dist(u,ca);
        ll d2=dist(v,ca);
        if(2*d1<d){
            int l1=level[v];
            int l2=level[ca];
            int diff=l1-l2;
            int l=0,r=diff;
            int ans=v;
            while(l<=r){
                int mid=(l+r)/2;
                int kanc=kthancestor(v,mid);
                ll d3=dist(kanc,ca);
                if(1LL*2*(d3+d1)>=d){
                    ans=kanc;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            return ans;
        }
        else if(2*d1>d){
            int l1=level[u];
            int l2=level[ca];
            int diff=l1-l2;
            int l=0,r=diff;
            int ans=ca;
            while(l<=r){
                int mid=(l+r)/2;
                int kanc=kthancestor(u,mid);
                ll d3=dist(kanc,u);
                if(1LL*2*(d3)>=d){
                    ans=kanc;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            return ans;
           
        }
        else return ca;
    }
    
public:
    vector<int> findMedian(int totalnodes, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n=totalnodes;
        adj=vector<vector<pair<int,int>>>(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        preprocess(0);
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            ans.push_back(calcans(u,v));
        }
        
        return ans;
        
        
    }
};