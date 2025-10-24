class Solution {
public:
    long long splitArray(vector<int>& nums) {
        if(nums.size() == 2)
            return abs(nums[0]-nums[1]);
        
        long long leftSum = nums[0];
        long long rightSum = nums[nums.size()-1];
        int left = 0;
        int right = nums.size()-1;
        
        while(left+1 < nums.size() && nums[left] < nums[left+1])
            {
                leftSum += nums[left+1];
                left++;
            }

        while(right-1 >= 0 && nums[right-1] > nums[right])
            {
                rightSum += nums[right-1];
                right--;
            }

        if(left != right && abs(left-right) == 1)
            return abs(leftSum-rightSum);
        else if(left != right)
            return -1;

        return min(abs((leftSum-nums[left])-rightSum), abs(leftSum-(rightSum-nums[left])));
    }
};