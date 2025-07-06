class Solution {
public:
#define deb(x) cout<<#x<<" "<<x<<"\n";
    const int mod=1e9+7;
    
    // x1+x2+... xr=n 
    long long power(long long a,long long b,int mod)
    {
        long long res=1;
        while(b>0)
        {
            if(b&1)
            {
                res*=a;
                res%=mod;
            }
            a=(a*a)%mod;
            b/=2;
        }
        return res;
    }    


    int numberOfSets(int n, int k) {
        
        // g1+x1+g2+x2+...+gk+xk+gk1=n-1 ,xi>=1
        // g1+x1+g2+x2+...+gk+xk+gk1=n-1-k ,xi>=0k,gi>=0
        // n-1-k+2k+1-1C2k = n+k-1C2k 
        int N=n+k-1,r=2*k;
        int curr=1;
        
        for(int i=1;i<=r;i++)
        {
            curr=(1LL*curr*(N-i+1))%mod;
            curr=(1LL*curr*power(i,mod-2,mod))%mod;
        }

        return curr;
    }
};