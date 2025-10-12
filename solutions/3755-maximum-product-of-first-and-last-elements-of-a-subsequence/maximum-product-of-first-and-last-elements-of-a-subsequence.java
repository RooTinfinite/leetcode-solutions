class Solution {
    public long maximumProduct(int[] nums, int m) {
        int n = nums.length;
        int[] max = new int[n];
        int[] min = new int[n];
        max[n-1]=min[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            max[i] = Math.max(max[i+1],nums[i]);
            min[i] = Math.min(min[i+1],nums[i]);
        }

        long ans = Long.MIN_VALUE;

        for(int i=0;i<n;i++){
            int j = i+m-1;
            if(j>=n) break;
            long product = 1L*nums[i]*(nums[i]>=0?max[j]:min[j]);
            ans = Math.max(ans,product);
        }

        return ans;
    }
}