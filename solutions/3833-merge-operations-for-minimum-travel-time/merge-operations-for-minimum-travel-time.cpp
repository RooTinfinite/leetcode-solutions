#define ll long long
class Solution 
{
public:
    vector<vector<vector<vector<int>>>>dp;
    int sol( vector<int>& p, vector<int>& t,int i,int k,int pt,int nt)
    {
        int n=p.size();
        if(i>=n)
        {
            if(k!=0)
                return 1e8;
            else
                return 0;
        }
        if(dp[i][k][pt][nt]!=(-1))
            return dp[i][k][pt][nt];
        
        int ans=((p[i]-p[i-1])*pt)+sol(p,t,i+1,k,nt,t[i+1]);
        if(k>0 && i<(n-1))
        {
            int tans=((p[i]-p[i-1])*pt)+sol(p,t,i+1,k-1,pt,t[i+1]+nt);
            ans=min(ans,tans);
        }
        return  dp[i][k][pt][nt]=ans;
    }
    int minTravelTime(int l, int n, int k, vector<int>& p, vector<int>& t) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        dp.resize(n+1,vector<vector<vector<int>>>(k+1,vector<vector<int>>(101,vector<int>(101,-1))));
        t.push_back(t.back());
        return sol(p,t,1,k,t[0],t[1]);
    }
};