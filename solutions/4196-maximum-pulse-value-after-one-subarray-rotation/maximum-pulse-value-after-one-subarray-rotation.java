class Solution {
    public long maxValue(int[] nums) {
        int n = nums.length;
        long sum = 0;
        for(int i=0;i<n;i++){
            if(i%2==1) nums[i] = -1*nums[i];
            sum+=nums[i];
        }
        long minsum = 0L;
        long even = 0;
        long odd = nums[0];
        for(int i=1;i<n;i++){
            int val = nums[i];
            long new_even = Math.min(0,odd+val);
            long new_odd = Math.min(even+val,val);
            even = new_even;
            odd = new_odd;
            minsum = Math.min(minsum,even);
        }

        return (sum - 2*minsum);

    }
}