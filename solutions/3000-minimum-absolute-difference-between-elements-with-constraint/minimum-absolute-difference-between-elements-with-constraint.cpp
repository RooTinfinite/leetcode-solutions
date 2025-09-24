class Solution {
public:
    typedef long long ll;
    int minAbsoluteDifference(vector<int>& nums, int x) {
        if(x==0) return 0;
        int n = nums.size();
        
        int ans = 1e9;
        
        set<int> s;
        for(int i=x;i<n;i++)
        {
            s.insert(nums[i-x]);
            auto ind = s.lower_bound(nums[i]);
            
            if(ind!=s.end()) ans = min(ans,abs(*ind - nums[i]));
            if(ind!=s.begin()) ind--, ans = min(ans,abs(*ind - nums[i]));
        }
        
        return ans;
    }
};