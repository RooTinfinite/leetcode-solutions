class Solution {
    public void operation(int[] nums,int n){
        int min_index=0;
        int minsum=nums[0]+nums[1];
        for(int i=0;i<n-1;i++){
            if(nums[i]+nums[i+1]<minsum){
                min_index=i;
                minsum=nums[i]+nums[i+1];
            }
        }
        nums[min_index]=minsum;
        for(int i=min_index+1; i<n-1;i++){
            nums[i]=nums[i+1];
        }
        
    }
    public int minimumPairRemoval(int[] nums) {
        int n=nums.length;
        int[] pairsum=new int[n-1];
        int count=0;
        for(int i=0; i<n-1;i++){
            if(nums[i]>nums[i+1]){
                count++;
                operation(nums,n);
                i=-1;
                n--;
            }
        }
        return count;
    }
}