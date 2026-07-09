class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> mini(nums.size());

        int mint=INT_MAX;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<mint) mint = nums[i];
            mini[i] = mint;
        }

        int maxt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxt) maxt = nums[i];
            if(maxt-mini[i]<=k) return i;
        }
        return -1;
    }
};