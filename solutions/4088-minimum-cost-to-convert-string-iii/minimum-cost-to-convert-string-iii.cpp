#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,a,n) for(ll i=a;i<n;i++)
#define g(i,a,n) for(ll i=a;i>=n;i--)
#define vll vector<ll>

class Solution
{
public:
    int minCost(string src, string tar, vector<vector<string>>& tu, vector<int>& costs)
    {
        ll n=src.length(),m=tu.size();
        vll rc(m,0);
        f(i,0,m)
        {
            ll w=0;
            f(j,0,tu[i][0].length())if(tu[i][0][j]=='*')w++;
            rc[i]=costs[i]+w;
        }
        const ll maxi=1e18;
        vll dp(n+1,maxi);
        dp[n]=0;
        g(i,n-1,0)
        {
            if(src[i]==tar[i])dp[i]=dp[i+1];
            f(j,0,m)
            {
                ll t=tu[j][0].length();
                if(i+t<=n)
                {
                    bool ok=1;
                    f(k,0,t)
                    {
                        if((tar[i+k]!=tu[j][1][k]) or (tu[j][0][k]!='*' and tu[j][0][k]!=src[i+k]))
                        {
                            ok=0;
                            break;
                        }
                    }
                    if(ok and dp[i+t]!=maxi)dp[i]=min(dp[i],rc[j]+dp[i+t]);
                }
            }
        }
        return dp[0]==maxi?-1:dp[0];
    }
};