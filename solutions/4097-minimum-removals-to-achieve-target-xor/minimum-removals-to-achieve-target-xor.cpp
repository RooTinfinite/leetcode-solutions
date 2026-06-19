//translated using AI
class Solution {
public:
    unordered_map<string,int> map;

    int helper(vector<int>& nums, int target, int i, int xr){
        if(i==nums.size()){
            if(xr==target) return 0;
            else return INT_MAX;
        }

        string key = to_string(i) + "," + to_string(xr);
        if(map.find(key)!=map.end()) return map[key];

        int ans1 = helper(nums,target,i+1, xr ^ nums[i]);
        if(ans1 != INT_MAX) ans1++;

        int ans2 = helper(nums,target,i+1, xr);

        int ans = min(ans1, ans2);
        map[key] = ans;
        return ans;
    }

    int minRemovals(vector<int>& nums, int target) {
        int xr = 0;
        for(int i=0;i<nums.size();i++){
            xr ^= nums[i];
        }

        int ans = helper(nums,target,0,xr);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};