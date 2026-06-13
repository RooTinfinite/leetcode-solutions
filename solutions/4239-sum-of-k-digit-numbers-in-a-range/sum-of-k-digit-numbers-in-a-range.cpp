class Solution {
    #define ll long long
    static const ll mod=1e9+7;
public:
    int sumOfNumbers(int l, int r, int k) {
        ll cnt=r-l+1;
        
        ll sum=((cnt*(l+r))/2)%mod;
        ll part1=modP(cnt,k-1);
        ll first=modP(10,k);
        
        ll env9=modP(9,mod-2);
        ll geo=((first-1+mod)%mod*env9)%mod;
        ll result=sum;
        result=(result*part1)%mod;
        result=(result*geo)%mod;
        return result;
        
    }


    ll modP(ll a,ll b){
        ll result =1;
        while(b>0){
            if(b&1) result=(result*a)%mod;
            a=(a*a)%mod;
            b>>=1;
            
        }

        return result;
    }
};