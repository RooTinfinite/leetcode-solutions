class Solution {
public:
    int monkeyMove(int n) {
        long long res=1, base=2, mod=1e9+7;
        while(n>0)
        {
            if(n%2)
            res=(res*base)%mod;
            base=base*base%mod;
            n/=2;
        }
        int k=res;
        return (k-2+mod)%mod;
    }
};