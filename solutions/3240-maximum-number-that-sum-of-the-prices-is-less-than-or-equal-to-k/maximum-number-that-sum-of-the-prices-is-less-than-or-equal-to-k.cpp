typedef long long int ll;

bool IsSet (int bit, ll x) {
    return ((x & (1LL << bit)) > 0);
}

vector<ll> SetBitsCount (ll x) {
    int highest_bit = 63;
    while (highest_bit >= 0 && !IsSet(highest_bit, x)) highest_bit --;
    
    vector<ll> cnt(64, 0);
    
    for (int i = highest_bit; i >= 0;) {
        x -= (1LL << i);
        cnt[i] += x+1;
        
        for (int j = i-1; j >= 0; j --)
            cnt[j] += (1LL << i)/2;
        
        i --;
        while (i >= 0 && !IsSet(i, x)) i--;
    }
    
    return cnt;
}

ll SumOfPrices (ll n, int x) {
    vector<ll> cnt_bits = SetBitsCount (n);
    
    ll result = 0;
    for (int i = 63; i >= 0; i --)
        if ((i+1) % x == 0) result += cnt_bits[i];
    
    return result;
}

class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        ll l = 1, r = 1e15*64;
        
        while (l < r) {
            ll m = (l+r) >> 1;
            
            if (SumOfPrices(m+1, x) <= k) l = m+1;
            else r = m;
        }
        return l;
    }
};