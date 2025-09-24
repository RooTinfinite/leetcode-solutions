class Solution {
public:
    int dp[101][25];
    int fn(int ind,int num,string &s)
    {
        if(ind==s.size())
        {
             if(num%25==0)return 0;
            return 1e9;
        }
        if(dp[ind][num]!=-1)return dp[ind][num];
        
        int digit=s[ind]-'0';
        int non_pick=1+fn(ind+1,num,s);
        int pick=fn(ind+1,(num*10+digit)%25,s);
        
        return dp[ind][num]=min(pick,non_pick);
    }
    int minimumOperations(string num) {
       memset(dp,-1,sizeof(dp));
        
        return fn(0,0,num);
    }
};