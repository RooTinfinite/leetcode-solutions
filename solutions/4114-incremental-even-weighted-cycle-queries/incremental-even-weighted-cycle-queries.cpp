class Solution {
public:
    class dsu{
      public:
        unordered_map<int,pair<int,int>>parent; // stores parent and edge weight
        unordered_map<int,int>rank;
        
        void createset(int x){
            parent[x]={x,0};
            rank[x]=1;
        }
        
        pair<int,int> findparent(int x){
            if(parent[x].first==x){
                return {x,0};
            }
            
            pair<int,int>p=findparent(parent[x].first);
            return parent[x]= {p.first,p.second^parent[x].second};
        }
        
        void join(int x,int y,int w){
            pair<int,int> px=findparent(x);
            pair<int,int> py=findparent(y);
            int rx=rank[px.first];
            int ry=rank[py.first];
            if(px.first==py.first)return ;
            
            if(rx>ry){
                rank[px.first]+=ry;
                parent[py.first]={px.first, py.second^w^px.second};
            }
            else{
                rank[py.first]+=rx;
                parent[px.first]={py.first,px.second^w^py.second};
            }
        }
    };
    
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        dsu graph;
        for(int i=0;i<n;i++)graph.createset(i);
        int ans=0;
        
        for(vector<int>&v:edges){
            int x=v[0];
            int y=v[1];
            int w=v[2];
            
            pair<int,int>px=graph.findparent(x);
            pair<int,int>py=graph.findparent(y);
            
            // If they share the same root, a cycle is formed
            if(px.first==py.first){
                int pathsumfromx=px.second;
                int pathsumfromy=py.second;
                
                // Check if the cycle parity is even
                if((pathsumfromx^pathsumfromy)%2==0){
                    if(w==0){
                        ans++;
                    }
                }
                else{
                    if(w==1){
                        ans++;
                    }
                }
            }
            // If different roots, no cycle is formed, just join them
            else{
                ans++;
                graph.join(x,y,w);
            }
        }
        return ans;
    }
};