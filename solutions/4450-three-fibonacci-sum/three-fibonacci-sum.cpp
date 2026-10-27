constexpr int N=1e9;
using ll=long long;
ll f[50]={0, 1};
unordered_set<ll> is3F;
class Solution {
public:
    static void compute_f(){
        if (f[2]!=0) return ;
        for(int x=2; x<50; x++){
            f[x]=f[x-1]+f[x-2];
            if (f[x]>=N) return ;
        }
    }
    static void compute_3F(){
        if (!is3F.empty()) return ;
        is3F.reserve(50);
        ll sum3=f[0]+f[1]+f[2];
        is3F.insert(sum3);
        for(int x=3; f[x]<=N; x++){
            sum3+=f[x]-f[x-3];
            is3F.insert(sum3);
        }
    }
    static bool threeFibonacciSum(int n) {
        compute_f();
        compute_3F();
        return is3F.count(n);
    }
};