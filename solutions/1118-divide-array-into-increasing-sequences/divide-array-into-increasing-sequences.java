class Solution {
    public boolean canDivideIntoSubsequences(int[] nums, int k) {
       int i=0,j,max=0;
       while(i<nums.length){
           j=i;
           while(j<nums.length&&nums[j]==nums[i])
           ++j;
           max=Math.max(max, j-i);
           i=j;
       }
       if(nums.length/max>=k)
       return true;
       return false; 
    }
}