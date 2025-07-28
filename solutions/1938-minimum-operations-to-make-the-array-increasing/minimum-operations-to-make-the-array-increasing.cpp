class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations=0;  //cant keep 1 and do operations++ as for single ele array its inv
        for(size_t i {1};i<nums.size();i++) //keep i=1 not 0 as if condition uses prev ele
        {
            if(nums[i-1]<nums[i])
                continue;
            else
            {
                //first calculate difference between previous and current term
                int diff=nums[i-1]-nums[i];
                diff++;
                
                //now add difference to the current element that is smaller than prev ele
                nums[i]=nums[i]+diff;
                
                //increment count of operations by adding difference
                operations+=diff;
            }
        }
        return operations;
        
    }
};