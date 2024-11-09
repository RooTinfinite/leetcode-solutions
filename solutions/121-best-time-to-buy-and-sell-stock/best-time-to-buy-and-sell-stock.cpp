class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int minPro=INT_MAX, maxPro=0;
        for(int i=0;i<nums.size();i++) {
            minPro = min(nums[i],minPro);
            maxPro = max(maxPro, (nums[i]-minPro));
        }
        return maxPro;
    }
};