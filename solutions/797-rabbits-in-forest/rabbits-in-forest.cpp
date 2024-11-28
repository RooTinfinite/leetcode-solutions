class Solution {
public:
    int numRabbits(vector<int>& ans) {
        unordered_map<int,int> mp;
        int res = 0,zeros = 0;
        for(auto x : ans)
        {
          if(x!=0)mp[x]++;
          else zeros++;  
        }
        for(auto x : mp)
        {
           res = res+(x.first+1)*(x.second/(x.first+1));
           if(x.second%(x.first+1)!=0) res+=x.first+1;
        } 
        return res+zeros;
    }
};