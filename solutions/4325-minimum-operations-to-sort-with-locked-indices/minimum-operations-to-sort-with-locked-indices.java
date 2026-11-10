class Solution {
    public int minOperations(int[] nums, int[] locked, int k) {
        int count=0;
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                if(nums[i]>nums[j]){
                    count++;
                }
            }
        }
        int maxx=0 ,st=0,val=0;
        for(int i=0;i<nums.length;i++){
            maxx=Math.max(maxx,nums[i]);
            if(maxx==i+1){
                if(i>st){
                    for(int j=st;j<=i;j++){
                        if(locked[j]==1){
                            val++;
                        }
                    }
                }
                st=i+1;
            }
        }
        if(val>k) return -1;
        return count+val;
    }
}