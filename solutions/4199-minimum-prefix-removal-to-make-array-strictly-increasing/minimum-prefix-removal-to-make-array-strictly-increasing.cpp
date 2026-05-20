class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int i = nums.size()-1;
        while(i>0){
            if(nums[i-1] < nums[i]) i--;
            else break;
        }
        return i;
    }
};