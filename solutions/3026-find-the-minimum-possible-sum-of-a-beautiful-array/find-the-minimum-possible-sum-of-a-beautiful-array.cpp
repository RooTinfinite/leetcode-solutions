class Solution {
public:
    const int MOD=1e9+7;
    long long minimumPossibleSum(int n, int target) {
        long long mid=target>>1;// take the mid

        if(n<=mid)return n*1ll*(n+1)/2 % MOD;// early return

        // take first half
        long long ans=mid*(mid+1)/2;
        ans%=MOD;
        // pick rem numbers optimally
        long long rem=n-mid;
        // As per explained expression
        ans+=target*rem+(rem*1ll*(rem-1)/2);
        ans%=MOD;
        return ans;
    }
};