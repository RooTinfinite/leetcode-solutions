class Solution {
public:
    using ll=long long;
    ll n,mod=1e9+7;
    ll can(vector<int>& value, vector<int>& decay, ll md){
        ll res=0;
        for(int i=0;i<n;++i){
            if(value[i]<md)
                continue;
            res+=(value[i]-md)/decay[i]+1;
            if(res>(ll)1e9)
                return res;
        }
        return res;
    }
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        n=value.size();
        ll l=0,r=1e18;
        while(l<r){
            ll md=(l+r+1)/2;
            if(can(value,decay,md)>=m)
                l=md;
            else
                r=md-1;
        }
        ll res=0,take=0;
        for(int i=0;i<n;++i){
            if(value[i]<l)
                continue;
            ll t=(value[i]-l)/decay[i]+1; // t = count
            ll s=t*value[i]-decay[i]*t*(t-1)/2;// take 0....t - 1 = t * (t - 1) / 2
            res=(res+s)%mod;
            take+=t;
        }
        res=(res-(take-m)%mod*(l%mod))%mod;
        res=(res+mod)%mod;
        return res;
    }
};