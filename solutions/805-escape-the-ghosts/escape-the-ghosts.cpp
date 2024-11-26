class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
     int tx=target[0];
     int ty=target[1];
     int dt=abs(ty)+abs(tx);
     for(auto i:ghosts)
     {
         int d=abs(tx-i[0])+abs(ty-i[1]);
         if(d<=dt)
         {
             return 0;
         }
     }   
     return 1;
    }
};