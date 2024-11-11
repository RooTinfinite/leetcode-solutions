class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
      if(intervals.size()==1)
         return intervals;
      vector<pair<int,int>> p;
      for(int i=0;i<intervals.size();i++)
      {
          p.push_back({intervals[i][0],intervals[i][1]});
      } 
      sort(p.begin(),p.end());

      vector<vector<int>> ans;
      int f=p[0].first,s=p[0].second;
      for(int i=0;i<p.size()-1;i++)
      {
          vector<int> a(2);
          if(s>=p[i+1].first)
          {
              s=max(s,p[i+1].second);
          }
          else
          {
              a[0]=f;
              a[1]=s;
              f=p[i+1].first;
              s=p[i+1].second;
              ans.push_back(a);
          }
      } 
      int n=intervals.size();
      ans.push_back({f,s});
      return ans;
    }
};