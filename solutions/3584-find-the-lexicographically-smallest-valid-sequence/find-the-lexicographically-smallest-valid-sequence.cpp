class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();

        int dp[n + 1];
        dp[n] = 0;

        int i = n - 1;
        int j = m - 1;

        while (i >= 0) {
            if (j>=0 && w1[i] == w2[j]) {
                dp[i] = dp[i + 1] + 1;
                i--;
                j--;
                
            } else {
                dp[i] = dp[i + 1];
                i--;
                
            }
        }
    
        vector<int>ans;
        vector<int>res;
        int flag = 0;
        i=0;
        j=0;

        while(i<n && j<m)
        {
           if(w1[i]!=w2[j])
           {
             if(!flag  && dp[i+1]>=m-j-1)
             {
                   flag = 1;
                   ans.push_back(i);
                   j++;
             }
           }
           else
           {
             ans.push_back(i);
             j++;
           }

           i++;
        }
       
        return j!=m ? res:ans;
    }
};