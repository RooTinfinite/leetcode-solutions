class Solution {
    public long[] findPrefixScore(int[] nums) {
        int n=nums.length;
        long ans[]=new long[n];
        int min=0;
        for(int i=0;i<n;i++)
        {
            if(min<=nums[i])
            {
                min=nums[i];
            }
            ans[i]+=min+nums[i];
        }
        for(int i=1;i<n;i++)
        {
            ans[i]+=ans[i-1];
        }
        return ans;
    }
}