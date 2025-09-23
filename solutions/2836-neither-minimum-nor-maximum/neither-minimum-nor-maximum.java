class Solution {
    public int findNonMinOrMax(int[] nums) 
    {
        int n=nums.length;
        Arrays.sort(nums);
        if(n>2)
        {
            int mid=n/2;
            return nums[mid];
        }
        return -1;
    }
}