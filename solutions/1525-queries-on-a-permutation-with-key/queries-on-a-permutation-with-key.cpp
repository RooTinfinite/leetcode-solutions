class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
      vector<int> P(m), res(queries.size());
      int size = m;
      for(int i = 0; i < m; i++)
          P[i] = m - i; 
      for(int i = 0; i < queries.size(); i++) {
          int curQuery = queries[i];
          
          auto it = find(P.begin(), P.end(), curQuery);
          int curIndex = it - P.begin(); 
          int index = size - 1 - curIndex; 
          queries[i] = index;
          P.erase(P.begin() + curIndex);
          P.push_back(curQuery);
      }  
        
      return queries;
    }
};