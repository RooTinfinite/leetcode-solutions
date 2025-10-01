class Solution {
    public long maximumTotalSum(int[] nums) {
        Arrays.sort(nums);
        long ans=nums[nums.length-1];
        for(int i=nums.length-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
                nums[i]=nums[i+1]-1;
                ans+=nums[i];
                if(nums[i]<=0){
                    return -1;
                }
            }
            else{
                ans+=nums[i];
            }
        }
        return ans;
    }
}