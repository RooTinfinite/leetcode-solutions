uint64_t pre[100001];
class Solution {
public:
    static int minFlips(string& s) {
        const int n=s.size();
        pre[0]=0;
        int cnt0=0, cnt1=0;
        bool flip=0;
        for (int i=0; i<n; i++, flip=!flip) { // flip 
            cnt1+=(s[i]-'0'==flip);       // accumulate prefix sum
            cnt0=(i+1)-cnt1;
            pre[i+1]=((uint64_t)cnt0<<32)+cnt1;
        }

        uint64_t ans=min((uint64_t)(pre[n] & UINT_MAX), pre[n]>>32);
        
        if ((n&1)==0) return ans;

        for (int i=1; i<n; i++) {
            // Prefix cost is swapped due to odd length shift
            const uint64_t s0=(pre[n]>>32)-(pre[i]>>32);
            const uint64_t s1=(pre[n] & UINT_MAX)-(pre[i] & UINT_MAX);
            const uint64_t p0=pre[i]>>32;
            const uint64_t p1=pre[i] & UINT_MAX;

            // New cost = (Suffix Pattern X) + (Prefix Pattern NOT X)
            ans=min(ans, min(s0+p1, s1+p0));
        }
        return ans;
    }
};