class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long runningSum = 0;
        int count=0;
        for(int i=nums.size()-1;i>=0;i--){
            runningSum+=(long)nums[i];
            if(runningSum<=0) break;
            count++;
        }
        return count;
    }
};