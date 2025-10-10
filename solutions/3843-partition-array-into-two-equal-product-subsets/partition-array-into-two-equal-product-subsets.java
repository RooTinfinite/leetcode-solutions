class Solution {
    public boolean checkEqualPartitions(int[] nums, long target) {
        long p = 1;
        for(int i = 0;i<nums.length;i++){
            p = p*nums[i];
        }
       if(p != target*target){
        return false;
       }
       return helpr(target,nums.length,nums,1);
    }
    public boolean helpr(long target,int n,int[]nums,long prd){
    if(prd > target){
        return false;
    }
    if(target == prd){
        return true;
    }
    if(n == 0){
    return prd == target;
    }
    if(helpr(target,n-1,nums,prd*nums[n-1])){
        return true;
    }
    return helpr(target,n-1,nums,prd);
    }
}