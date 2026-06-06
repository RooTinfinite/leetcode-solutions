class Solution {
    public int dominantIndices(int[] nums) {
        int n=nums.length;
        int runningavg[]=new int[n];
        runningavg[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            runningavg[i]=runningavg[i+1]+nums[i];
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            double avg=(double)(runningavg[i+1]/(n-i-1));
            if(nums[i]>avg){
                count++;
            }
        }
        return count;
        
    }
}