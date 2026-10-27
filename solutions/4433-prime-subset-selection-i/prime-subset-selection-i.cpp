constexpr int N=1e6+1;
bitset<N> sieve=0;
vector<int> prime;
static void Sieve(){
    if (!prime.empty()) return;
    sieve[0]=sieve[1]=1;
    for (int p=2; p<=1000; p+=1+(p>2)){
        if (!sieve[p]){
            prime.push_back(p);
            for(int j=p*p; j<N; j+=p) sieve[j]=1;
        }
    }
    for(int i=1001; i<N; i+=2){
        if (!sieve[i]) prime.push_back(i);
    }
//    cout<<prime.size();
}

class Solution {
public:
    static vector<int> maxPrimes(int n, int s) {
        Sieve();
        vector<int> ans;
        ans.reserve(n/(1+log(n)));
        int sum=0;
        for(int p: prime){
            if (p>n) break;
            sum+=p;
            if (sum>s) break;
            ans.push_back(p);
        }
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();