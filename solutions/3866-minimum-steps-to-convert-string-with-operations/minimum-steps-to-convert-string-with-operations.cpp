class Solution {
public:
//foxed
    vector<int> dp;
    
    int compute(string a, string b)
    {
       int count=0;

       for(int i=0; i<a.size(); i++)
       {
          if(a[i]==b[i])continue;
          bool flag=true;

          for(int j=i+1; j<a.size(); j++)
          {
             if(b[i]==a[j] && b[j]==a[i] && a[j]!=b[j])
             {
                swap(a[i], a[j]);
                count++;
                flag=false;
                break;
             }
          }
          if(flag){
            count++;
          }
       }
      
       return count;
    }

    int solve(int index, string &a, string &b)
    {
        if(index==a.size())return 0;
        if(dp[index]!=-1)return dp[index];
        
        int mini=1e9;

        for(int i=index; i<a.size(); i++)
        {
          string s1= a.substr(index, i-index+1);
          string s2= b.substr(index, i-index+1);

          mini= min(mini, compute(s1, s2) + solve(i+1, a, b));
          reverse(s1.begin(), s1.end());
          mini= min(mini, 1+compute(s1, s2)+ solve(i+1, a, b));
        }
        return dp[index]=mini;
    }
    int minOperations(string word1, string word2) {
        
        int n= word1.size();

        dp.resize(n,-1);

        return solve(0, word1, word2);
    }
};