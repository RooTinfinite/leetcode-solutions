class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int minAnd = 1;
        int zeros = 0;
        for(int i = 0;i < nums.size(); ++i){
            minAnd = (minAnd & nums[i]);
            zeros += (nums[i] == 0);
        }
        int ans = 0;
        int andd = INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            andd = andd & nums[i];
            if(andd == minAnd){
                ans++;
                andd = INT_MAX;
            }
        }
        return zeros == nums.size()? nums.size():minAnd>0?1:max(ans,1);
    }
};