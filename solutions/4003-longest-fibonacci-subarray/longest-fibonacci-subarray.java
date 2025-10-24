class Solution {
    public int longestSubarray(int[] nums) {
        int sub=1;
        int prev=nums[0];
        int max=-1;
        for(int i=1;i<nums.length-1;i++){
            int curr=nums[i];
            if((prev+curr)==nums[i+1]){
                sub++;
                prev=curr;
                max=Math.max(max,sub);
            }
            else{
                sub=1;
                prev=curr;
            }
        }
        return (max==-1)?2:max+1;
    }
}