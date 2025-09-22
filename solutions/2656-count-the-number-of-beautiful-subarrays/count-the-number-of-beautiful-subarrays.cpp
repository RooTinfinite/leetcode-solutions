#define ll long long int

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> prefXor(n+1, 0);
        
        for(int i=0;i<n;i++){
            prefXor[i+1] = prefXor[i] ^ nums[i];
        }
        
        unordered_map<int, int> mp;
        mp[0] = 1;
        ll ans = 0;
        for(int i=1;i<=n;i++){
            if(mp[prefXor[i]]) ans += mp[prefXor[i]];
            mp[prefXor[i]]++;
        }
        
        return ans;
    }
};