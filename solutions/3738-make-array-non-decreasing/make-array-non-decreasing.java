class Solution {
    public int maximumPossibleSize(int[] nums) {

        int maxsofar=nums[0];
        int cnt=1;

        for(int i=1;i<nums.length;i++)
        {
            if(nums[i] >= maxsofar)
            {
                maxsofar=nums[i];
                cnt++;
            }
        }
        return cnt;
    }
}