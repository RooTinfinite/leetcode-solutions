class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int countSum = nums[0];
        for(int i =1; i<nums.size();i++){
            if(nums[i-1]+1 == nums[i]) countSum += nums[i];
            else break;
        }
        sort(nums.begin(),nums.end());
        for(int i = 0; i< nums.size(); i++){
            if(countSum == nums[i]){
                countSum++;
            }
        }
        return countSum;
        
    }
};