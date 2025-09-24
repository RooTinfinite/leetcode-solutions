class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int c=0;

        for(int r=0;r<nums.size()-1;r++){
            for(int p=r+1;p<nums.size();p++){
                if(nums[r]+nums[p] < target ) c++;
            }
        }

        return c;
    }
};