class Solution {
public:
    const int mod = 1e9 + 7;

    long long find(long long base,long long exp){
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp /= 2;
    }
    return res % mod;
    }
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int,int>> a;
        long long n = nums1.size(),ans = 0;
        int last = 0;
        for(int i = 0; i<n; i++){
            if(nums0[i] == 0){
               last += nums1[i];
            } else{
                a.push_back({nums1[i],nums0[i]});
            }
        }
        sort(a.begin(),a.end(),[](auto &a1, auto&a2){
            if(a1.first == a2.first) return a1.second < a2.second;
            return a1.first > a2.first;
        });


        long long exp = 0;


        for(int i = a.size()-1; i>=0; i--){
            auto [one,zero] = a[i];
            exp += zero;
            long long first = find(2,exp);

            long long rn  = find(2,one);

            long long val = (first * (rn - 1 + mod) % mod) % mod;
             ans = (ans + val) % mod;

            exp += one;
        }

            long long first = find(2,exp);

            long long rn  = find(2,last);

            long long val = (first * (rn - 1 + mod) % mod) % mod;
             ans = (ans + val) % mod;

        // cout<<ans<<endl;

        return ans;
        
    }
};