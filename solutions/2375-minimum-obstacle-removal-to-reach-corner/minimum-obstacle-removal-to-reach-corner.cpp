class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
      int m=grid.size();
      int n=grid[0].size();
      int i,j;
      vector<vector<pair< int, int> >> adj(m*n);

      for(i=0;i<m;i++){
          for(j=0;j<n;j++){
      
      int c=n*i+j;
    
           if(i!=0){
            adj[c].push_back(make_pair(grid[i-1][j],n*(i-1)+j));
           }
           if(i!=m-1){
           adj[c].push_back(make_pair(grid[i+1][j],n*(i+1)+j));
           }
           if(j!=0){
           adj[c].push_back(make_pair(grid[i][j-1],n*i+j-1));
           }
           if(j!=n-1){
           adj[c].push_back(make_pair(grid[i][j+1],n*i+j+1 ));
           }

          }
      }

      set<pair<int,int>> s;
      
      s.insert(make_pair(0,0));
      vector<int> visited(m*n);
      for(i=0;i<m*n;i++){
          visited[i]=0;
      }
      visited[0]=1;
    
      while(s.empty()!=1){
       
       pair<int,int> p=*(s.begin());

       visited[p.second]=1;
       if(p.second==m*n-1){
           return p.first;
       }
       s.erase(s.begin());
      for(j=0;j<adj[p.second].size();j++){

         
           if(visited[adj[p.second][j].second]==0){
             s.insert(make_pair(p.first+adj[p.second][j].first,adj[p.second][j].second));
            
           }
      }


      }


     return (n+m-3);

    }
};