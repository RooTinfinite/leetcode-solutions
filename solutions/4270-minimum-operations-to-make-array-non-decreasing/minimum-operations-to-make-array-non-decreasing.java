class Solution {
    public long minOperations(int[] nums) {
        long res=0;
        for (int i=nums.length-2;i>=0;i--) {
            if (nums[i]>nums[i+1]){
                res+=nums[i]-nums[i+1];
            }
        }
        return res;
    }
}