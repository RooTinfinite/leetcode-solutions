class Solution {
public:
    long long dp[100001];
    long long solve(int i,vector<int>&v,int n)
    {   
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        long long a=v[i]+solve(i+1,v,n);
        long long b=v[i]+solve(i+2,v,n);
        long long c=v[i]+solve(i+3,v,n);
        return dp[i]=min(a,min(b,c));
    }
    long long minIncrementOperations(vector<int>& v, int k) {
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            v[i]=max(k-v[i],0);
        }
        memset(dp,-1,sizeof(dp));
        long long ans=solve(0,v,n);
        ans=min(ans,solve(1,v,n));
        ans=min(ans,solve(2,v,n));
        return ans;
    }
};