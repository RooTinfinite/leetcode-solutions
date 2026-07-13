class Solution {
public:
    typedef unsigned long long ull;
    vector<ull>pfx,power;
    void buildhash(vector<int>&nums){
        int n=nums.size();
        ull base=200000ULL;
        pfx.resize(n+1,0);
        power.resize(n+1,1);
        for(int i=0;i<n;i++){
            pfx[i+1]=pfx[i]*base+(nums[i]+1);
            power[i+1]=power[i]*base;
        }
    }
   
    
    ull encode(int l,int r){
        int len=r-l+1;
        return pfx[r+1]-pfx[l]*power[len];
    }
    bool check(int mid,vector<int>&nums){
        unordered_map<ull,int>mp;
        for(int i=0;i+mid<=nums.size();i++){
            ull temp=encode(i,i+mid-1);
            mp[temp]++;
        }
        for(auto&it:mp)if(it.second==1)return true;
        return false;
    }
    
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int lo=1,hi=nums.size()-1;
        int ans=n;
        buildhash(nums);
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,nums)){
                ans=mid;
                hi=mid-1;
            }else lo=mid+1;
        }
        return ans;
    }
};